#include <stdio.h>

typedef struct student{
    char name[17];
    double GPA; // the GPA being a double has 8 spaces. 
} student;

typedef struct student1{
    char name[16];
    double GPA; //not 100% sure why but it doubles the double so now it's 216. But roughly the same. 
} student1;

int main()
{
    printf("%d\n%d\n", sizeof(student),sizeof(student1));
    return 0;
    student s = {"Alice", 3.9};
    student s1 = {"Bob",3.93};
//the last name address digit is going to be just before the size/amount of the GPA because C is going to store them together. 
}

//malloc = function returns the address of a block where you can write to the memory. A memory that doesn't go away and you can allocate how much memroy you want for it. 


student1 make_student1(char *name, double gpa)
{
    student1 s1; 
    s1.name = (char*)malloc(strlen(name)+1);
    strcpy(s1.name, name);
    s1.gpa = gpa; 
    return s1;
}