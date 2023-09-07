#include<stdio.h>

char check_if_armstrong_number(unsigned int num);
int main(){

unsigned int num1;
unsigned int num2;
printf("\n\nEnter two to find armstrong numbers between them: ");
scanf("%d%d",&num1,&num2);

  for(int counter = num1; counter<=num2; counter++)
  {
       if(check_if_armstrong_number(counter))
       {
            printf("%d  ",counter);
       }
  }


    return 0;
}

char check_if_armstrong_number(unsigned int num){

    unsigned int sum = 0;
    char remainder;
    unsigned int temp = num;
    

    do{
         remainder = temp%10;
         sum += (remainder*remainder*remainder);  
         temp /= 10;
    }while(temp>0);

    if(num == sum)
    {
        return 1; // indicate that number is armstrong one.
    }
                   

return 0;  // indicate that number is not armstrong one.
    
    
}