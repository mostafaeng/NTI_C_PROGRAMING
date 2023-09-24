#include<stdio.h>


int find_last_occurance(unsigned int length,int*arr,int value);
int main(){

int value;
int arr[7] = {2,3,4,5,6,4,7};

printf("\n\nenter value to find last occurance: ");
scanf("%d",&value);

printf("\n\nlast occurance of %d = %d\n\n",value,find_last_occurance(7,arr,value));

    return 0;
}


int find_last_occurance(unsigned int length,int*arr,int value)
{
   unsigned int counter;
   int ret_index = -1;

   for(counter = 0; counter<length; counter++)
   {
       if(value == arr[counter])
       {
           ret_index = counter;
       }
   }

return ret_index;

}