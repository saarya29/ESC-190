#include <stdio.h>

void func1(int a)
{
    a = 10;
    printf("%d\n",a);
}

void change_array(char arr[]) //similar to void func1
{
    arr[0] = 'A'; //char = '', not ""
}  
int main()
{
    int f = 5;
    func1(f); //you need to call this function because all your initialization needs to happen somewhere.. thinking back to main blocks in python.

    char arr[100] = "hello, my name is Aarya";//an array that can hold man 100 characters.
    printf("Before: %s\n",arr);
    change_array(arr);
    printf("After: %s\n",arr);
    return 0; //whenever it's not a void... need return. 
} 
/* meanwhile in Python:
def char_arrays(string):
    if len(string) <= 100: #i guess a max base case it can look through
        new_string = "A" + string[1:]
        print(new_string)
        return new_string
    
string = "hello my name is Aarya"
print(char_arrays(string))*/

