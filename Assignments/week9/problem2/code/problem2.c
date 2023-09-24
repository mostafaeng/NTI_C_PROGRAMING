#include<stdio.h>
#include<stdlib.h>

//program take array and return another one 



char *check_if_num_power_2(int *arr,unsigned int length,unsigned int *result_length);

int main(){


unsigned int len;
unsigned int result_length;
int arr_1[100];

printf("\n\nenter array length : ");
scanf("%d",&len);


printf("\n");
for(int i =0; i<len; i++)
{
    printf("arr[%d] :",i+1);
    scanf("%d",&arr_1[i]);
}

printf("\n");
char*ptr = check_if_num_power_2(arr_1,len,&result_length);
for(char i=0; i<len; i++)
{
    printf("[%d--%d]  ",arr_1[i],ptr[i]);
}



    return 0;
}


char *check_if_num_power_2(int *arr,unsigned int length,unsigned int *result_length)
{
    unsigned int counter;
    unsigned int mul_result = 1;
    char *ret_arr = (char*)malloc(length*sizeof(char));

    for(counter =0; counter<length; counter++)
    {
        do{
             mul_result *= 2;
             if(mul_result == arr[counter])break;   

        }while(mul_result<arr[counter]);

        ret_arr[counter] = mul_result == arr[counter] ? 1 : 0;
        mul_result = 1;

    }

    *result_length = counter;

  return ret_arr;

}