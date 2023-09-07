#include<stdio.h>
#include<conio.h>

void motor_half_speed(void);
void motor_stop(void);
void motor_full_speed(void);
int main(){




char state = 0;
while( getch() == 99)
{
     

     switch (state)
    {
         case 0 :
                motor_half_speed();
                state = (state+1)%4;
                break;

         case 1 :
                motor_stop();
                state = (state+1)%4;
                break;

         case 2 :
                motor_full_speed();
                state = (state+1)%4;
                break;

         case 3 :
                motor_stop();
                state = (state+1)%4;
                break;              

    }
}



    return 0;
}

void motor_half_speed(void){
    printf("half speed\n");
}

void motor_stop(void){
    printf("stop\n");
}

void motor_full_speed(void){
    printf("full speed\n");
}