#include <stdio.h>

int main()
{
    // w is for writing to the file, overwrites what is already in it
    // a is for appending to the file, adds to the file instead of overwriting

    FILE *pF = fopen("C:\\Users\\david\\OneDrive\\Desktop\\test.txt", "w");

    fprintf(pF, "\nobamna :3");

    fclose(pF); //close file at the end


    // deleting a file


    // if (remove("test.txt") == 0)
    // {
    //     printf("\nNice dude, you deleted that file");
    // }
    // else
    // {
    //     printf("\nDawg, that file was NOT deleted");
    // }

    return 0;
}