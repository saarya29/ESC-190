#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct businesses{
    char *name; //when you don't know the size, you should use a pointer. 
    int phone[10];
}businesses;

void read_in_names(businesses **terms, int *stores, char *filename)
{
    FILE *f_p = fopen(filename, "r"); //allows you to open the file. 

    char line[10000];
    int index = 0;
    int ph_sz = 0;

    fgets(line, sizeof(line), f_p); //you need to get fgets to read the first line before you get i tto call atoi. 

    *stores = atoi(line);// you get the number from the first line. 

    //now we need to read and create a malloc. 

    *terms = (businesses *)malloc((*stores)*sizeof(businesses));

//since name is a pointer, you're going to have to allocate memory for the names separately. Using student2 logic. 

    while (fgets(line, sizeof(line), f_p)!= NULL) //hopefully this is correct. Or should I be using line??
    {
        if (line[index] != '-')
        {
            (*terms)[i].phone[ph_sz++] = line[index] - '\0'; //they're pasing (making the phonennumber into integerrs. Remember integer parsing is a very important tool you might need to use. )
            while (line[++index]!= '\t')
            {
                index ++;
                strcpy(terms[i]->name, line + index); //oka.... not 100 % sure I understand teh point of the line and the index part but oka. 
                free(line);
            }
        }
    }
    fclose(f_p);
}//ask about this code... not sure if it owuld completely work. 

void free_numbers( businesses *terms, int size)
{
    //clear all the garbage cans
    for (int i = 0; i < size; i++)
    {
        free(terms[i]->name);
        free(terms[i]->phone);
    }
    free(terms); //yipee
}