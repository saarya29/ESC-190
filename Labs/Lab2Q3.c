#include <stdio.h>
#include <string.h>
// first version = using an index
int my_strcmp_rec(char *s1, char *s2) // because you're going to have to return a value and C is doing critical analysis here, you can't have a void... you need an int. 
{
    ;
    if (s1[0] == '\0'&& s2[0] == '\0')//BASE CASE
    {
        return 0; //similar to python i guess. 1 means not the same. 
    }
    else
    {
        if (*s1 == *s2) // the first pointers are equal meaning the first elements are equal. 
        {
            char *remove_letter1 = &s1[1]; //you're kind of removing that letter so your first element becomes somethig else. 
            char *remove_letter2 = &s2[1];
            return my_strcmp_rec(remove_letter1, remove_letter2);
        }
        else
        {
            return 1;
        }
    }
    
    
   /* for (int i = 0; i <size1; i++)
    {
        if (s1[i] != s2[i]) //same index but you're comparing the values in both strings at that point
            {
                //printf("Your two strings are not equal"); //Q: WHY DOES THIS NOT WORK??
                return 1;
            }
    }
    //printf("Your strings are equal"); //AND HERE AS WELL. 
    return 0;*/
}

int main()
{
    char *s1 = "Aarya"; // checked: it doesn't matter if you do this or char s1[]
    char *s2 = "Aarya"; 

    my_strcmp_rec(s1,s2);
    printf("This is your first string: %s\n",s1);
    printf("This is your second string: %s\n",s2);
    // if you want to make a declaration based on what you got before:
    if (my_strcmp_rec(s1,s2) == 0)
    {
        printf("Your strings are the same!");
    }
    else
    {
        printf("Your strings are not the same");
    }
    
    return 0;
}