/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** model_create.c file ***/
/*** Contains all the creation functions for models ***/

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

#include "include/struct.h"
#include "include/load_data.h"
#include "include/model_create.h"
#include "include/debug.h"
#include "include/out.h"

model create_model(const char *filename){
    model new = {.n = -1,
                 .n_lat = -1,
                 .n_long = -1,
                 .points = NULL};

    new = load_data(filename);
    compute_n_lat(&new);
    compute_n_long(&new);

#if DEBUG
    print_model(new);
#endif

    return new;
} /* create_model() */

void destroy_model(model m){
    int i;

    check_model(m, "desroy_model");

    free(m.points);
} /* destroy_model() */

int **create_model_matrix(model *m){
    int **t = NULL;
    int i;
    
    if(m == NULL)
        null_model("create_matrix_model");

    if(m->n_lat < 0 || m->n_long < 0){
        fprintf(stderr, "Impossible to compute the number of longitudes");
        fprintf(stderr, " without the number of latitudes.\n");
    }else{
        t = (int**) malloc(m->n_long * sizeof(int*));

        if(t == NULL)
            alloc_fail("create_matrix_model", "t");

        for(i = 0; i < m->n_long; i++){
            t[i] = (int*) calloc(m->n_lat, sizeof(int));
            if(t[i] == NULL)
                alloc_fail("create_matrix_model", "t[i]");
        }
    }

    return t;
} /* create_model_matrix() */

void compute_n_lat(model *m){
    long double northern_lat;
    int n = 0;

    if(m == NULL)
        null_model("compute_n_lat");

    northern_lat = m->points[0].p.latitude;

    while(m->points[n].p.latitude == northern_lat)
        n++;

    m->n_lat = n;
} /* compute_n_lat() */

void compute_n_long(model *m){
    if(m == NULL)
        null_model("compute_n_long");
        
    if(m->n_lat < 0){
        fprintf(stderr, "Impossible to compute the number of longitudes");
        fprintf(stderr, " without the number of latitudes.\n");
    }else{
        m->n_long = m->n / m->n_lat;
    }
} /* compute_n_long() */

void check_model(const model m, const char *function_name){
    if(m.points == NULL)
        points_null(function_name);
} /* check_model() */

void free_matrix(const model m, int **matrix){
    int i;
    
    for(i = 0; i < m.n_long; i++)
        free(matrix[i]);
    
    free(matrix);
} /* free_matrix() */
