#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check user input
    if (argc != 2)
    {
        printf("INVALID INPUT");
        return 1;
    }

    // Open memory card
    FILE *memory_card = fopen(argv[1], "r");

    // Check input file
    if (memory_card == NULL)
    {
        printf("INVALID MEMORY CARD");
        return 2;
    }

    // Buffer to read into
    BYTE buffer[512];

    // Counter of recovered images
    int count = 0;

    // Pointer to new file
    FILE *new_file = NULL;

    //New filename
    char filename[8];

    // Loop through card until end is reachd
    while (fread(&buffer, 512, 1, memory_card) == 1)
    {
        // Check start of every byte array
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(new_file);
            }

            sprintf(filename, "%03i.jpg", count);
            new_file = fopen(filename, "w");
            count++;
        }
        
        if (count != 0)
        {
            fwrite(&buffer, 512, 1, new_file);
        }
    }
    
    fclose(new_file);
    fclose(memory_card);
}