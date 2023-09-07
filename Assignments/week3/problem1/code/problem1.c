#include<stdio.h>

char check_if_perfect_number(unsigned int num);
int main(){

unsigned int num1;
unsigned int num2;
  printf("\n\nEnter two to find perfect numbers between them: ");
  scanf("%d%d",&num1,&num2);

  for(int counter = num1; counter<=num2; counter++)
  {
       if(check_if_perfect_number(counter))
       {
            printf("%d  ",counter);
       }
  }

    return 0;
}

char check_if_perfect_number(unsigned int num){
   
    unsigned int counter;
    unsigned int sum_of_factors = 0;
    for(counter=1; counter<num; counter++)
    {
         if(0 ==  num%counter)
         {
             sum_of_factors += counter;
         }   
    }
    
    if(num == sum_of_factors)
    {
        return 1; //indication that number is perfect one.

    }
    
 return 0;   //indication that number is not perfect one.
}