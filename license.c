#include <stdio.h>
#include <string.h>

#define MAX_PLATES 8
#define MAX_PLATE_LEN 6

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[MAX_PLATE_LEN + 1];

    // Create array to store plate numbers
    char plates[MAX_PLATES + 1][MAX_PLATE_LEN + 1];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, MAX_PLATE_LEN + 1, infile) == MAX_PLATE_LEN + 1)
    {
        // Replace '\n' with '\0'
        buffer[MAX_PLATE_LEN] = '\0';

        // Save plate number in array
	strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < idx; i++)
    {
        printf("%s\n", plates[i]);
    }
}
