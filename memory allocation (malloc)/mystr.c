#include "mystr.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//want soething like python strings but mutable
//writing in pseudopython
/*s = "abc";
s[1] = 'z'; //make s be 'azc'
s.append('d')*/
//want to initialize the string. 
//want to be able to change a character at an index
// want to be able to append

// #block is [a b \'0']
//capacity is teh size of the block
// sz = 2

//the capacity is teh actual size of the block, while the size is the size of the string. 
// you want to be able to use what you ahave in mystr.c and mystr.h and use them in your codes. 
#if !defined(MYSTR_H)
typedef struct mystr{
    char *block; 
    int sz; //keep track of the stting length
    int capacity; //keep track of the size of the block
}mystr;

void create_string(mystr **p_p_s) //send the address of a pointer. Set the pointer to be the address of a valid mystr. 
//presumably, the string is already valid. You don't need to change ht adress of teh string. 
//Q: WHY ARE YOU DOING A POINTER TO A POINTER?
       //YOU WANT TO ACRUALY ALOCATE THE MEMORY SO YOU CAN STORE TEH STR. 
{
    *p_p_s = (mystr *)malloc(sizeof(mystr));
    if (*p_p_s == NULL){
        printf("ERROR: failed to create mystr");
        exit(1);
    }

    (*p_p_s)->capacity = 100;//what you want the initial capacity oto be, adn then you're going to allocate the memory to be of teh next line and then you 're going to make the block contain the empty string and thus have a size of 0 because it's supposed to end with the unll terminator.
    //you're going to allocate teh block. 
    (*p_p_s)->block = (char *)malloc((*p_p_s)->capacity); //you need to store something in there. 
    (*p_p_s)->block[0] = '\0'; //the first blcok in the malloc that you are allocating. 
    (*p_p_s)->sz = 0; 

    //will call using the create_string(&p_s)
    //p_s will get set to a calid mystring. You have to validate it thoguhg. 
}

void set_char(mystr *p_s, int ind, char c)//i think ind means index?
{
    if ((ind >= p_s-> sz)||(ind < 0)){
        print("ERROR: index %d out of bounds \n", ind);
        exit(1);
    }
    (p_s->block)[ind] = c;
}
//want to be able to append

void append_str(mystr*p_s, const char *src)
{
    //why not just use strcat? You might not have enough capacity. We want to make sure there is sufficient capacity. 
    if (p_s -> capacity < p_s->sz + strlen(src)){
        int new_capacity = p_s -> capacity + strlen(src) + 1 *2; // need the null as well. Don't realy ned to multiply by 2 but it's a way of ensuring you're not going to rn out of memory. So oyu don't have to realocate all the time. 
        p_s-> block = (char *)realloc(p_s-> block, new_capacity * sizeof(char));
        //when you have p_sblock realloc, it's going to reallocate memory to that block. It would fre and then allocate and before doing that it will reallocate. 
        //This works. It's either goin tot 
        if (p_s->block == NULL){
            printf("ERROR: string is too large when appending\n");
            exis(1);
        }
        p_s-> capacity = new_capacity;
        p_s -> sz = strlen(src) + p_s->sz; //src and then your old capacity size.
    }
    strcat(p_s->block, src);
}
//change a p_s -> vlock apropriately 
//change p_s -> capacity (possibly)
//change p_s -> sz (possibly)
#endif

//for everything to work, you need to upload al the files. Put them into a folder and then extract them together. 
