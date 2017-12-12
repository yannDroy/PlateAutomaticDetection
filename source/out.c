/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** die.c file ***/
/*** Contains functions write output files ***/

#include <stdio.h>
#include <stdlib.h>

#include "include/struct.h"
#include "include/out.h"
#include "include/model_process.h"
#include "include/die.h"

void write_matrix(const char *filename, const model m, int **matrix){
    FILE *file = NULL;
    int i, j;
    int current;

    check_model(m, "write_matrix");

    file = fopen(filename, "w");

    if(file == NULL)
        die("write_matrix", ERROR_FILE_OPENING);

    for(i = 0; i < m.n_long; i++){
        for(j = 0; j < m.n_lat; j++){
            current = i * m.n_lat + j;
            
            fprintf(file, "%Lf ", m.points[current].p.longitude);
            fprintf(file, "%Lf ", m.points[current].p.latitude);
            fprintf(file, "%d\n", matrix[i][j]);
        }
    }

    if(fclose(file) < 0)
        die("write_matrix", ERROR_FILE_CLOSING);
} /* write_matrix() */
