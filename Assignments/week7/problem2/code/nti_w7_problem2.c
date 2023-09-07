#include"qeueu.h"


void decode_function(char *str,qeueu_t *obj);
char string[25] ="EAS*Y*QUE***ST***IO*N***";
static char string_after_decode[100];
static q_state ret;
qeueu_t *temp;


int main(){

     temp = create_qeueu(26,&ret);
     decode_function(string,temp);
     printf("\n\n%s\n\n",string_after_decode);
   


return 0;
}




void decode_function(char *str,qeueu_t *obj){
      unsigned int index = 0;
      while('\0' != *str)
      {
            if('*' == *str)
            {
                string_after_decode[index++] = *Deqeueu_data(obj,&ret);
                string_after_decode[index++] = ' ';
            }
            else
            {
                   ret = Enqeueu_data(obj,str);
            }
            str++;
      }
      
}