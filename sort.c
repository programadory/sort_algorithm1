/*
* Sort Algorithm by @yagami 
* Complexity time O(n log n) ;-;
* 2024 v1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int complexitychecker=0;

void* sort(int unsorted_list[], const int list_end){
  
  int mover, swap, pivot, pointer, pointer_limit = (list_end-1);
  
  for(pointer=0; pointer < pointer_limit; pointer++)
  {
    for(mover=pointer+1; mover < list_end; mover++)
    {
      if( !(unsorted_list[pointer] < unsorted_list[mover]) )
      {
        if(mover==1)
        {
          swap = unsorted_list[mover];
          unsorted_list[mover] = unsorted_list[pointer];
          unsorted_list[pointer] = swap; 
        }
        else
        {
          swap = unsorted_list[mover];
          pivot = unsorted_list[pointer+1];
          unsorted_list[mover] = pivot;
          unsorted_list[pointer+1] = unsorted_list[pointer];
          unsorted_list[pointer] = swap;
        }
      } 
    }
  }
  return unsorted_list;
}

int main(void){
  
  srand(time(NULL));
  int unsorted[20];
  for(int gen=0; gen<20; unsorted[gen]=rand()%120, gen++);
  
  for(int i=0; i<20; i++){
    printf("%d, ", unsorted[i]);
  }

  printf("\n\nPress enter to sort it!\n");
  getchar();
  
  sort(unsorted, 20);
  
  for(int i=0; i<20; i++){
    printf("%d, ", unsorted[i]);
  }
  printf("\n");
  
  return 0;
}