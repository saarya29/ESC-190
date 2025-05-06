#include <stdio.h>
/*
int main()
{
    char *s = "hellor";
    s + 1;
    int ans = *(s+1);
    printf("%c\n",ans); // remember you're trying to print the actual character, not an integer... that will print something random.hmm to find the count, i thin you could also implement this logic and use a count feature. 
    return 0;
}
*/
/*
int main()
{
    char arr[] = "Aarya"; //21
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("The length is: %d\n",(length-1));
    return 0;
}
/* there is a small issue with this execution:f the string is "Aarya", it actually occupies 6 bytes:
5 bytes for the characters 'A', 'a', 'r', 'y', 'a'
1 byte for the null terminator (\0) .. can avoid this by simply -1*/

/*int main()
{
    int count = 0;
    char *s = "Aarya"; //this will only look at the first character
    int size = sizeof(s)/sizeof(s[0]); //i'm pretty sure this logic would still work.
    printf("%c",*s);
    /*for (int i = 0; i <= size; i++)
    {
        /*int ans = *(s + i);
        printf("%c\n",ans); // hopefully this works but keep in mind that ans is an int rn. 
        count ++; *
    }
    printf("%d\n",count); */
    //return 0; } */

int main()
{
    int arr[] = {6,7,8};
    printf("%p\n",arr + 1);
    printf("%ld\n",arr);
    printf("%ld",arr); // missed what he wrote :()
    return 0;
}


// in pointer arithmetic, C knows how much to increment by based on what you are working with. For example, in a string, when you do s + i (it will icrement by 1 because characters increment by 1, whereas in integers, the bytes are by 4, but they still know when you increment by 1, C will know to go by 4 to the next integer. )