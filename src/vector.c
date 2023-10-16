#include "vector.h"

double magnitude(struct Vector *vec) {
	return sqrt(pow(vec->x,2.0) + pow(vec->y,2.0));
}

void normalize(struct Vector *vec) {
	vec->x /= magnitude(vec);
	vec->y /= magnitude(vec);
}

void setmagnitude(struct Vector *vec, double mag) {
	normalize(vec);
	vec->x *= mag;
	vec->y *= mag;
}
