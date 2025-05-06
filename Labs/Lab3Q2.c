#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//having the typedef allows you to usestudent1 directly as a type instead of writing struct student1 everytime.
typedef struct student1 //struct student1 is the structure definition. It groups related pieces of data, making it easier to manage entities like "a student."
{
    char name[200];
    char student_number[11]; // i think the reason we used the [11] here is to account for the null character but I am a bit confused because why does it actually allow me to take in 11 integers. 
    int year;
    //you need to declare what these values are. 
} student1; // the student1 at the end is necessary because it serves as a type alias created by the typedef keyword. I guess it's convention and therefore I must follow. 
// fyi this isn't the main function... you need that to specify who your person truly is. 


int print_names(student1 student)
{
    printf("Name: %s\n", student.name); // because these two, as defined are strings. 
    printf("Student Number: %s\n", student.student_number);
    printf("Year: %d\n", student.year);
    return 0;
}
void set_default_name(student1 *p_s)
{
    strcpy(p_s->name, "Aarya Shah"); // i think this is wrong. 
    // if I didn't have this, then it would still kind of work in the sense that it would just print out the p_s value but that's not really the purpose of the assignment ( i think)
    //printf("Default Student:%s\n",p_s->name);
    // when you want to set something, you add ->
    // suppose you wanted to print the pointer address. Not too sure why: 
    //printf("Pointer Address: %p\n", (void *)p_s);
    strcpy(p_s->student_number, "10001000100");
    p_s->year,0;
}

void create_block1(student1 **p_p_s, int n_students) //whenever you have a global variable, you want to add another layer of pointers. With this, you're going to be able to access the memory. 
{
    *p_p_s = (student1 *)malloc(n_students*sizeof (student1)); //malloc ALWAYS finds space on the heap. HEAP is permanent
    //a pointer is basically an integer. You want to chage the value of 1000 to 2000 inside the function that creates an array. This create an array of student1s
    //You have to make a pointer to p_s. Which is a p_p_s
    //you're making a pointer that's pointing to it. Therefore, you only need one star.  You need to change where the pointer points to, which is  why you need a double pointer  
}
//Question 5:
void set_name(student1 *p_p_s, char *namings) // not sure i'm understanding this properly
{
    //my understanding is that it can go through the malloc and do basically what set_default_name does. 
    strcpy(p_p_s->name,namings); // going to point to the first thing in the arrray and then going to call it 
    //printf("Second Name:%s\n",p_p_s->name);
}

//Question 6
void destroy_block(student1 *p_s)
{
    free(p_s);
}
// you should always free your malloc block or it causes data leaks. It's like the only thing you can do with a malloc. 

//Questoin 7
// what makes this different (i think) is that it points to the name, rather than using string I think
typedef struct student2{
char *name;
char *student_number; // this is an adress type. You can't just free an address type. 
int year;
} student2;

void create_block2(student2 **p_p_s, int num_students)
{
    *p_p_s = (student2 *)malloc(num_students*sizeof (student2)); // you want everything in the block to be 0. Need a for loop
    for (int i = 0; i < num_students; i++)
    {
        (*p_p_s)[i].name = 0; // remember that we're looking at the pointer, and so it's going to save the address to the value to be 0. Also because student number and name are both addresses I think
        (*p_p_s)[i].student_number = 0;
    }
}

//Question8. Basically the same as set_name 1 i think. 
void set_name2(student2 *p_p_s, char *name) // 
{
    //since it's a pointer type, if you wanted to change something, you have to make a new block of memory using malloc and then if you change the things in the malloc, it's what you did with the array, except you have to free it later.
    p_p_s -> name = (char*)malloc(strlen(name)+1); // you want to create memory in the array based on the amount of memory needed to store the name. This is why you use strlen. It's the equivalent of doing sizeof arr
    strcpy(p_p_s->name,name); //it's going to add the name into the block memory. I think you still need the 'NULL' character so you're going to add that in. 
    *((p_p_s->name)+strlen(name)) = '\0';
}

// QUESTION 9;
void destroy_block2(student2 *p_p_s, int num) // we need to free up memory but because everything is in terms of pointers, you're going to need to free things using a for loop
{ // num's going to have to be the size of the block of malloc that you're going to need cleared. 
    for (int i = 0; i < num; i++)
    {
        free(p_p_s[i].name); // you clear one trash can
        free(p_p_s[i].student_number); // you clear another trash can
    }
    free(p_p_s); // and then the whole trash can gets put in the garbage truck
}

//QUESTION 10: THE PURPOSE OF THIS IS TO KNOW THE DIFFERENCE BETWEEN STUDENT_BLOCK1 AND STUDENT_BLOCK2 IS THAT STUDENT1 HAS AN EFFECT OUTSIDE THE FUNCTION WHEREAS STUDENT2 DOES NOT. 
void modify_student1(student1* p_s) // i'll be honest, i'm not too sure I know if my variables are correct. 
{
    strcpy(p_s->name, "Modified Student Name"); //whenever you have a pointer 
}

void modify_student2(student2 *p_p_s)
{
    strcpy(p_p_s.name, "Another Modified Student");
}
int main()
{
    //you must declare that you are going to use the structure student1 from before. 
    student1 student; // this is just one block of student 
 // Copy the student number
    student.year = 1; // Assign the year
/* the reason you need to use strcopy is because you cannot directly assign student.name[200] = {"your name"}. You have to use strcopy to copy the string into an array. */
    
    set_default_name(&student);
    print_names(student);
    // you don't want to write set_default_name(*student.name); because you have a string (name) but in doing the pointer, you're only passing a character. Remember how the * only points to the first element in the array. To get it to point to all of student1, you pass the ADDRESS OF STUDENT!!
    // recall how the * and the & have to/should be together. 

    //Question 4: 
    //struct is the same as primitive types (memory wise, very similar. If we want to have an array of something, it's the equivalent to having a pointer of sometihng)
    student1 *students; // you're creating a place that can store different students here. 
    create_block1(&students,5); // since the function requires me to call **, and I have initialized student to *student, I need the & to get the **. This is similar to what I did in Question 3. 
    
    //Question 5. You want to set a name to something you have in block 2. 
    char *namings = "AREAYYY";
    char *namings2 = "ARYAYAY";
    set_name(&students[1], namings);
    set_name(&students[2], namings2);
    printf("Classmate Name: %s\n", students[1].name);
    printf("Another Classmate: %s\n", students[2].name); 
    //you must have a pointer when you need an array or else you don't know how long it is. 


    //QUESTION 10 STUFF:
    student1 *student3; 
    char *name = "ARYAYAY";
    set_name(&student3[1], name);
    printf("Another Classmate: %s\n", student3[1].name);
    modify_student1(student3);

    student2 *student4;
    char *name2 = "AAAAAAAAAAAAAA";
    set_name2(&student4[1], name2);
    printf("Who Are You: %s\n", student4[1].name);
    modify_student2(*student4);
    return 0;
}