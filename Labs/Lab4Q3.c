#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//safer to use char * f you want to accomodate words that are much longer. Also can use strcpy and that's the python equivalent of changing a list. 

typedef struct student1{ //structure is an array... kind of like a list. 
    char name[];
    int age;
}student1; //you're going to need a semicolon here too. 

void change_name1(student1 *p_s)
{
    p_s ->name[0] = 'b';
}

int main()
{
    student1 s = {"el", 20};
    //s.name[0] = 'e';//l";
    strcpy(s.name, "el");
    s.age = 20;
    return 0;
}