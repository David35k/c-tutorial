#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 69
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFFUL)

typedef struct
{
    char name[MAX_NAME];
    int age;
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
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%i\t<deleted>\n", i);
        }
        else
        {
            printf("\t%d\t%s,%i\n", i, hash_table[i]->name, hash_table[i]->age);
        }
    }

    printf("\n");
}

bool tableInsert(person *p)
{
    // inserts a new person in the hash table, returns true if success

    int index = hash(p->name);

    if (p == NULL)
        return false;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == DELETED_NODE || hash_table[try] == NULL)
        {
            hash_table[try] = p;
            return true;
        }
    }

    return false;
}

person *tableLookup(char *name)
{
    // finds a person in the hash table by name, returns pointer to person

    int index = hash(name);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;

        if (hash_table[try] == NULL)
            return false;
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[try]->name, name, MAX_NAME) == 0)
        {
            return hash_table[try];
        }
    }

    return NULL;
}

bool tableDelete(char *name)
{
    // finds a person in hash table and deletes them, returns true if success

    int index = hash(name);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false;
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[try]->name, name, MAX_NAME) == 0)
        {
            hash_table[try] = DELETED_NODE; // if it was allocated using malloc would have to free
            return true;
        }
    }

    return false;
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

    person *temp = tableLookup("Noshirwan");

    if (temp == NULL)
    {
        printf("\nperson not found!\n");
    }
    else
    {
        printf("\nfound the person! name: %s, age: %i\n", temp->name, temp->age);
    }

    tableDelete("Noshirwan");

    printTable();

    temp = tableLookup("Noshirwan");

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