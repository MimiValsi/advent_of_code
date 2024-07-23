#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "misc.h"

#define NUM_LINE 339

// Number of Tables
#define N 10
#define TEST 8

typedef struct {
        char name[3];
        u16 value;
} Wire;

typedef struct {
        Wire wire1;
        Wire wire2;
        Wire dest;
        char cmd[6];
} Table;

void part1(FILE *file);
void part2(FILE *file);
bool present_struct_wire(Table *table, u16 len, char *to_cmp);

int main(void)
{
        FILE *file = fopen("../data/test.txt", "r");
        part1(file);
        // rewind(file);
        // part2(file);
        fclose(file);
        return 0;
}

void
part1(FILE *file)
{
        Table table[N] = {0};
        char *line = NULL;
        char *token = NULL;
        char tmp[6][6] = {0};

        // j follows tmp flow and o follows table flow
        u32 j = 0,
            o = 0;

        for (u32 i = 0; i < 3; i++) {
        // for (u32 i = 0; i < TEST; i++) {
        // for (u32 i = 0; i < NUM_LINE; i++) {
                line = get_line(file);
                token = strtok(line, " ");
                while (token) {
                        strcpy(tmp[j], token);
                        printf("token %s\n", token);
                        printf("tmp[%d]: %s\n", j, tmp[j]);
                        j++;
                        NL();
                        NL();
                        token = strtok(NULL, " ");
                }
                // reset j. tmp is only needed to facilitate data parse
                j = 0;
                if (isdigit(tmp[0][0])) {
                        strcpy(table[o].dest.name, tmp[2]);
                        table[o].dest.value = atoi(tmp[0]);
                        o++;
                        continue;
                }

                if (strcmp(tmp[0], "NOT") == 0) {
                        strcpy(table[o].wire1.name, tmp[1]);
                        strcpy(table[o].dest.name, tmp[3]);
                        table[o].dest.value = ~table[o].wire1.value;
                        continue;
                } else {
                        printf("tmp 0: %s\n", tmp[0]);
                        printf("tmp 1: %s\n", tmp[1]);
                        printf("tmp 2: %s\n", tmp[2]);
                        printf("tmp 3: %s\n", tmp[3]);
                        printf("tmp 4: %s\n", tmp[4]);
                        strcpy(table[o].wire1.name, tmp[0]);
                        // strcpy(table[o].cmd, tmp[1]);
                        strcpy(table[o].wire2.name, tmp[2]);
                        if (strcmp(tmp[1], "AND") == 0) {
                                strcpy(table[o].dest.name, tmp[4]);
                                // table[o].dest.value = table[o-1].wire1.value & table[o-2].wire2.value;
                                table[o].dest.value = table[0].wire1.value & table[1].wire2.value;
                                o++;
                                continue;
                        }

                        if (strcmp(tmp[1], "OR")) {
                                strcpy(table[o].dest.name, tmp[4]);
                                table[o].dest.value = table[o].wire1.value | table[o].wire2.value;
                                o++;
                                continue;
                        }

                        if (strcmp(tmp[1], "RSHIFT")) {
                                strcpy(table[o].dest.name, tmp[4]);
                                table[o].dest.value = table[o].wire1.value >> atoi(tmp[2]);
                                o++;
                                continue;
                        }

                        if (strcmp(tmp[1], "LSHIFT")) {
                                strcpy(table[o].dest.name, tmp[4]);
                                table[o].dest.value = table[o].wire1.value << atoi(tmp[2]);
                                o++;
                                continue;
                        }
                }

                free(line);
        }

        for (u32 i = 0; i < TEST; i++) {
                printf("table[%d].wire1: .name: %2s | .value %d\n", i, table[i].wire1.name, table[i].wire1.value);
        }
        NL();

        for (u32 i = 0; i < TEST; i++) {
                printf("table[%d].wire2: .name: %2s | .value %d\n", i, table[i].wire2.name, table[i].wire2.value);
        }
        NL();

        for (u32 i = 0; i < TEST; i++) {
                printf("table[%d].dest: .name: %3s | .value %d\n", i, table[i].dest.name, table[i].dest.value);
        }
        // printf("table[0].dest.name: %s\n", table[0].dest.name);
        // printf("table[0].dest.value: %d\n", table[0].dest.value);

        // for (u32 i = 0; i < 6; i++) {
        //         printf("tmp[%d]: %s\n", i, tmp[i]);
        // }

        // printf("Tables\n");
        // for (u32 i = 0; i < 10; i++) {
        //         printf("wire: %s\n", table[i].wire);
        //         printf("value: %d\n", table[i].value);
        // }

        // free(line);
}

bool
present_struct_wire(Table *table, u16 len, char *to_cmp)
{
        for (u32 i = 0; i < len; i++) {
                if (strcmp(table[i].wire1.name, to_cmp) == 0) {
                        return true;
                }
        }

        return false;
}

void
part2(FILE *file)
{

}
