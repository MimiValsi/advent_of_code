#include <stdio.h>
#include "../misc/misc.h"

int
main(void)
{
        FILE *file;
        file = fopen("../data/day1.txt", "r");

        int floor = 0, position = 0;
        int end = (int) get_file_length(file);

        for (int i = 0; i < end; i++) {
                position++;
                if (fgetc(file) == '(') {
                        floor++;
                } else {
                        floor--;
                }

                if (floor == -1) {
                        printf("%d\n", position);
                }

        }

        printf("floor: %d\n", floor);
        fclose(file);
        return 0;
}
