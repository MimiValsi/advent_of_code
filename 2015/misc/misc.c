#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include <ctype.h>
#include <string.h>

/* Read the file, go to the end, return the length and go back to the beginning.
 * Return the length
 */
long
get_file_length(FILE* file)
{
        fseek(file, 0, SEEK_END);
        long end = ftell(file);
        fseek(file, 0, SEEK_SET);

        return end;
}

/* Read the file, and return line without '\n' */
char*
get_line(FILE* file)
{
        int SIZE = 20;

        char *line = malloc(SIZE * sizeof(char) + 1);
        if (!line) {
                return "ERROR: Couldn't allocate memory. Abort.";
                exit(-1);
        }
        for(int i = 0;;i++) {
                line[i] = (char) fgetc(file);
                if (line[i] == '\n') {
                        line[i] = '\0';
                        return line;
                }
        }

        return NULL;
}

/* Read a string and create an array of 'ints' */
int*
str_to_int_array(char *line, size_t size)
{
        char *n;
        char *str;
        int *nb;
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

int
arr_length(int *arr)
{
        int n = 0;
        for (int i = 0; arr[i] != '\0'; i++) {
                n++;
        }

        return n;
}

unsigned int
max_elem(int *arr, int size)
{
        int max = arr[0];
        for (int i = 0; i < size; i++) {
                if (arr[i] > max) {
                        max = arr[i];
                }
        }

        return max;
}

unsigned int
min_elem(int *arr, int size)
{
        int min = arr[0];
        for (int i = 0; i < size; i++) {
                if (arr[i] < min) {
                        min = arr[i];
                }
        }

        return min;
}

