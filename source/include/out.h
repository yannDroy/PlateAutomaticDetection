/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for out.c file ***/

#ifndef __OUT__
#define __OUT__

#include "struct.h"

#define OUTNAME_MAX_LENGTH 256

/*
 * Writes the matrix representation of the model in an output file.
 * PARAMETERS:
 * filename: the output file to write to
 * m: the model on which is based the matrix
 * matrix: the matrix to output
 */
void write_matrix(const char *filename, const model m, int **matrix);

#endif
