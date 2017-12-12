/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** pad.c file ***/
/*** Contains the main Plate Automatic Detection program ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/model_process.h"

#define MIN   1
#define MAX 100

#define MAX_LENGTH 100

#define DEFAULT_BEGIN 10
#define DEFAULT_END   40
#define DEFAULT_NUMBER 4

int threads;
int mode;

void usage(char *s){
    fprintf(stderr, "Usage: %s ", s);
    fprintf(stderr, "<parallel> <schedule> <filename> <threads> ");
    fprintf(stderr, "[<begin_cutoff> <end_cutoff> <computations>]\n\n");
    
    fprintf(stderr, "Where:\n");
    fprintf(stderr, " - <parallel> is : \n");
    fprintf(stderr, "     -c for cutoff parallelization\n");
    fprintf(stderr, "     -m for matrix parallelization\n");
    fprintf(stderr, " - <schedule> is the OpenMP schedule for loops\n");
    fprintf(stderr, " - <filename> is the input model file\n");
    fprintf(stderr, " - <threads> the number of desired threads (integer)\n");
    fprintf(stderr, " - <begin_cutoff> the low-bound cutoff (integer)\n");
    fprintf(stderr, "   Must be between %d and %d\n", MIN, MAX);
    fprintf(stderr, " - <end_cutoff> the high-bound cutoff (integer)\n");
    fprintf(stderr, "   Must be between %d and %d ", MIN, MAX);
    fprintf(stderr, "and greater than <begin_cutoff>\n");
    fprintf(stderr, " - <computations> the number of computations (integer)\n");
    fprintf(stderr, "   Must be positive\n");
        
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[], char *envp[]) {
    char schedule[MAX_LENGTH];
    double compute_time;
    int begin, end, number;

    // Parameters testing and setting
    if(argc != 5 && argc != 8)
        usage(argv[0]);

    if(argc == 8){
        begin = atoi(argv[5]);
        end = atoi(argv[6]);
        number = atoi(argv[7]);
    }else{
        begin = DEFAULT_BEGIN;
        end = DEFAULT_END;
        number = DEFAULT_NUMBER;
    }

    if(begin < MIN || begin > MAX ||
       end < MIN || end > MAX ||
       number < 1 || end < begin)
        usage(argv[0]);

    threads = atoi(argv[4]);

    if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "-C"))
        mode = 0;
    else if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "-M"))
        mode = 1;
    else
        usage(argv[0]);

    // OpenMP scheduling
    sprintf(schedule, "OMP_SCHEDULE=%s", argv[2]);
    putenv(schedule);

    // PAD
    compute_time = pad(argv[3], begin, end, number);
    
    /*fprintf(stderr, "**************************\n");
    fprintf(stderr, "* Compute time: %8f *\n", compute_time);
    fprintf(stderr, "**************************\n");*/
    fprintf(stderr, "%f\n", compute_time);
    
    return EXIT_SUCCESS;
} /* main() */
