#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Sort/sort.h"


#define FILE_NAME "./2015/Day2/puzzleInput.txt"

int main()
{
    FILE* puzzle_input = fopen(FILE_NAME, "r");

    if (puzzle_input == NULL) {
        printf("Can't open %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    
    int total_ribbon = 0;

    char line[1024];
    while (fgets(line, sizeof(line), puzzle_input) != NULL) {
        int length = 0, width = 0, height;
        int n = sscanf(line, "%dx%dx%d", &length, &width, &height);

        int dimensions[3] = { length, width, height };
        insertion_sort_int(dimensions, 3);

        int area_with_ribbon = (dimensions[0] * 2) + (dimensions[1] * 2) + (length * width * height);
        printf("Total area with ribbon: %d\n", area_with_ribbon);
        total_ribbon += area_with_ribbon;
    }

    printf("\nTotal: %d\n", total_ribbon);

    fclose(puzzle_input);


}