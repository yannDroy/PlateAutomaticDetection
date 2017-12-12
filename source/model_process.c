/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** model_process.c file ***/
/*** Contains the processing functions for plates limits ***/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <libgen.h>
#include <omp.h>

#include "include/struct.h"
#include "include/model_process.h"
#include "include/model_create.h"
#include "include/debug.h"
#include "include/out.h"

extern int threads;
extern int mode;

double pad(char *filename, const int begin, const int end, const int n){
    double start_time, end_time;
    double step = 0;
    model m;
    int i;

    // Model creation
    m = create_model(filename);

    // Start time
    start_time = omp_get_wtime();

    if(n > 1)
        step = (end - begin) / ((double) (n - 1));

    // Parallelization mode (cutoff vs. matrix)
    if(!mode){
#pragma omp parallel for num_threads(threads) schedule(runtime)
        for(i = 0; i < n; i++)
            compute_plate_limits(filename, m, ((double) begin) + i * step);
    }else{
        for(i = 0; i < n; i++)
            compute_plate_limits(filename, m, ((double) begin) + i * step);
    }

    // End time
    end_time = omp_get_wtime() - start_time;

    // Model destroying
    destroy_model(m);

    return end_time;
} /* pad() */

void compute_plate_limits(char *filename, model m, const double cutoff){
    char outname[OUTNAME_MAX_LENGTH];
    int **matrix = NULL;

    // New matrix creation
    matrix = create_model_matrix(&m);

    // Velocities differences computing for plate limits
    velocity_diff(m, matrix, cutoff / 10000.0);
    
#if DEBUG
    print_model_matrix(matrix, m.n_long, m.n_lat);
#endif

    // Output writing
    sprintf(outname, "visualization/in/%s_%f.out",
            basename(filename), cutoff);
        
    write_matrix(outname, m, matrix);

    free_matrix(m, matrix);
} /* compute_plate_limits() */

void velocity_diff(const model m, int **matrix, const double cutoff){
    int i, j;
    int current, next_east, next_south;
    double diff;

    // Parallelization mode (cutoff vs. matrix)
    if(!mode){
        // For all the points
        for(i = 0; i < m.n_long; i++){
            for(j = 0; j < m.n_lat; j++){
                // Converting (i,j) to index in points list
                // 3 points: current one, the next to the East
                // and the next to the South
                current = i * m.n_lat + j;   
                next_east = i * m.n_lat + ((j + 1) % m.n_lat);
                next_south = (i + 1) * m.n_lat + j;

                // First we compute for East
                diff = m.points[current].v.v_east
                    - m.points[next_east].v.v_east;

                if(diff > 0 && diff > cutoff)
                    matrix[i][j] = CONVERGENT;
                else if(diff < 0 && fabs(diff) > cutoff)
                    matrix[i][j] = DIVERGENT;

                // If the point is not a limit, we then check for South
                if(matrix[i][j] == BACKGROUND){
                    // If we are not on the last parallel
                    if(i + 1 < m.n_long){
                        diff = m.points[current].v.v_north
                            - m.points[next_south].v.v_north;

                        if(diff > 0 && diff > cutoff)
                            matrix[i][j] = DIVERGENT;
                        else if(diff < 0 && fabs(diff) > cutoff)
                            matrix[i][j] = CONVERGENT;
                    }
                }
            }
        }
    }else{
        // For all the points
#pragma omp parallel for num_threads(threads) schedule(runtime) \
    private(j, current, next_east, next_south, diff)            \
    shared(matrix)
        for(i = 0; i < m.n_long; i++){
            for(j = 0; j < m.n_lat; j++){
                // Converting (i,j) to index in points list
                // 3 points: current one, the next to the East
                // and the next to the South
                current = i * m.n_lat + j;   
                next_east = i * m.n_lat + ((j + 1) % m.n_lat);
                next_south = (i + 1) * m.n_lat + j;

                // First we compute for East
                diff = m.points[current].v.v_east
                    - m.points[next_east].v.v_east;

                if(diff > 0 && diff > cutoff)
                    matrix[i][j] = CONVERGENT;
                else if(diff < 0 && fabs(diff) > cutoff)
                    matrix[i][j] = DIVERGENT;

                // If the point is not a limit, we then check for South
                if(matrix[i][j] == BACKGROUND){
                    // If we are not on the last parallel
                    if(i + 1 < m.n_long){
                        diff = m.points[current].v.v_north
                            - m.points[next_south].v.v_north;

                        if(diff > 0 && diff > cutoff)
                            matrix[i][j] = DIVERGENT;
                        else if(diff < 0 && fabs(diff) > cutoff)
                            matrix[i][j] = CONVERGENT;
                    }
                }
            }
        }
    }
} /* velocity_diff() */
