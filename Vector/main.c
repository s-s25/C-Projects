#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int size;
    int* arr;
} Vector;

void append(Vector* vector, int value) {
  

    vector->size++;
    malloc(sizeof(int) * vector->size);

}

int delete(Vector* vector, int index) {

}

void print_Vector(Vector* vector) {

}

int size(Vector* vector) {

}

int get(Vector* vector, int index) {

}

int set(Vector* vector, int value, int index) {

}