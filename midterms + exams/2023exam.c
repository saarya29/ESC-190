#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct business {
    int phone_number[10];
    char *name;
} business;

//similar to the first function in autocomplete. 
void read_numbers(const char *filename, business **whitepages, int *size)
{
    //1. Reading the filenmaes:
    FILE *fp = fopen(filename, "r");
    *size = atoi(name);

    *whitepages = (business *)malloc((*size)*sizeof(business));
    if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%lf\t%[^\n]", &phone_number, name);
            (*terms)[i].phone_number = phone_number;
            strcpy((*terms)[i].term, name);
    }}//the only problem is realizing that this behaves more like student 2 but you can't allocate memory i don't think more than once.

    void free_numbers(business *whitepages, int size)
    {
        free(whitepages);
    }