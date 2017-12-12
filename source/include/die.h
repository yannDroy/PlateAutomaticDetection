/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for die.c file ***/

#ifndef __DIE__
#define __DIE__

/* Already defined error messages */
#define ERROR_FILE_OPENING "File opening failure"
#define ERROR_FILE_CLOSING "File closing failure"

/*
 * Prints an error message with perror() and exits.
 * Called after an error involving errno.
 * PARAMETERS:
 * function_name: the function name in which the error occured
 * error_message: the error message to print
 */
void die(const char *function_name, const char *error_message);

/*
 * Prints in which function a NULL model was used and exits.
 * PARAMETERS:
 * function_name: the function name
 */
void null_model(const char *function_name);

/*
 * Prints in which function there was an allocation failure.
 * PARAMETERS:
 * function_name: the function name
 * variable_name: the variable_name
 */
void alloc_fail(const char *function_name, const char *variable_name);

/*
 * Prints an error message saying that the points list
 * of the model used in a function is null and exits.
 * PARAMETERS:
 * function_name: the function name
 */
void points_null(const char *function_name);

#endif
