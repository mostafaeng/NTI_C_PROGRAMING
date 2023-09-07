#include<stdio.h>


unsigned int calc_signal_falling_edge(char signal[],unsigned int length);
int main(){

 char signal_1[6] = {1,0,1,0,1,0};
 printf("\n\nnumber of falling edges = %d\n",calc_signal_falling_edge(signal_1,6));

    return 0;
}

unsigned int calc_signal_falling_edge(char signal[],unsigned int length){
     unsigned int num_of_edge = 0;
     unsigned int counter = 0;
        while(counter<length)
        {
            if((signal[counter] == 1 ) && (signal[counter+1] == 0))
            {
                num_of_edge++;
            }
            counter++;
        }
 return num_of_edge;

}