/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** Header for vector.c file ***/

#ifndef __VECTOR__
#define __VECTOR__

#include "struct.h"

#define PI 3.14159265358

/*
 * Computes the cross product (^) of 2 3D vectors.
 * PARAMETERS:
 * v1: vector 1
 * v2: vector 2
 * RETURN VALUE:
 * the cross product vector
 */
vector cross_product(const vector v1, const vector v2);

/*
 * Computes the scalar product (.) of 2 3D vectors.
 * PARAMETERS:
 * v1: vector 1
 * v2: vector 2
 * RETURN VALUE:
 * the scalar product
 */
long double scalar_product(const vector v1, const vector v2);

/*
 * Computes the magnitude of a 3D vector.
 * PARAMETERS:
 * v: the vector
 * RETURN VALUE:
 * the magnitude
 */
long double magnitude(const vector v);

/*
 * Computes the multiplication of a 3D vector by a scalar.
 * PARAMETERS:
 * v: vector 1
 * x: the scalar
 * RETURN VALUE:
 * the multiplication vector
 */
vector mult(const vector v, const long double x);

/*
 * Computes the division of a 3D vector by a scalar.
 * Basically multipying by the inverse.
 * PARAMETERS:
 * v: vector 1
 * x: the scalar
 * RETURN VALUE:
 * the division vector
 */
vector div_vector(const vector v, const long double x);

/*
 * Computes the sum of 2 3D vectors.
 * PARAMETERS:
 * v1: vector 1
 * v2: vector 2
 * RETURN VALUE:
 * the sum vector
 */
vector sum(const vector v1, const vector v2);

/*
 * Computes the substraction of 2 3D vectors.
 * Basically the sum of v1 and -1 * v2.
 * PARAMETERS:
 * v1: vector 1
 * v2: vector 2
 * RETURN VALUE:
 * the substraction vector
 */
vector sub(const vector v1, const vector v2);

/*
 * Computes the position vector (cartesian coordinates) from a
 * point in polar coordinates.
 * PARAMETERS:
 * latitude: the point latitude
 * longitude: the point longitude
 * r: the point elevation
 * RETURN VALUE:
 * the position vector
 */
vector position_vector(const long double latitude,const long double longitude,
                       const long double r);

/*
 * Computes the velocity vector of a point on the surface of a model
 * taking into account the fact that the model is spherical.
 * PARAMETERS:
 * p: the point
 * RETURN VALUE:
 * the velocity vector
 */
vector velocity_vector(point_velocity pv);

#endif
