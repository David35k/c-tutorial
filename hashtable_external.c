#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 69
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    // function that takes a persons name and hashes it

    int length = strlen(name);

    unsigned int hashValue = 0;

    for (int i = 0; i < length; i++)
    {
        hashValue += name[i];
        hashValue *= name[i];
        hashValue %= TABLE_SIZE;
    }

    return hashValue;
}

void initTable()
{
    // creates an empty hash table by setting every pointer to NULL

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void printTable()
{
    // prints the hash table

    printf("\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%d\t", i);

            person *tmp = hash_table[i];
            while (tmp != NULL)
            {
                printf(" - %s,%i", tmp->name, tmp->age);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }

    printf("\n");
}

bool tableInsert(person *p)
{
    // inserts a new person in the hash table, if at same index creates linked list

    if (p == NULL)
        return false;

    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;

    return true;
}

person *tableLookup(char *name)
{
    // finds a person in the hash table by name, returns pointer to person

    int index = hash(name);
    person *tmp = hash_table[index];

    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        tmp = tmp->next;
    }

    return tmp;
}

bool tableDelete(char *name)
{
    // finds a person in hash table and deletes them, returns true if success

    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;

    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL)
        return false;
    if (prev == NULL)
    {
        hash_table[index] = tmp->next;
        return true;
    }

    prev->next = tmp->next;

    return true;
}

int main()
{
    initTable();

    person david = {"David", 16};
    person daniel = {"Daniel", 12};
    person gerbert = {"Abraham", 25};
    person ferb = {"Ferb", 69};
    person jim = {"Jim", 1};
    person joe = {"Joe", 2};
    person noshirwan = {"Noshirwan", 3};
    person spencer = {"Spencer", 4};
    person john = {"John", 5};
    person yasuhiro = {"Yasuhiro", 6};

    tableInsert(&david);
    tableInsert(&daniel);
    tableInsert(&gerbert);
    tableInsert(&ferb);
    tableInsert(&jim);
    tableInsert(&joe);
    tableInsert(&noshirwan);
    tableInsert(&spencer);
    tableInsert(&john);
    tableInsert(&yasuhiro);

    printTable();

    person *temp = tableLookup("Jim");

    if (temp == NULL)
    {
        printf("\nperson not found!\n");
    }
    else
    {
        printf("\nfound the person! name: %s, age: %i\n", temp->name, temp->age);
    }

    tableDelete("Noshirwan");
    tableDelete("Ferb");
    tableDelete("Jim");

    printTable();

    temp = tableLookup("Jim");

    if (temp == NULL)
    {
        printf("\nperson not found!\n");
    }
    else
    {
        printf("\nfound the person! name: %s, age: %i\n", temp->name, temp->age);
    }

    return 0;
}