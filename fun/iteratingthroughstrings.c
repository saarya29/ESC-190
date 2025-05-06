#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    char *newStr = &str[1]; // Point to the second character
    printf("Original string: %s\n", str);
    printf("Modified string: %s\n", newStr);
    return 0;
}