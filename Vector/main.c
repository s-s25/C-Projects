#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int size;
    int* arr;
} Vector;

Vector make_Vector(int arr[], int size) {
    Vector vector;
    vector.size = size;
    vector.arr = malloc(sizeof(int) * vector.size);
    for (int i = 0; i < size; i++) {
        *(arr + i) = arr[i];
    }
}

void append(Vector* vector, int value) {
    vector->size++;
    vector->arr = realloc(vector->arr, sizeof(int) * vector->size);
    vector->arr[vector->size - 1] = value;
}

int delete(Vector* vector, int index) {
    int* arrTemp = malloc(sizeof(int)*(vector->size - 1));
    int del;
    for (int i = 0; i < vector->size; i++) {
        if (i == index) {
            del = vector->arr[i];
            
        }
        else {
            arrTemp[i] = vector->arr[i];
        }
    }
    free(vector->arr);
    vector->arr = arrTemp;
    vector->size--;
    return del;
}

void print_Vector(Vector* vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->arr[i]);
    }
}

int size(Vector* vector) {
    return vector->size;
}

int get(Vector* vector, int index) {
    return vector->arr[index];
}

int set(Vector* vector, int value, int index) {
    int del = vector->arr[index];
    vector->arr[index] = value;
    return del;
}

int main(void) {
    int arr[] = {7,3,7,8,4};
    Vector vector = make_Vector(arr, 5);
    append(&vector, 7);

    //delete(&vector,2);
    //int g = get(&vector,1);
    //int s = set(&vector, 25, 4);
    //print_Vector(&vector);
}