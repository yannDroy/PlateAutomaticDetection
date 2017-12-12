/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Structures used in the project are defined in this file ***/

#ifndef __STRUCT__
#define __STRUCT__

/*
 * Point on the surface of a model.
 * Coordinates are [latitude;longitude].
 * latitude: latitude of the point
 * longitude: longitude of the point
 */
typedef struct point {
    long double latitude;
    long double longitude;
} point;

/*
 * Velocity information.
 * It can be seen as a vector with [v_north;v_east] coordinates
 * v_north: velocity according to the North direction
 * v_east: velocity according to the East direction
 */
typedef struct velocity {
    long double v_north;
    long double v_east;
} velocity;

/*
 * Velocity information for a given point
 * p: the point
 * v: the point velocity vector
 */
typedef struct point_velocity {
    point p;
    velocity v;
} point_velocity;

/*
 * Structure for a model.
 * A model is a list of all its surface points and their velocities.
 * n: the number of points
 * n_lat: the number of points on the same latitude
 * n_long: the number of points on the same longitude
 * (the model can be seen as a (n_lat * n_long) matrix)
 * points: the points list
 * matrix: the matrix representation of the model
 * (matrix[i][j] == plate_number)
 */
typedef struct model {
    int n;
    int n_lat;
    int n_long;
    point_velocity *points;
} model;

/*
 * Structure for a 3D vector (Cartesian coordinates).
 * x: x coordinate
 * y: y coordinate
 * z: z coordinate
 */
typedef struct vector {
    long double x;
    long double y;
    long double z;
} vector;

#endif
