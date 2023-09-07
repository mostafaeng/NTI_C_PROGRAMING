#include<stdio.h>
#include<math.h>
#include<stdlib.h> 


int main(){

float a,b,c;
float distinctive;
float real_root;
float imagine_part;

printf("Enter coefficient of equation: ");
scanf("%f%f%f",&a,&b,&c);

distinctive = b*b-(4*a*c);

switch (0 == distinctive)
{
      case 1 :
             real_root = -(b/(2*a));
             printf("two identical real roots = %0.1f\n",real_root);
             break;
      default :
             switch(distinctive>0)
             {
                     case 1 :
                            real_root = (-b+sqrt(distinctive))/(2*a);
                            printf("real_root1 = %0.1f\n",real_root);
                            real_root = (-b-sqrt(distinctive))/(2*a);
                            printf("real_root2 = %0.1f\n",real_root);
                            break;
                     default :
                            real_root = -(b)/(2*a);
                            imagine_part = sqrt(abs(distinctive))/(2*a);
                            printf("complex_root1 = %0.3f + %0.3fi\ncomplex_root2 = %0.3f - %0.3fi\n",real_root,imagine_part,real_root,imagine_part);
                            break;
             }       
           

}



    return 0;
}