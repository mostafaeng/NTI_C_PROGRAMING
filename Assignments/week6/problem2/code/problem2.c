#include<stdio.h>
#include<stdlib.h>

int *Fibonacci_series(unsigned int num_of_elem);
int main(){
    printf("\n\n");
  int*F_series = Fibonacci_series(10);
  for(int i = 0; i<10; i++){
    printf("%d  ",F_series[i]);
  }

    return 0;
}

int *Fibonacci_series(unsigned int num_of_elem){

unsigned int counter;
int *ret_series;
ret_series = (int *)calloc(num_of_elem,sizeof(int));
ret_series[0] = 0;
ret_series[1] = 1;

for(counter = 2; counter<num_of_elem; counter++)
{
      ret_series[counter] = ret_series[counter-1] + ret_series[counter-2];
}

return ret_series;

}