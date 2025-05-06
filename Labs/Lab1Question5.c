#include <stdio.h>
//3 ways to solve the same problem. 
void find_min_max(char arr[],int size, char **min, char **max)
{
    *min = arr;
    *max = arr;

    for (int i = 1;i<size;i++)
    {
        if (arr[i] < **min)
        {
            *min = &arr[i];
        }
        if (arr[i]> **max) //realize that if you had the equal sign, it would have given you -14. This is because of what characters you are dereferencing twice... you only need to be including it once. 
        {
            *max = &arr[i]; //you're looking at the pointer of the pointers. 
        }
    }
}


/*int main() // need to return an integer.. logic is subtract the highest from lowest of the addresses. Can add into a list and get the min and max?
{
    char arr[] = "United States of America";
    int size = sizeof(arr)/sizeof(arr[0]);
    char *min,*max;
    find_min_max(arr,size,&min,&max);
    int length = (max - min); // you don't write int max or int min because then you're subtracting their types which is not possible. You need it to declare what type of item you are initially dealing wit. Not afterwards
    printf("Length string: %d\n",-length); //i realized that due to the addresses, it produces a negative value all the time. 
    return 0;
}*/

// this however, is not a fullproof method because you might not always have your addresses in a sorted order and what if you have multiple of the same characters. 
//withouth using strlen, this is a potential option. 

/*int main()
{
    char *s = "hello";
    s + 1;
    int ans = *(s+1);
    printf("%c\n",ans); // remember you're trying to print the actual character, not an integer... that will print something random.hmm to find the count, i thin you could also implement this logic and use a count feature. 
    return 0;
}*/


/*int main()
{
    char arr[] = "United States of America"; //21
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("The length is: %d\n",(length-1));
    return 0;*/

// there is a small issue with this execution:f the string is "Aarya", it actually occupies 6 bytes:
//5 bytes for the characters 'A', 'a', 'r', 'y', 'a'
//1 byte for the null terminator (\0) .. can avoid this by simply -1*/

int main()
{
    int count = 0;
    char *s = "parvaresh"; //this will only look at the first character
    int size = sizeof(s)/sizeof(s[0]); //i'm pretty sure this logic would still work.
    for (int i = 0; i <= 8; i++)
    {
        int ans = *(s + i);
        printf("%c\n",ans); // hopefully this works but keep in mind that ans is an int rn. 
        count ++;
    }
    printf("%d\n",count);
    return 0;
}

//i'm just confused why does it stop at the fifth letter in this case... i feel like this is also not the best approach. 