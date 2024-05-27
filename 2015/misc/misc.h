#include <stdio.h>

long get_file_length(FILE* file);
char* get_line(FILE* file);
int* str_to_int_array(char* line, size_t len);
int arr_length(int* arr);
unsigned int max_elem(int* arr, int size);
unsigned int min_elem(int* arr, int size);
