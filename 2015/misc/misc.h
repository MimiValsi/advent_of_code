#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef int8_t i8;
typedef int32_t i32;
typedef int64_t i64;
typedef int16_t i16;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// Haven't figure it out how to create a pointer of pointers
// like char str[x][y]
struct Dyn_str {
        char str[5][6];
};

#define NL() printf("\n")

u64 get_file_length(FILE* file);
struct Dyn_str line_split(char* line, char* delim);
char* get_line(FILE* file);
i32* str_to_int_array(char* line, u32 len);
u32 arr_length(i32* arr);
i32 max_elem(i32* arr, u32 size);
i32 min_elem(i32* arr, u32 size);
void* alloc_2D_array(u32 rows, u32 cols);
void free_2D_array(i64 **arr, u32 rows);
