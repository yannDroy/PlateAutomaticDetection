/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** die.c file ***/
/*** Contains functions which exit the program in case of error ***/

#include <stdio.h>
#include <stdlib.h>

#include "include/die.h"

void die(const char *function_name, const char *error_message){
    perror(error_message);
    fprintf(stderr, "in %s() function\n", function_name);
    exit(EXIT_FAILURE);
} /* die() */

void null_model(const char *function_name){
    fprintf(stderr, "Null model in %s()\n", function_name);
    exit(EXIT_FAILURE);
} /* null_model() */

void alloc_fail(const char *function_name, const char *variable_name){
    fprintf(stderr, "%s allocation failure in %s()\n",
            variable_name, function_name);
    exit(EXIT_FAILURE);
} /* null_model() */

void points_null(const char *function_name){
    fprintf(stderr, "The model matrix or the model points list is NULL ");
    fprintf(stderr, " in %s()\n", function_name);
    exit(EXIT_FAILURE);
} /* points_or_matrix_null */
