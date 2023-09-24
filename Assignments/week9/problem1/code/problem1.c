#include<stdio.h>


//******** calculate number of ones in decimal number using shift.

int main(){

int num;
unsigned char num_of_ones = 0;

printf("\n\nEnter number: ");
scanf("%d",&num);

while(num<10)
{

    for(char i =0; i<32; i++)
    {
        if(num & (int)1<<i)
        {
            num_of_ones++;
        }
        
    }
printf("\n\nnum of ones in %d = %d\n",num,num_of_ones);
num_of_ones = 0;
num++;
}


printf("\n\nnum of ones = %d\n",num_of_ones);
    return 0;
}