#include <stdio.h>

//NOTE: when arrays are used, they are gnerally converted to the pointer of the first element

double sum(double x, double y) //don't need a semicolon in function declaration.
{
    return x + y;
}
void change_a(int *p_a)
{
    *p_a = 44;
}
int main()
{
    int a = 42;
    //printf("%d\n",a); //need to save to show problems
    int *p_a = &a; // p_a is the address of a
    change_a(p_a); // change the value at p_a... a is now 44
//Q: how would u print something like this though?

    double s = sum(1.2,3.4);
    printf("%ld\n",s);

    char *str = "hello!";
    printf("%s is stored at the address %ld",str, str);

    int arr[] = {5,6,7};
    printf("%d\n",arr[0]); //5.
    printf("%ld\n",arr); //address of 5.

    printf("%d\n",*arr); //*arr is the same as arr[0]
//Q: what's the difference bw square brackets + "*"

    char *str2 = "hellos";
    printf("%c\n",str[0]);
    printf("%c\n",*str2);
    printf("%c\n",*(str2+0));
//casting = convertint b/w types
//in quotes because it does the same thing sa
//printf with the wrong type; interpret the data as if it were in the type I say
//(int) 1.2 --> 1 
//(long int)str: just the address of the first element of str
}

//RULES LEARNT: 
    //int* stores the address of an integer
    //*p_a means the value at address p_a
    //&a means the address of a
    // your copy the value to the local variable from the function call
    //arr[0] is the same as *arr