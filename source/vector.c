/*************************/
/*** author: Yann Droy ***/
/*********** Fall 2017 ***/
/*************************/

/*** vector.c file ***/
/*** Contains mathematical functions involving vectors ***/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "include/struct.h"
#include "include/vector.h"
#include "include/model_process.h"

vector cross_product(const vector v1, const vector v2){
    vector r = {.x = v1.y * v2.z - v1.z * v2.y,
                .y = v1.z * v2.x - v1.x * v2.z,
                .z = v1.x * v2.y - v1.y * v2.x};

    return r;
} /* cross_product() */

long double scalar_product(const vector v1, const vector v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
} /* scalar_product() */

long double magnitude(const vector v){
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
} /* magnitude() */

vector mult(const vector v, const long double x){
    vector r = {.x = v.x * x,
                .y = v.y * x,
                .z = v.z * x};

    return r;
} /* mult() */

vector div_vector(const vector v, const long double x){
    return mult(v, (1 / x));
} /* div_vector() */

vector sum(const vector v1, const vector v2){
    vector r = {.x = v1.x + v2.x,
                .y = v1.y + v2.y,
                .z = v1.z + v2.z};

    return r;
} /* sum() */

vector sub(const vector v1, const vector v2){
    return sum(v1, mult(v2, -1.0));
} /* sub() */

vector position_vector(const long double latitude,const long double longitude,
                       const long double r){
    // Simple variables, converted to radians
    long double a = longitude * PI / 180.0;
    long double b = latitude * PI / 180.0;
    vector v;

    // Spherical coorinates formula
    v.x = r * cos(a) * cos(b);
    v.y = r * sin(a) * cos(b);
    v.z = r * sin(b);

    return v;
} /* position_vector() */

vector velocity_vector(point_velocity pv){
    // Simple variables
    long double a = pv.p.longitude * PI / 180.0;
    long double b = pv.p.latitude * PI / 180.0;
    long double u_a = pv.v.v_east;
    long double u_b = pv.v.v_north;
    vector v;

    // Formula
    v.x = (-sin(a) * u_a) - (sin(b) * cos(a) * u_b);
    v.y = (cos(a) * u_a) - (sin(b) * sin(a) * u_b);
    v.z = cos(b) * u_b;

    return v;
} /* velocity_vector() */
