#include <stdio.h>
#include <string.h>

typedef struct{
    char name[25];
    char password[12];
    int id;
} User;

// User is now the name for structs that have a name password and id

int main()
{
    // typedef = reserved keyword that gives an existing datatype a "nickname"

    User user1 = {"David", "sussy123", 14};
    User user2 = {"Bruhman", "password123", 3};

    printf("name: %s, password: %s, ID: %d\n", user1.name, user1.password, user1.id);
    printf("name: %s, password: %s, ID: %d\n", user2.name, user2.password, user2.id);

    return 0;
}