#include "mystr.h"
#include <stdio.h>

int main()
{
    mystr *p_s;
    create_string(&p_s); //p_s is now a valid pointer to an empty mystr. 
    append_str(p_s, "hi");
    printf("The string is: %s\n", p_s->block);
    append_str(p_s, "hello");
    printf("The string is: %s\n", p_s->block);
}