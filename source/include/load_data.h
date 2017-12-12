/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for load_data.c file ***/

#ifndef __LOAD_DATA__
#define __LOAD_DATA__

#include "struct.h"

#define COMMAND_MAX_SIZE 100
#define OUTPUT_COMMAND_MAX_SIZE 150

/*
 * Counts the number of lines in a file.
 * It uses a pipe running 'wc -l' command.
 * PARAMETERS:
 * filename: the concerned file
 * RETURN VALUE:
 * the number of lines
 */
int line_number(const char *filename);

/*
 * Loads model data for points velocities from its file.
 * PARAMETERS:
 * filename: the concerned data model file
 * RETURN VALUE:
 * the filled model
 */
model load_data(const char *filename);

#endif
