#if !defined(matrix_h)
#define matrix_h 

#include <stdlib.h>
#include <stdint.h>

typedef struct matrix{
    size_t row; 
    size_t columns;
    int **element;  //it needs to be a pointer to a 2D array. Not sure why?
}
// afterwards, you might need to define the actual calls in here so it works. 
#endif