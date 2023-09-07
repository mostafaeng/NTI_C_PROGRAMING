#include<stdio.h>




int main(){
unsigned char rows;
unsigned char counter_1;
unsigned char counter_2;
printf("\n\n");
printf("Enter number of rows: ");
scanf("%d",&rows);

for(counter_1 =1; counter_1<=rows; counter_1++)
{
     for(counter_2 =1; counter_2<=(2*rows-1); counter_2++)
     {
        if(counter_2>=rows-(counter_1-1) && counter_2<=rows+(counter_1-1))
        {
             0 == counter_1%2 ? (0 == counter_2%2 ? printf(" ") : printf("*")) : (0 != counter_2%2 ? printf(" ") :printf("*"));
        }
        else
        {
            printf(" ");
        }
     }
     printf("\n");
}


    return 0;
}