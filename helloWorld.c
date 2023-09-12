#include <stdio.h>
#include <string.h>

enum Day
{
    Mon = 1,
    Tue = 2,
    Wed = 3,
    Thu = 4,
    Fri = 5,
    Sat = 6,
    Sun = 7
};

int main()
{
    // enum = a user defined type of named integer identifiers
    // helps to make a program more readable
    // enums are not strings, but they can be treated as int

    enum Day today = Tue;

    if (today == Sat || today == Sun)
    {
        printf("hooray ninja, its the weekends!!");
    }
    else
    {
        printf("aw man, its a workday, all good brah stay on the grind");
    }

    return 0;
}