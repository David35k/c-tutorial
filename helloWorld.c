#include <stdio.h>

int main()
{
    FILE *pF = fopen("C:\\Users\\david\\OneDrive\\Desktop\\test.txt", "r");
    char buffer[255];

    // check if the file exists
    if (pF == NULL)
    {
        printf("Dude, unable to open file");
    }
    else
    {
        // loops through all of the lines in the file and prints them
        // if reaches end of file fgets will return NULL
        while (fgets(buffer, 255, pF) != NULL)
        {
            printf("%s", buffer);
        }
    }

    fclose(pF);

    return 0;
}