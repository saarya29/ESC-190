#include <ctype.h>
#include <stdio.h>
int my_atoi(char *s)
{
    /*if (s == '\0')
    {
        return 0;//kind of like in python, am I allowed to return a variable value or does it need to be an integer in this case because I defined this to be an integer. 
    }
    
    int first = *s-'0';
    int *remove_letter = &s[1];
    return first, my_atoi(remove_letter);
should ask more about this logic*/
int i = 0;
int res = 0; // i first did it withouth this and it didn't work because you need something to initialize/add to. 
    while (s[i] != '\0')// a good way to know you're at the end of a string. i think better than python. 
    {
        res = res*10 +s[i] -'0'; //whenever you have to iterate through characters in C, you go by their memory sizes i think (bits) and characters it's 10. 
        i++;
    }
    return res;
}
int main() 
{
    char *s = "950";

    // Check if the given input is a digit or not
    if (isdigit(*s))
    {
        //altogether it can assess this is a digit. 
        printf("%s is a Number\n", s);
        int results = my_atoi(s);
        printf("%d",results);
    } 
    else
        printf("%s is NOT A Number", s);
  
    return 0;
}