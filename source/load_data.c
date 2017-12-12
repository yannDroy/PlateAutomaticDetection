/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** load_data.c file ***/
/*** Contains functions for loading data from files ***/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "include/struct.h"
#include "include/load_data.h"
#include "include/die.h"
#include "include/debug.h"

int line_number(const char *filename){
    FILE *pipe = NULL;
    char command[COMMAND_MAX_SIZE];
    char output[OUTPUT_COMMAND_MAX_SIZE];
    int lines = 0;

    // Creating the command
    sprintf(command, "wc -l %s", filename);

    // Setup the pipe to execute the created command
    pipe = popen(command, "r"); 

    if(pipe == NULL)
        die("line_number", "Pipe opening for 'wc -l' command failure");

    // Geting the data from the command
    fgets(output, OUTPUT_COMMAND_MAX_SIZE, pipe);
    // Getting the integer number of lines
    sscanf(output, "%d", &lines);

    if(pclose(pipe) < 0)
        die("line_number", "Pipe closing for 'wc -l' command failure");
    
    return lines;
} /* line_number() */

model load_data(const char *filename){
    FILE *file = NULL;
    model new;
    int i;

    // Getting the number of points
    new.n = line_number(filename);

#if DEBUG
    fprintf(stdout, "DEBUG: %d lines in the input file '%s'\n",
            new.n, filename);
#endif

    // Points list allocation
    new.points = (point_velocity*) malloc(new.n * sizeof(point_velocity));
    if(new.points == NULL)
        alloc_fail("load_data", "new.points");

    file = fopen(filename, "r");

    if(file == NULL)
        die("load_data", ERROR_FILE_OPENING);

    // Model filling
    for(i = 0; i < new.n; i++){
        fscanf(file, "%Lf", &new.points[i].p.latitude);
        fscanf(file, "%Lf", &new.points[i].p.longitude);
        fscanf(file, "%Lf", &new.points[i].v.v_north);
        fscanf(file, "%Lf", &new.points[i].v.v_east);
    }

    if(fclose(file) < 0)
        die("load_data", ERROR_FILE_CLOSING);

    return new;
} /* load_data() */
