#include <stdio.h>
#include <string.h>
#include <stdlib.h>




//Q3: 
void change_a(int *p_a)
{
    *p_a = 43;
}

void change_integer(int **p_p_a)
{
    **p_p_a = 46;
}

void change_int_ptr(int **p_p_a)
{
    *p_p_a = malloc(sizeof(int));
}
void modify_array(int *p_arr) //although it might not be intuitive to write array here when you're literally calling array... 

{
    p_arr[2] = 8;
}

//Q21
typedef struct student{
    char name[1000];
    int age;    
}student;



//Q27: 
void change_student_name(int *p_default)
{
    strcpy(p_default->name, "Jenny");
}

void change_age(int *p_default)
{
    p_default->age = 30;
}
void modifying_pointering(int **p_p_s)
{
    //this is going to take in a pointer to an addresss of a student and is going to set it to point to a new address where a student can be stored. 
    *p_p_s = (student *)malloc(sizeof(student));
}

void change_first_letter(student *p_p_s)
{
    strcpy(p_p_s[2]->name, "Jenny"); //hmm... nvm... maybe my thought processs was a bit incorrect. 
    //this doesn't mean the second letter. It means you have a malloc storing a certain amount of students and you 
    //want the certain student which is at the 2nd index. 
}


void change_name_pt3(student **p_block_addr_s)
{
    strcpy(p_block_addr_s[2]->name, "Jenny")
    //here, what we're trying to do is take in the first address of a student in a block of addresses and change the name of teh student at index 2 to "Jenny?
}

int main()
{//Q1: 
    int a = 42;
//Q2:
    int *p_a = &a;
    change_a(p_a);
    printf("%d\n",a);
    int **p_p_a = &p_a; //since you're pointing to a pointer you need two stars... everytime you increase the amount of things you are pointing to, you need an extra star.
    change_integer(&p_a); //or change_integer(p_p_a);
    change_int_ptr(&p_a);
    change_int_ptr(p_p_a);
    
//Q 15
    int arr[4] = {5,6,7};
    modify_array(&arr);
    //NOTE THAT IF ARR IS AN ARRAY (IN OUR CASE IT IS), &arr would also work here, and arr and &arr are the same thing. But if arr is a pointer, then arr and &arr are different)
    *p_block = (int)malloc(3*sizeof(int));
    modify_array(p_block); //for the array specifically...
    //in this case since you have a pointer, using the & doesn't work... 
    change_integer(p_block); //you're just changing an integer i guess so you don't need the ampsersand in here. Also because *p_block itself is a malloc. It's already kind of global.
    change_int_ptr(&p_block);// here you do need the ampersand becauase you might be creating another malloc and another global variable is almost accessed. 
//Q22
    student default = {"Jenny", 20};
    strcpy(default.name, "Jennifer");
    (default.age  = 21); //don't necessarily need teh brackets. 
    int *p_default = &default;
    strcpy(p_default->name, "Jenny")// OR strcpy((*p_s).name, "Jenny")
    (p_default->age = 22); //or (*p_s).age = 22;
//Q29
    change_student_name(p_default); //since you're using p_s, it's fine if you only use that. 
    change_age(&default); //when you're reverting to looking at teh actual numbers, you need an &. In addresses, you dnn't. 
//Q31
    student classroom[5];
    change_student_name(&(classroom[2]));//or if you want (arr_s +2)
    change_age(&(classroom[2]));
    *p_block_s = (student *)malloc(5*sizeof(student));
//Q35: 
    modifying_pointering(&p_block_s);
    change_student_name(p_block_s + 2); //or (&(p_block_s[2])) because we still need to reference the fact that we're looking at the 2nd index. 
    student **p_p_s = &p_block_s;
    strcpy(((*p_p_s)+2)->name, "Jennifer"); //when you use the arrows, you need to give a pointer arithmetic type of syntax, while when you are using teh . and the array method, you're allowed to use teh type of syntax that you providede. (*p_p_s)[2].name, 'jJennifer
//Q39: THERE ARE APPARENTLY FOUR DIFFERENT WAYS TO DO THIS. 
    ((*(p_p_s))[1]).name[0] = 'j';
    (*p_p_s + 1)->name[0] = 'j';
    (*(*p_p_s +1)).name[0] = 'j';
    p_p_s[0][1].name[0] = 'j';
    
    student **p_block_addrs_s = (student **)malloc(10*sizeof(student *)); //since you're looking at pointers to students. 
//apparently you don't even need a cast in this question. COOL. 
    change_first_letter(p_block_addrs_s);
    change_name_pt3(p_block_addrs_s);
    return 0;
}
