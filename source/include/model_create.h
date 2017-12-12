/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for model_create.c file ***/

#ifndef __MODEL_CREATE__
#define __MODEL_CREATE__

#include "struct.h"

/*
 * Creates a model from a data file.
 * PARAMETERS:
 * filename: the data file containing the model
 * RETURN VALUE:
 * the created model
 */
model create_model(const char *filename);

/*
 * Destroys a model by freeing the allocated memory.
 * PARAMETERS:
 * filename: the model to destroy
 */
void destroy_model(model m);

/*
 * Creates an empty matrix for a model.
 * PARAMETERS:
 * m: the model
 * RETURN VALUE:
 * the created matrix
 */
int **create_model_matrix(model *m);

/*
 * Computes the number of points on the same latitude.
 * It just counts the number of points on the first latitude.
 * PARAMETERS:
 * m: the model pointer
 */
void compute_n_lat(model *m);

/*
 * Computes the number of points on the same longitude.
 * PARAMETERS:
 * m: the model the pointer
 */
void compute_n_long(model *m);

/*
 * Checks if the points list or the matrix of the model are NULL.
 * PARAMETERS:
 * m: the model
 * function_name: the function in which we are testing
 */
void check_model(const model m, const char *function_name);

/*
 * Frees a model matrix.
 * PARAMETERS:
 * m: the model on which is based the matrix
 * matrix: the matrix to free
 */
void free_matrix(const model m, int **matrix);

#endif
