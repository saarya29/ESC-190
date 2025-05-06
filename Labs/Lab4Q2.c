#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double my_atof(const char *str) // you want to return a double... there are many operations that you might have to consider. Remember that.
{// takes in a pointer, so I'm pretty sure it's only going to look at the first value?
    int negative = 1; double  fraction = 0.0; 
    int res = 0; double iterator = 0.1; int i = 0;
    if (!isdigit(str[i])) //most likely will be... just for clarification? 
        {
            if (str[i] == '-') //Negative = True
            {
                negative = -1;
                i++;
            }
            else if (*str == '.')
            {
                fraction = 1;
                i++;
            }
        }
    else if (fraction == 1) //need to use atof here.
        {
            while (str[i] != '\0')// a good way to know you're at the end of a string. i think better than python. 
            {
                res = res*10 +str[i] -'0'; //whenever you have to iterate through characters in C, you go by their memory sizes i think (bits) and characters it's 10. 
                i++;
                if (fraction == 1)
                {
                    res += str[i]*0.1;
                    iterator/10;
                    i++;
                }
                return res*negative;
            }
        }
}

int main()
{
    char line[100]; 
    char *p_buffer = line;
    FILE *open_file = fopen("integers", "r");
    char *caller; 
    double summation=0.0;
    while(fgets(line, sizeof(line), open_file))
    {
        while (*p_buffer && *p_buffer != '='){
            p_buffer ++;
            }
        if (*p_buffer == '=')
            {
                caller = (*p_buffer + 1); //get rid of the space...
            }
        summation = myatof(caller);
    }
    fclose(open_file);
    return 0;  
}
//you cannot declare things inside your while or if loops if you plan on using it afterwards. 