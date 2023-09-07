#include<stdio.h>
#define LENGHT  10

char check_if_duplicate_before(int duplicate_elems[], unsigned int length,int value);

int main(){
    unsigned int counter_1;
    unsigned int counter_2;
    unsigned int times_num_of_duplicate = 1;
    unsigned int total_num_of_duplicate_elem = 0;
    unsigned int duplicate_elements[10];
    unsigned int index = 0;
    int arr[LENGHT] = {1,1,2,1,3,2,1,3,2,3};
     
     printf("\n\n");
    for(counter_1 =0; counter_1<LENGHT-1; counter_1++)
    {
         for(counter_2 =counter_1+1; counter_2<LENGHT; counter_2++)
         {
              if(arr[counter_1] == arr[counter_2])
              {
                times_num_of_duplicate++;
              }
         }

         if((times_num_of_duplicate>=2) && (check_if_duplicate_before(duplicate_elements,index,arr[counter_1])))
         {
            duplicate_elements[index++] = arr[counter_1];
            total_num_of_duplicate_elem++;
            printf("%d duplicate %d times\n",arr[counter_1],times_num_of_duplicate);
         }
         times_num_of_duplicate = 1;
    }
    
    printf("\ntotal number of duplicated elements = %d\n",total_num_of_duplicate_elem);



    return 0;
}

char check_if_duplicate_before(int duplicate_elems[], unsigned int length,int value){

    unsigned int counter = 0;
    for(counter =0; counter<=length; counter++)
    {
        if(value == duplicate_elems[counter]){
            return 0; // indicate that number is duplicate before.
        }
    }
    return 1; // indicate that number is not duplicate before.
}