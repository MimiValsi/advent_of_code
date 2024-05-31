#include <stdio.h>
typedef unsigned int u32;
typedef long i32;
typedef long long i64;
typedef unsigned long long u64;
typedef int i16;

u64 get_file_length(FILE* file);
char* get_line(FILE* file);
i32* str_to_int_array(char* line, size_t len);
u32 arr_length(i32* arr);
i32 max_elem(i32* arr, u32 size);
i32 min_elem(i32* arr, u32 size);
void* alloc_2D_array(u32 rows, u32 cols);
void free_2D_array(i64 **arr, u32 rows);
