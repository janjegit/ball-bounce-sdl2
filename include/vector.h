#ifndef VECTOR_H_INCLUDE
#define VECTOR_H_INCLUDE

#include <math.h>
#include "types.h"

double magnitude(struct Vector *vec);

void normalize(struct Vector *vec);

void setmagnitude(struct Vector *vec, double mag);

#endif


