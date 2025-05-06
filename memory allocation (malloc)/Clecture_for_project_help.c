#include <stdio.h>

struct student1{
    char name[200];
    double gpa;
}student1

struct student2{
    char *name; //contains an address and a number
    double gpa;
};

void create_student1(struct student1, **p_p_s1, const char *name, double gpa)



//stuedent2; 
//1032 [name: 283759332     gap: -2.5]
//*p_p_s1 : 1032
        //          not a valid address (because it is a random address. )
        //THIS WASN'T A PROBLEM BEFORE BECAUSE YOU DIDN'T HAVE THE NUMBER. You just had memory and space allocated for whatever you wanted it to be. In student2, you have a number and so it needs to be a valid number. 
        // not a problem: we're about to copy local gpa to (*P_p_s1)-> gpa. 
// I cannot currently go ((*p_p_s1)-> name)[0] = 'x

void create_student2(struct student2 **p_p_s1, const char *name, double gpa)
{
    *p_p_s1 = (struct student2*)malloc(sizeof(struct student2)); // this would crash
    //(*p_p_s1) -> name is not initialized (some random number)
        //problem: cnannot write to the random address (*p_p_s1)-> name
        //(*p_p_s1) -> gpa. Also not initializes (some ranndom number). This is not a problem. We're about ot copy local gpa to (*p_p_s1)

}



void create_student_fixed(struct studen2 **p_p_s1, const char *name, double gpa)
{
    *p_p_s1 = (struct student2*)malloc(sizeof(struct student2));
    (*p_p_s1) -> name = (char *)malloc(sizeof(char) * (strlen(name)+1));
    strcpy((*p_p_))
}
{
    *p_p_s1 = (struct student1*)malloc(sizeof(struct student1));
    strcpy((*p_p_s1)->name, name); // you need to parenthesize the *p_p_s1. i// the arrao is the same as (*p-s1)
}

int main()
{
    struct student1 *p_s1; //p_s1 -> name the same way you say *p_p_s name...
    create_student1(&p_s1);
}

//if you use struct student1 s1; s1.name. Use when you have the actual object (not a pointer). You would want to use the arrow when you have a pointer. 
//