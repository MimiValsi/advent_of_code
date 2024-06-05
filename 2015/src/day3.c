#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../misc/misc.h"
#include <stdbool.h>
#include <time.h>

/* ^ north
 * < west
 * > east
 * v south 
 */

typedef struct{
        i64 x;
        i64 y;
} Grid;

typedef struct{
        i64 x;
        i64 y;
        u64 presents;
} Position;

_Bool check_house(i64 grid_x, i64 grid_y, Position *pos, u64 size);
u64 input_1(FILE *file);
u64 input_2(FILE *file);
Grid move(char c, Grid *grid_1);

int main(void)
{
        FILE *file = fopen("../data/day3.txt", "r");
        // FILE *file = fopen("../data/test.txt", "r");
        u64 unique_houses = input_1(file);
        u64 santa_and_robo_houses = input_2(file);

        printf("unique_houses = %lld\n", unique_houses);
        printf("santa_and_robo_houses= %lld\n", santa_and_robo_houses);
        fclose(file);

        return 0;
}

_Bool
check_house(i64 grid_x, i64 grid_y, Position *pos, u64 count)
{
        for (u64 i = 0; i < count; i++) {
                if (grid_x == pos[i].x && grid_y == pos[i].y) {
                        pos[i].presents++;
                        if (pos[i].presents > 1) {
                                return false;
                        }
                        return true;
                }
        }

        return false;
}

Grid
move(char c, Grid *grid_1)
{
        switch (c) {
                case '^':
                        grid_1->y++;
                        break;
                case '>':
                        grid_1->x++;
                        break;
                case 'v':
                        grid_1->y--;
                        break;
                case '<':
                        grid_1->x--;
                        break;
        }

        return *grid_1;
}

u64
input_1(FILE *file)
{
        u64 size = 5,
            unique_houses = 0;

        u64 end = get_file_length(file);

        Grid *grid_1 = calloc(1, sizeof(*grid_1));
        if (grid_1 == NULL) {
                printf("Couldn't allocate grid_1! Bye.");
                exit(EXIT_FAILURE);
        }

        Position *pos = calloc(size, size * sizeof(*pos));
        if (pos == NULL) {
                printf("Couldn't allocate position! Bye.");
                exit(EXIT_FAILURE);
        }


        for(u64 i = 0; i < end; i++) {
                if (i >= size) {
                        size *= 1.5;
                        Position *new_pos = realloc(pos, size * sizeof(*pos));
                        if (new_pos == NULL) {
                                printf("Couldn't reallocate Position! Bye.");
                                free(new_pos);
                                exit(EXIT_FAILURE);
                        }
                        pos = new_pos;

                }

                int c = fgetc(file);
                *grid_1 = move(c, grid_1);
                pos[i].x = grid_1->x;
                pos[i].y = grid_1->y;
                pos[i].presents = 0;

                if (check_house(grid_1->x, grid_1->y, pos, i+1))
                        unique_houses++;


        }
        free(pos);
        free(grid_1);

        return unique_houses;
}

u64
input_2(FILE *file)
{
        u64 size = 5,
            // count = 0,
            unique_houses = 0;

        Grid *santa_grid = calloc(1, sizeof(*santa_grid));
        if (santa_grid == NULL) {
                printf("Couldn't allocate grid_1! Bye.");
                exit(EXIT_FAILURE);
        }

        Grid *robo_grid = calloc(1, sizeof(*robo_grid));
        if (robo_grid == NULL) {
                printf("Couldn't allocate grid_1! Bye.");
                exit(EXIT_FAILURE);
        }

        Grid *grid = calloc(1, sizeof(*grid));
        if (grid == NULL) {
                printf("Couldn't allocate grid_1! Bye.");
                exit(EXIT_FAILURE);
        }

        Position *santa_pos = calloc(size, size * sizeof(*santa_pos));
        if (santa_pos == NULL) {
                printf("Couldn't allocate position! Bye.");
                exit(EXIT_FAILURE);
        }

        Position *robo_pos = calloc(size, size * sizeof(*robo_pos));
        if (robo_pos == NULL) {
                printf("Couldn't allocate position! Bye.");
                exit(EXIT_FAILURE);
        }

        Position *pos = calloc(size, size * sizeof(*pos));
        if (pos == NULL) {
                printf("Couldn't allocate position! Bye.");
                exit(EXIT_FAILURE);
        }

        u64 end = get_file_length(file);
        // u64 end = 8192;
        for (u64 i = 0; i < end; i++) {
                // count++;
                if (i >= size) {
                        size *= 1.5;

                        Position *new_santa_pos = realloc(santa_pos, size * sizeof(*santa_pos));
                        if (new_santa_pos == NULL) {
                                printf("Couldn't reallocate Position! Bye.");
                                free(new_santa_pos);
                                exit(EXIT_FAILURE);
                        }
                        santa_pos = new_santa_pos;

                        Position *new_robo_pos = realloc(robo_pos, size * sizeof(*robo_pos));
                        if (new_robo_pos == NULL) {
                                printf("Couldn't reallocate Position! Bye.");
                                free(new_robo_pos);
                                exit(EXIT_FAILURE);
                        }
                        robo_pos = new_robo_pos;

                        Position *new_pos = realloc(pos, size * sizeof(*pos));
                        if (new_pos == NULL) {
                                printf("Couldn't reallocate Position! Bye.");
                                free(new_pos);
                                exit(EXIT_FAILURE);
                        }
                        pos = new_pos;
                }

                // Initialize manually to avoid 'Valgrind uninitialised value error'
                santa_pos[i].presents = robo_pos[i].presents = pos[i].presents = 0;

                int c = fgetc(file);
                *grid = move(c, grid);

                if (i % 2 == 0) {
                        *santa_grid = move(c, santa_grid);
                        pos[i].x = santa_pos[i].x = santa_grid->x;
                        pos[i].y = santa_pos[i].y = santa_grid->y;
                        // printf("santa[%lld].x = %lld\n", i, santa_pos[i].x);
                        // printf("santa[%lld].y = %lld\n\n", i, santa_pos[i].y);

                        if (check_house(grid->x, grid->y, pos, i))
                                unique_houses++;

                } else {
                        *robo_grid = move(c, robo_grid);
                        pos[i].x = robo_pos[i].x = robo_grid->x;
                        pos[i].y = robo_pos[i].y = robo_grid->y;
                        printf("robo[%lld].x = %lld\n", i, robo_pos[i].x);
                        printf("robo[%lld].y = %lld\n\n", i, robo_pos[i].y);

                        if (check_house(grid->x, grid->y, pos, i))
                                unique_houses++;

                }
        }

        free(santa_grid);
        free(santa_pos);
        free(robo_pos);
        free(pos);
        free(robo_grid);
        free(grid);

        // return santa_houses + robo_houses;
        return unique_houses;
}