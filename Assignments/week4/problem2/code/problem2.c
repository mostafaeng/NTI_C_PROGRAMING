#include<stdio.h>




void calc_ones_negative_numbers_in_array(int arr[],unsigned int length,unsigned int *ones,unsigned int *negative);
int main(){

int arr_1[10] = {1,1,-1,2,3,1,-2,-3,4,1};
unsigned int num_ones;
unsigned int num_negative;

calc_ones_negative_numbers_in_array(arr_1,10,&num_ones,&num_negative);

printf("number of ones = %d\nnumber of negtive = %d\n",num_ones,num_negative);



    return 0;
}

void calc_ones_negative_numbers_in_array(int arr[],unsigned int length,unsigned int *ones,unsigned int *negative){
       unsigned int counter;
       *ones = 0;
       *negative = 0;
       for(counter=0; counter<length; counter++)
       {
            if(1 == arr[counter])
            {
                (*ones)++;
            }

            if(0>arr[counter])
            {
                (*negative)++;
            } 
       }
      


}