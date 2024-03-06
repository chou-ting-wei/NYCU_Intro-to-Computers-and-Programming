#include "vector.h"
#include <stdlib.h>

vector* vector_construct(int _length) {
	vector* v = (vector*)malloc(sizeof(vector));
	v->length = _length;
	v->vec = (int*)calloc(_length, sizeof(int));
	return v;
}