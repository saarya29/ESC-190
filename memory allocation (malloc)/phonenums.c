#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct business{
    int phone[10];
    char *name; 
}business; 


void read_business(business **whitepage, int *size, char *filename)
{
    FILE *fp = fopen(filename, "r");
    int line[20]; //the number should not be more than 20 digits hopefully. 
    if (fgets(line, sizeof(line), fp))
    {
        *size = atoi(line);
    }
    //I'm most likely never going to use line again in adding becauase I don't want to risk going psat the first line. 

    *whitepages = (business *)malloc(sizeof(business)*(*size));

    //I know that the first 10 and teh 2 dashes are going to be the phonenumbers. 
    //int bus_size = get_size_of_business(fp); I'm going to get rid of this for now. 
    char buffer[1000000]; 
    //since this array would then be statically determined, you will not be able to allocate memory to it. 
    //instead char *buffer =  malloc(100000 * sizeof(char));
    //char *new_buffer = realloc(buffer, 200000 * sizeof(char)); 
    ///whenever you have a realloc, you know you probably need to have a malloc somewhere to reallocate the memory to. 
    int count = 0;

    for (int i = 0; i < *size; i++)
    {
        if (!fgets(buffer, sizeof(buffer),fp))
        {
            (*whitepages)[i].phone[0] = buffer[0]; //and then you technically do that for all the phone numbers. 
            (*whitepages)[i].phone[1] = buffer[1];
            (*whitepages)[i].phone[2] = buffer[2];

            (*whitepages)[i].phone[3] = buffer[4];
            (*whitepages)[i].phone[4] = buffer[5];
            (*whitepages)[i].phone[5] = buffer[6];

            (*whitepages)[i].phone[6] = buffer[8];
            (*whitepages)[i].phone[7] = buffer[9];
            (*whitepages)[i].phone[8] = buffer[10];
            (*whitepages)[i].phone[9] = buffer[11]; //all of these are going to be in the phone...
        }
        while (buffer != NULL) //hopefully it's going to copy through. 
        {
            count ++; //and this would be the size of the buffer. 
        }
        (*whitepages)[i].name = malloc(strlen(count -14)+1); //you would have to malloc the names a bit separately. 
        strcpy((*whitepages)[i].name, count + 14);
    }
    //int k = 0;
/*    for (int j = 0; j<12; j++)
    {
        if (buffer[j] != '-')
        {
            (*whitepage)[i].phone[k++] = buffer[j];
        }
    }*/
    /*for (a = 13; a < count; a++)
    {

    }
    (*whitepages)[i].phone[k] = '\0';

    
    if ((*whitepage)[i].name)
    {
         //strcpy will need it from the first pointer onwards,
        (*whitepage)[i].name[strcspn((*whitepage)[i].name, "\n")] = '\0';
    }*/
    fclose(fp);
}
    


