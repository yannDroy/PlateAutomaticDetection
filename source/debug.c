/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** debug.c file ***/
/*** Contains printing debugging functions ***/

#include <stdio.h>

#include "include/struct.h"
#include "include/debug.h"

void print_model(const model m){
    int i;
    
    fprintf(stdout, "DEBUG: Model:\n");

    fprintf(stdout, " %d points\n", m.n);
    fprintf(stdout, " n_lat: %d\n", m.n_lat);
    fprintf(stdout, " n_long: %d\n", m.n_long);
    fprintf(stdout, " points:\n");
    
    for(i = 0; i < m.n; i++)
        fprintf(stdout, "  %d: %Lf %Lf %Lf %Lf\n", i,
               m.points[i].p.latitude, m.points[i].p.longitude,
               m.points[i].v.v_north, m.points[i].v.v_east);
} /* print_model() */

void print_model_matrix(int **m, int lines, int columns){
    int i, j;

    fprintf(stdout, "DEBUG: Matrix model:\n");
    for(i = 0; i < lines; i++){
        fprintf(stdout, " ");
        for(j = 0; j < columns; j++){
            if(m[i][j])
                fprintf(stdout, "x");
            else
                fprintf(stdout, ".");
        }
        fprintf(stdout, "\n");
    }
} /* print_model_matrix() */
