#include "misc.h"
#include <stdio.h>
#include <string.h>

#define SIZE 40
/* Read the file, go to the end, return the length and go back to the beginning.
 * Return the length
 */
u64
get_file_length(FILE* file)
{
        fseek(file, 0, SEEK_END);
        u32 length = ftell(file);
        rewind(file);

        return length;
}

/* Read the file, and return line without '\n' */
char*
get_line(FILE* file)
{
        char *line = malloc(SIZE * sizeof(char) + 1);
        if (!line) {
                perror("ERROR: Couldn't allocate memory.");
                exit(-1);
        }
        for(i32 i = 0;;i++) {
                line[i] = fgetc(file);
                if (line[i] == '\n') {
                        line[i] = '\0';
                        return line;
                }
        }

        return NULL;
}

/* Read a string and create an array of 'ints' */
i32*
str_to_int_array(char *line, size_t size)
{
        char *n;
        char *str;
        i32 *nb;
        size_t j = 0,
               o = 0;

        n = malloc(size * sizeof(char) + 1);
        if (!n) {
                return NULL;
                exit(-1);
        }

        str = calloc(5, 5);
        if (!str) {
                return NULL;
                exit(-1);
        }

        nb = calloc(5, 5);
        if (!nb) {
                return NULL;
                exit(-1);
        }

        for (size_t i = 0; i < size+1; i++) {
                if (isdigit(line[i])) {
                        str[j] = line[i];
                        j++;
                } else {
                        j = 0;
                        nb[o] = atoi(str);
                        free(str);
                        str = calloc(5, 5);
                        o++;
                }
        }
        free(str);
        free(n);

        return nb;
}

// check array length.
u32
arr_length(i32 *arr) {
  i32 n = 0;
  for (i32 i = 0; arr[i] != '\0'; i++) {
    n++;
  }

  return n;
}

// Check for biggest number in a array
i32
max_elem(i32 *arr, u32 size)
{
        i32 max = arr[0];
        for (u32 i = 0; i < size; i++) {
                if (arr[i] > max) {
                        max = arr[i];
                }
        }

        return max;
}

// Check for the lowest number in a array
i32
min_elem(i32 *arr, u32 size)
{
        i32 min = arr[0];
        for (u32 i = 0; i < size; i++) {
                if (arr[i] < min) {
                        min = arr[i];
                }
        }

        return min;
}

// allocate a 2D array, and initialize all values to 0
void*
alloc_2D_array(u32 rows, u32 cols)
{
        i32 **arr = calloc(rows, sizeof(i32*));
        for (u32 i = 0; i < rows; i++) {
                arr[i] = calloc(cols, sizeof(i32));
        }
        return arr;
}

// free a 2D array
void
free_2D_array(i64 **arr, u32 rows)
{
        for (u32 i = 0; i < rows; i++) {
                free(arr[i]);
        }
        free(arr);
}

