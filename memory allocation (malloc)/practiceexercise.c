#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Q11: 
void change_to_int(int **p_p_a)//pointer to pointer needs two stars
{
    *p_p_a = malloc(sizeof(p_p_a));
    //you don't always ned something to start off
    free(p_p_a);
}

void change_integer(int **p_p_a)
{
    **p_p_a = 46;
}

void change_array(int *p_arr)//it's going to take the array and since we're going to make the pointer the argument, it's going to point at one thing instead of everything 
{
    p_arr[2] = 8;
    //or a "slightly better way *(p_arr + 2) = 8"
}

//Q21
typedef struct student{
    char name[1000];
    int age;
}student;//need teh student in the end. 

void change_name(student *p_s)
{
    strcpy(p_s->name, "Jenny");
    //in this case, you'd want to use the "mapping technique. "
    //strcpy((*p_s).name, "Jenny");
}




int main()
{
    int a = 43;
    int *p_a = &a;
    int *p_p_a = &p_a; //hmm should ask if this is correct
    change_to_int(&p_a);//when you want to change the value of p_a to point to a new address without using p_p_a
    change_to_int(p_p_a); //another way of writing i think?
    change_int(&p_a);

    int arr[4] = {5,6,7};
    change_array(arr); //i forget. Do you take this whole thing or just one element?
    //in array, saying (arr) and (&arr) is the same (not a pointer returned by malloc)
    //in pointers, (arr) and (&arr) are not the same thing

    int *p_block = malloc(3 * sizeof(int));
    change_array(p_block); // this would technically change the value of the second index in the malloc.
    //suppose you wanted to use change_integer to change the value of the integer stored in the block of memory, you can just do:
    change_integer(p_block); //although p_block is a pointer to the malloc
    
    //qUESTION 21-23
    student s = {"Jenny", 20};
    s.age = 20;
    //Q24: 
    student *p_s = &s; //asked for the address of the student, not teh name
    //change_integer(s.age); are these two lines valid?
    //printf("%d\n",s.age);
    strcpy(p_s->name, "Jenny"); //(or use strcpy((*p_s).name,"Jenny")
    (p_s->age, 20); 
    change_name(&s);
    return 0;
}