#include "autocomplete.h"
#include "autocomplete.c"//not sure if really necessary? Might get rid of if not needed. 

int main()
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");
    lowest_match(terms, nterms, "Tor");
    highest_match(terms, nterms, "Tor");
    
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocaks here -- not required for the project, but good practice
    free(terms);
    return 0;
}
