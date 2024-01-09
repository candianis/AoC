#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define FILE_NAME "./2015/Day1/inputText.txt"

int main()
{
    FILE* puzzleInput = fopen(FILE_NAME, "r");
    int currentValue = 0;
    int commandAmount = 0;

    if (puzzleInput == NULL) {
        printf("Can't open %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    
    printf("%s file was opened succesfully.\n", FILE_NAME);
    int c = 0;

    while ((c = fgetc(puzzleInput)) != EOF) {
        ++commandAmount;
        
        if (c == '(')
            ++currentValue;
        if (c == ')')
            --currentValue;

        if (currentValue < 0)
            break;
    }

    fclose(puzzleInput);

    printf("The final value is: %d\n The amount of commands were: %d", currentValue, commandAmount);

}