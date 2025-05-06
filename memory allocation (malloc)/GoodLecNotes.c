#include <stdio.h>
#include <stdlib.h>

typedef struct student22{
    char name[1000];
    int age;
    } student22;


int main()
{
    student22 students[5];
    //want to change the name/age of student[2]
    change_age(&(student[2]),45);
    change_name(&(student[2]), "Alice");
    //another way you can do this: 
    change_age(students + 2, 45); //the addres of students + 2, gives you student[2]. It's like arr* = arr[0] but we nded the second student 
    change_name(students + 2, "Alice");
    //ar[2] is syntactic sugar for *(arr +2)
    //&(arr[2] is arr + 2)
    //because *(&(arr[2] is arr[2]))
}
    //Q22
    int main1()
    {
        student22 s = {"Roger",41};
        //s.name = "Jennifer;" not posible you'd have to initialize it. 
        strcpy(s.name, "Jennifer"); // right here you made your array long enough such that it was able to make jennifer's name fit. However, it we had only made it such that Roger's name fits.then you may or may not crash if you try to change the name to jennifer. You'd have to reallocate space using a maloc. You canot change the size of an aray once it's ben set in your struct   } 
        //manual copy
        char *str = "Jennifer";
        int i = 0;
        while(*src){
            (s.name)[i] = *src; 
            src++;
            i++;
            //more efficient way = (s.name)[i++] = *src++;
        }
        s.age = 21;

        //Q24Creating a pointer to the student to address of the student
        student22 *p_s = &s;
        //Q25. Change the name of the student to "Jenny"
        strcpy((*p_s).name, "Jenny");
        strcpy(p_s -> name, "Jeny");
        }
        //Q26: 
        p_s-> age = 20; //the reason you don't have to add the strcpy is because you're dealing with an int here, not a string. 
        //however, numbers and text work in the same way./ 

        //Q27: 
        void change_name(student22 *p_s, char *name)
        {
            strcpy(p_s -> name, name);
        }

        //*name is the same as name[0]. Those are of type char. Strcpy expects char*. 
        //name[0] might cause a crash 
        //can say (p-> name)[0] = 'a' is fine. 
        //Because Alice is defined as a literal, canot modify its contents
        
