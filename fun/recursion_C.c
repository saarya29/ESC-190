#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void natural_num(int i)
{
    if (i == 51)
    {
        return;
    }
    printf("%d,",i), natural_num(i+1); //YIPPEE
}


int count_digits(int num)
{
    if (num == 0) //i guess it kind of means that there is nothing left. 
    {
        return 1; //special case. 
    }
    if (num < 0)
    {
        num = -num;
    }
    return 1 + count_digits(num/10);
}


int summation(int j)
{
    if (j == 0)
    {
        return 0; //you cannot pass anymore. 
    }
    return j + summation(j - 1); //it didn't say whether in increasing or decreasing order. 
}//you can just go straight to the return statement(s)


int fibonnaci(int n) //how many indexes you want to go up until. 
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonnaci(n-2) + fibonnaci(n-1); //apparently the computer is supposed to be smarter than us, and should know when to start. 
    //in recursion (kind of like python), you work backwards a lot. 
}

int gcd(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
} // this is actually Euclidean algorithm and it works regardless of which ones bigger or smaller than the other because it takes the remainders. I think it's pretty cool. 
int find_largest(int *arr, int max)
{
    if (*arr == '\0') // omg silly syntax errors. plz no make these errors
    {
        return max; // if it's an empty string, it's going to return -1, which also kind of means error. 
    }
    if (*arr > max)
    {
        max = *arr;
        //int *remove_letter = &s[1] //i think, it would kinf of be just like that. 
    }
    return find_largest(arr + 1, max);
}
char *reverse_str(char *str)
{
    int size = strlen(str); //5
    if (size == 0)//you're done..
    {
        return "";
    }
    
    char *string = (char *)malloc(sizeof(char)*(size+1)); //size is going to stay the same. 
    if (!string) {
        return NULL;  // Handle malloc failure
    } //you always need to handle malloc failure!

    //in my malloc, i'd make my second index into my 3rd index etc.

    //BASE CASE: if the length of the string is 1. You return itself. 
    if (size == 1)
    {
        string[0] = str[0];
        string[1] = '\0';
        return string;
    }
    char *reversed_rest = reverse_str(str + 1);//you don't need to do the whole remove-letter thing. 
    strcpy(string, reversed_rest);
    string[size - 1] = str[0];
    string[size] = '\0';

    free(reversed_rest);
    return string;
}

void palindrome(char word[], int index)
{
    int len = strlen(word) - (index + 1); //similar to your logic in the reversed function. It's making length the index of the one opposite to the index of the size we've entreed. 

    if (word[index] == word[len]) //there is a possibility we have a palindrome... otherwise not
    {
        if (index + 1 == len || index == len) //even or odd because if you're near the centre, it kind of confirms then that you are a palindrome and you can return early. 
        {
            return;
        }
        palindrome(word, index + 1); //you need to traverse ahead. 
    }
    else
    {
        printf("The entered word is not a palindome");
    }
}

//I'm sure there was a way you could've done this withouth a whole malloc. 
int main()
{
    int i = 0;
    natural_num(i);
    int j = 5;
    int res = summation(j);
    printf("%d\n",res);
    int k = 20;
    int index = 0;
    fibonnaci(k);
    int a = 18;
    int b = 12; //i know that the gcd = 10;
    int ans = gcd(a,b);
    printf("The gcd of this pair of numbers is %d\n", ans);
    int arr[] = {5,10,15,20,25};
    int max = -1; //assuming all are positive int or zero
    int ans2 = find_largest(arr, max);
    printf("the largest int is %d\n", ans2); //it's being interfered by whatever is in memory. 
    char *summer = "Aarya"; //need Ayraa
    char *rev = reverse_str(summer);
    printf("The reversed string is %s\n", rev);
    return 0;

}