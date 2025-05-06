#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//don't think you need the strucutal definition because you're declaring it in the main function
int alpha_sort(const void *a, const void *b)
{
    return strcmp(((term *)a)->term, ((term *)b)->term);;//hm. should investigate more about this line. 
}

void read_in_terms(term **terms, int *pnterms, char *filename)
{ 
    FILE *file; 
    file = fopen(filename, "r"); // since we made the pointer, and there is no textfile called "filename" we're addressing, we just put filename in directly. 
    char line[200];
//could also have used atoi
    if (!fgets(line, sizeof(line), file)) { // Read first line
        fprintf(stderr, "Error reading file\n"); //stderr means standard error. 
        exit(1);}
    *pnterms=atoi(line); //a way of counting but a simpler way could also just be to use a while loop. 
    //*pnterms = 0;
    //while (fgets(line, sizeof(line), file)) {
    //    (*pnterms)++;
    //}//
    rewind(file); //in hindsight since I'm using the while loop, I don't think I needed this. 
    fgets(line, sizeof(line), file); // Skip the first line again

    *terms = (term *)malloc((*pnterms)*sizeof(term)); //there might be a condition that i need to check here. 
    if (*terms == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); }
    for (int i = 0; i < *pnterms; i++) //add everything into our malloc. 
    {
        char name[200];
        double weight;
        /*while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') //you're going to get a space before the letter. 
        {s
            i++; //iterate through
        }*/
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%lf\t%[^\n]", &weight, name);
            (*terms)[i].weight = weight;
            strcpy((*terms)[i].term, name);
/*another way you could have done this: 
if (fgets(line, sizeof(line), file))
char temp_weight[50] //an arbitrary amount. 
int j = 0;

while line[j] != '\t' && line[j] != '\0' && j <50) {
temp_weight[j] = line[j]; 
j++;
... and then i'm pretty sure when you arrive. you can do the
(*terms)[i].weight = weight;
strcpy((*terms)[i].term, name)}
*/
            //strcpy(terms -> term, &(line[i])); //this is going to make everything into terms, ehere everything is in your malloc, and it's going to behave like a list.
    //take this and shove it in here.
        }
    }

    qsort(*terms, *pnterms, sizeof(term),alpha_sort);
}

int lowest_match(term *terms, int n, char *substr){ /// SHE FINALLY LIVES

int low = 0;
int high = n-1;
//printf("%d\n", high);
int index = -1;

while(low<=high){
int mid = low + (high-low)/2;
int letters = strncmp(terms[mid].term,substr,strlen(substr));
if (letters == 0){
index = mid;
//printf("index %d\n", index);
high = mid - 1;

//printf(" high: %d\n", high);
//printf("index: %d\n", index); 
}else if(letters>0){
high = mid - 1;
}else {
low = mid + 1;
    }
}
    return index; 
}

int highest_match(term *terms, int n, char *substr){

int low = 0;
int high = n-1;
//printf("%d\n", high);
int index = -1;

while(low<=high){
int mid = low + (high-low)/2;
int letters = strncmp(terms[mid].term,substr,strlen(substr));
if (letters == 0){
index = mid;
//printf("index %d\n", index);
low = mid + 1; // checks farther on to see if there are other indicies 

//printf(" high: %d\n", high);
//printf("index: %d\n", index); 
}else if(letters>0){
high = mid - 1;
}else {
low = mid + 1;
    }
}
    return index; 
}

int sort_again(const void* a, const void* b) {
    double comparison = ((const term*)a)->weight - ((const term*)b)->weight;
    return (comparison < 0) - (comparison > 0);
    //this is just another way of typing... if deff is negative <0, return -1, else, return 1... if they're the same return 0. 
}
void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr)
{
  
  int start = lowest_match(terms, nterms, substr);
  int stop = highest_match(terms,  nterms, substr);
  
  *n_answer = stop - start + 1;
  *answer = (term*)malloc(sizeof(term)*(*n_answer));
  if (!*answer){
    exit(1);
  }
  if (*n_answer ==1)
  {
    strcpy((*answer)[0].term, terms[start].term);
    (*answer)[0].weight=terms[start].weight;
  }
  else
  {
    for (int i = start; i <= stop; i++) {
    strcpy((*answer)[i-start].term, terms[i].term);
    (*answer)[i-start].weight = terms[i].weight;
    (*answer)[i-start].term[strlen(terms[i].term)] = '\0';}
  }

qsort(*answer, *n_answer, sizeof(term),sort_again);}




