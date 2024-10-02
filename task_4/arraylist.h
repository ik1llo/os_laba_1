typedef struct {
    int* data;
    int size;
    int capacity;
} ArrayList;

ArrayList* create_array_list();
void add (ArrayList *list, int value);
void insert (ArrayList *list, int idx, int value);
int size (ArrayList *list);
void _remove (ArrayList *list, int idx);
void set (ArrayList *list, int idx, int value);
int get (ArrayList *list, int idx);