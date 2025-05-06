#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat_all(char **strs, int strs_sz0)
{
    //recognize that strs_sz0 tells you the number of strings but 
    // notht the size of all the strings. You cannot malloc unless 
    // you have the size of all the strings together (unless you want to realloc)
    //1. Compute total length:
    int total_len = 0;
    for (int i = 0; i < strs_sz0; i++){
        total_len += strlen(strs[i]);}
    //2. allocate memory ( + 1 for terminator) whenever you have a string. 
    char *result = (char *)malloc(total_len + 1);
    if (result == NULL){
        exit(1);}
// you cannot create somehting just like string = "" because strings and actual lists are immutable so you cannot change them whereas in python you can I blieve. 
// you need to create a buffer variable in a way.
    result[0] = '\0';
    for (int i = 0; i < strs_sz0; i++){
        strcat(result, strs[i]);}
    return result;}



int main()
{
    char *strs[] = {"ESC", "MAT", "MSE", "CIV"};
    char *result = concat_all(strs, 4);
    printf("%s\n", result); // ESCMATMSECIV
    free(result); // always free malloc'd memory
    return 0;
}
//will have to free concat later in my int block, but does this 
//make any sense?
