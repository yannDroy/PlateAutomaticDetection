/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for model_process.c file ***/

#ifndef __MODEL_PROCESS__
#define __MODEL_PROCESS__

#include "struct.h"

#define BACKGROUND  1
#define CONVERGENT -1
#define DIVERGENT   2

/*
 * Main function of the file.
 * Creates a model from a data file and computes the plates limits
 * and plate poles.
 * PARAMETERS:
 * filename: the input data file name
 * begin: the beginning cutoff for plate limits
 * begin: the ending cutoff for plate limits
 * step: the cutoff step
 * RETURN VALUE:
 * the computation time
 */
double pad(char *filename, const int begin, const int end, const int n);

/*
 * Computes the plate limits over the model.
 * It computes the velocities differences of close points.
 * There is a cutoff for velocities differences. If the
 * difference is under the cutoff, velocities are considered the
 * same so the points can potentially be on the same plate.
 * It then outputs the result in a file. The output file can be
 * read by GMT to have a visualization of the found plates.
 * PARAMETERS:
 * filenamem: the input filename (used for output)
 * m: the model
 * cutoff: the cutoff
 */
void compute_plate_limits(char *filename, model m, const double cutoff);

/*
 * Computes the velocity differences for close points.
 * PARAMETERS:
 * m: the model
 * cutoff: the cutoff
 */
void velocity_diff(const model m, int **matrix, const double cutoff);

#endif
