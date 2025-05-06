#include <stdio.h>

char *strcat_rec(char *dest, char *src) //the only problem with this approach is that you're not going to return dest, you're going to return concat. 

/*{
    if (dest[0] == '\0')
    {
        if (src[0] == '\0')
        {
            return concat;
        }
        *char concat -> src[0] = (char *)malloc(sizeof(char)*1);
        strcat_rec(dest, src + 1)
    }
    else{
        *char concat -> dest[0] = (char *)malloc(sizeof(char)*1);
        strcat_rec(dest + 1, src);
    }
}*/
char *strc_concatenate(char *dest, char *src)
{
    if (dest[0] == '\0')
    {
        if (src[0] == '\0')
        {
            return dest;
        }
        dest[0] = src[0]; //dest * = src *
        dest[1] = '\0';//*(dest + 1) = '\0'. It's better to use pointers when your argument is kind of like a pointer If you're iterating through a loop, [0] feels more intuitive. 
        strc_concatenate(dest + 1, src + 1);
    }
    else{
        strc_concatenate(dest + 1, src);
    }
    return dest;
}