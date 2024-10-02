#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

int main () {
    ArrayList* list = create_array_list();

    add(list, 10);
    add(list, 20);
    add(list, 30);

    insert(list, 1, 15);
 
    printf("array list size: %d\n\n", size(list));

    for (int k = 0; k < size(list); k++)
        printf("array list element #%d - %d\n", k + 1, get(list, k));

    free(list->data);
    free(list);

    return 0;
}

