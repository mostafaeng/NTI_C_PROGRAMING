#include<stdio.h>
#include<stdlib.h>

int *reverse_array(int arr[],unsigned int length);
int main(){



int arr_1[5] = {1,2,3,4,5};
char counter;
int *ptr = reverse_array(arr_1,5); 
for(counter = 0; counter<5; counter++){
     printf("\narr[%d] : %d\n",counter+1,ptr[counter]);
}


    return 0;
}

int *reverse_array(int arr[],unsigned int length){
    int *temp;
    unsigned int counter;
    temp = (int *)calloc(length,sizeof(int));
    for(counter= 0; counter<length; counter++)
    {
        temp[counter] = arr[length-1-counter] ;      
    }

return temp;

}