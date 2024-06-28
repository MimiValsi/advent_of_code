#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef int32_t i32;
typedef int64_t i64;
typedef int16_t i16;
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef char byte;

#define NL() printf("\n")

u64 get_file_length(FILE* file);
char* get_line(FILE* file);
i32* str_to_int_array(char* line, size_t len);
u32 arr_length(i32* arr);
i32 max_elem(i32* arr, u32 size);
i32 min_elem(i32* arr, u32 size);
void* alloc_2D_array(u32 rows, u32 cols);
void free_2D_array(i64 **arr, u32 rows);
