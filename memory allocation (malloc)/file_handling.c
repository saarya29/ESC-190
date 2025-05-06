#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b) {
    return strcmp(((term *)a)->term, ((term *)b)->term);
}

void read_in_terms(term **terms, int *pnterms, char *filename){
    FILE *file =fopen(filename, "r");
    
    char line[200];
    
    //get first line fo code
    fgets(line, sizeof(line), file); 
    *pnterms=atoi(line);

    *terms = (term *)malloc(sizeof(term)*(*pnterms));
    if (!*terms){
        exit(1);
    }
    
    for(int i =0;i<*pnterms;i++){
        double weight;
        char name[200];
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%lf\t%[^\n]", &weight, name);

            (*terms)[i].weight = weight;
            strcpy((*terms)[i].term, name);  // Copy the term properly
        }
    }
    qsort(*terms, *pnterms, sizeof(term), compare);
}

int alpha_sort(const void *a, const void *b)
{
    return strcmp(((term *)a)->term, ((term *)b)->term);;//hm. should investigate more about this line. 
}

void read_in_terms(term **terms, int *pnterms, char *filename)
{
    int count = 0;// this is going to be the numbers    
    FILE *file; int i; int nterm = 0;
    file = fopen(filename, "r"); // since we made the pointer, and there is no textfile called "filename" we're addressing, we just put filename in directly. 
    char line[200];
    double weight;

    while (fgets(line, sizeof(line), file)){//((ch = fgetc(fp))!= EOF){ //it's fgetc not fgets... also this is inpractical approach, reading by character. 
            printf("%s", line);
            nterm ++;}//i feel like we don't need this part. 

    *terms = (term *)malloc(nterm*sizeof(term));

    for (i = 0; i < nterm; i++) //add everything into our malloc. 
    {
        char name[200];
        while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') //you're going to get a space before the letter. 
        {
            i++; //iterate through
        }
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%lf\t%[^\n]", &weight, name);
            (*terms)[i].weight = weight;
            strcpy((*terms)[i].term, name);
            //strcpy(terms -> term, &(line[i])); //this is going to make everything into terms, ehere everything is in your malloc, and it's going to behave like a list.
    //take this and shove it in here.
        }
    
    }
    qsort(*terms, nterm, sizeof(term),alpha_sort);
    fclose(file);
}