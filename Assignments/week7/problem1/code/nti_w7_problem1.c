
#include<stdio.h>
#include<string.h>
#include"d_stack.h"


void decode_function(char *str,d_stack_t *obj);
char string[25] ="EAS*Y*QUE***ST***IO*N***" ;
char string_after_decode[100];
static stack_state ret;
d_stack_t *temp;

int main(){

    temp = create_d_stack(25,&ret);
    decode_function(string,temp);
    printf("\n\n%s\n\n",string_after_decode);

  return 0;
}











//function to decode encoded string*********************************

void decode_function(char *str,d_stack_t *obj){

    unsigned int index = 0;
    while('\0' != *str)
    {
        if('*' == *str)
        {
          string_after_decode[index++] = *pop_d_stack(obj,&ret);
          string_after_decode[index++] = ' ';
        }
        else
        {
            ret = push_d_stack(obj,str);

        }
       str++;

    }
    
}