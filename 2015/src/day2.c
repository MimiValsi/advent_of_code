#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "../misc/misc.h"


typedef struct {
        unsigned int l; // length
        unsigned int w; // width
        unsigned int h; // height
} Dimension;

Dimension box(int *arr);
void initialize(Dimension *dimension);
unsigned int box_surface(Dimension dimension);
unsigned int extra_slack(Dimension dimension);
unsigned int total_paper(unsigned int surface, unsigned int slack);
int* insertion_sort(Dimension dimension);
unsigned int total_ribbon(int *arr);

int main(void)
{
        Dimension dimension;
        initialize(&dimension);
        FILE *file = fopen("../data/day2.txt", "r");
        char *line;
        int *nb = NULL;
        unsigned int paper = 0;
        unsigned int ribbon = 0;
        for (int i = 0; i < 1000; i++) {
                line = get_line(file);
                size_t len = strlen(line);
                nb = str_to_int_array(line, len);
                dimension = box(nb);
                unsigned int surface = box_surface(dimension);
                unsigned int slack = extra_slack(dimension);
                paper += total_paper(surface, slack);
                int *arr = insertion_sort(dimension);
                ribbon += total_ribbon(arr);
                // for (int j = 0; j < 3; j++) {
                //         printf("> %d\n", arr[j]);
                // }
                // printf("\n");

                free(line);
                free(nb);
                // break;
        }

        printf("%d\n", paper);
        printf("%d\n", ribbon);

        fclose(file);
        return 0;
}

int*
insertion_sort(Dimension dimension)
{
        int *arr = malloc(3 * sizeof(int));
        arr[0] = dimension.w;
        arr[1] = dimension.l;
        arr[2] = dimension.h;

        for (int i = 0; i < 3; i++) {
                int j = i;
                while (j > 0 && arr[j - 1] > arr[j]) {
                        int tmp = arr[j - 1];
                        arr[j - 1] = arr[j];
                        arr[j] = tmp;
                }
        }
        return arr;
}

unsigned int
total_ribbon(int *arr)
{
        unsigned int wrapper = 0,
        ribbon = 0;

        wrapper = arr[0]*2 + arr[1]*2;
        ribbon = arr[0] * arr[1] * arr[2];
        return wrapper + ribbon;
}

unsigned int
total_paper(unsigned int surface, unsigned int slack)
{
        return surface + slack;
}

unsigned int
extra_slack(Dimension dimension)
{
        int arr[3] = {0};
        arr[0] = dimension.l * dimension.w;
        arr[1] = dimension.w * dimension.h;
        arr[2] = dimension.h * dimension.l;
        unsigned int slack = min_elem(arr, 3);

        return slack;
}

unsigned int
box_surface(Dimension dimension)
{
        return 2*dimension.l*dimension.w + 2*dimension.w*dimension.h + 2*dimension.h*dimension.l;
}

void initialize(Dimension *dimension)
{
        dimension->l = 0;
        dimension->w = 0;
        dimension->h = 0;
}

Dimension
box(int *arr)
{
        Dimension dimension;
        dimension.l = arr[0];
        dimension.w = arr[1];
        dimension.h = arr[2];

        return dimension;
}
