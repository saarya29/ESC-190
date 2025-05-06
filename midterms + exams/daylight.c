#include <stdio.h>

typedef struct daylight {
    int hours;
    int minutes;
}daylight; 

void create_daylight_pt_block(struct daylight ***block, int *data, int n)
{
  *block = (daylight **)malloc((n/2)*sizeof(daylight *));
  
  for (int i = 0; i < n/2; i ++)
  {
    (*block)[i] = (struct daylight *)malloc(sizeof(struct daylight));
    (*block)[i]->hours = data[2*i]; //takes all the hours
    (*block)[i]->minutes = data[2*i +1]; //it takes all the afterones as teh minutes. Makes sense. 
  }
}

int main()
{
  struct daylight **daylight_block;
  int data[] = {11, 29, 12, 9}; //the times that was provided by us.
  int n = 4;
  create_daylight_pt_block(&daylight_block, data, n);
  printf("%d %d\n", time[1]->hours, time[1]->minutes);
  free(time[0]);
  free(time[1])
  free(time); //apparently it's better to free them in out main function in this case. 
}