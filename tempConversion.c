//Converts degrees celcius to farenheit and vice versa
// F = (C * 9/5) + 32
// C = (F - 32) * 5/9

#include <stdio.h>
#include <ctype.h>

int main() {

    char unit; // unit of measurement
    float temp; // temperature

    // get unit from user
    printf("\nIs the temperature in (F) or (C)?");
    scanf("%c", &unit);

    // converts to uppercase
    unit = toupper(unit); 

    // get temp from user
    printf("\nHow many degrees is it?");
    scanf("%f", &temp);

    // carry out the correct formula for each unit
    if(unit == 'C') {
        temp = (temp * 9/5) + 32;
        printf("The temperature in farenheit is: %.1f", temp);
    } else if(unit == 'F') {
        temp = (temp - 32) * 5/9;
        printf("The temperature in celcius is: %.1f", temp);
    } else {
        printf("Enter valid unit (C or F)");
    }

    return 0;
}