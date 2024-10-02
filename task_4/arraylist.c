#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

ArrayList* create_array_list () {
    ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));

    list->size = 0;
    list->capacity = 10;
    list->data = (int*) malloc(list->capacity * sizeof(int));

    return list;
}

void add (ArrayList* list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(int));
    }

    list->data[list->size++] = value;
}

void insert (ArrayList* list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("out of bounds...\n");
        return;
    }

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(int));
    }

    for (int k = list->size; k > index; k--)
        list->data[k] = list->data[k - 1];

    list->data[index] = value;
    list->size++;
}

int size (ArrayList* list) { return list->size; }

void _remove (ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("out of bounds...\n");
        return;
    }

    for (int k = index; k < list->size - 1; k++)
        list->data[k] = list->data[k + 1];

    list->size--;
}

void set (ArrayList* list, int index, int value) {
    if (index < 0 || index >= list->size) {
        printf("out of bounds...\n");
        return;
    }

    list->data[index] = value;
}

int get (ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("out of bounds...\n");
        return -1;
    }

    return list->data[index];
}