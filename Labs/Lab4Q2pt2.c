#include <stdio.h>
#include <ctype.h>

double my_atof(const char *str) {
    int i = 0, negative = 1;
    double res = 0.0, fraction = 0.0, iterator = 0.1;
    int is_fraction = 0;

    // Check for negative sign
    if (str[i] == '-') {
        negative = -1;
        i++;
    }

    // Process integer and fractional part
    while (str[i] != '\0') {
        if (str[i] == '.') {
            is_fraction = 1;
            i++;
            continue;
        }
        if (!isdigit(str[i])) break; // Stop on non-numeric characters

        if (!is_fraction) {
            res = res * 10 + (str[i] - '0'); // Integer part
        } else {
            fraction += (str[i] - '0') * iterator;
            iterator /= 10.0;
        }
        i++;
    }

    return (res + fraction) * negative;
}

int main() {
    char line[100];
    FILE *open_file = fopen("integers.txt", "r");
    if (!open_file) {
        printf("Error opening file.\n");
        return 1;
    }

    double summation = 0.0;
    while (fgets(line, sizeof(line), open_file)) {
        char *p_buffer = line;

        // Find '='
        while (*p_buffer && *p_buffer != '=') {
            p_buffer++;
        }

        if (*p_buffer == '=') {
            p_buffer++; // Move past '='
            while (*p_buffer == ' ') p_buffer++; // Skip spaces
            summation += my_atof(p_buffer);
        }
    }

    fclose(open_file);
    printf("Total sum: %f\n", summation);
    return 0;
}
