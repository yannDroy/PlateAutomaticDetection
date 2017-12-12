/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for debug.c file ***/

#ifndef __DEBUG__
#define __DEBUG__

#include "struct.h"

#define DEBUG 0

/*
 * Prints a model.
 * PARAMETERS:
 * model: the model to print
 */
void print_model(const model m);

/*
 * Prints a model matrix.
 * PARAMETERS:
 * m: the matrix to print
 * lines: the number of lines in the matrix
 * columns: the number of columns in the matrix
 */
void print_model_matrix(int **m, int lines, int columns);

#endif
