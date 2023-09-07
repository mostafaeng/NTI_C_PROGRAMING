#include<stdio.h>
#include<string.h>


typedef struct 
{
    char name[30];
    unsigned short id;
    float salary;
}employees_data_t;

employees_data_t *search_on_employee(employees_data_t data[],char *employee_name,unsigned int num_ofemployee);
void print_employee_data(employees_data_t *data_of_employee);

employees_data_t data[4] = {{"ramy ali",11,4000},{"fady ali",12,3000},{"hossam ali",13,2000},{"kareem ali",14,1000}};
employees_data_t *return_data;

int main(){

    return_data = search_on_employee(data,"hossam ali",4);
    print_employee_data(return_data);

    return 0;
}

employees_data_t *search_on_employee(employees_data_t data[],char *employee_name,unsigned int num_ofemployee){
       employees_data_t *temp;
       unsigned int counter;
       for(counter=0; counter<num_ofemployee; counter++)
       {
            if(0 == strcmp(employee_name,data[counter].name))
            {
                temp = &data[counter];
                break;
            }   
       }
  
  return temp;
}

void print_employee_data(employees_data_t *data_of_employee){
    printf("\n\n==========data of employee=========\n");
    printf("name   : %s\n",data_of_employee->name);
    printf("id     : %d\n",data_of_employee->id);
    printf("salary : %0.2f L.E\n",data_of_employee->salary);
    printf("====================================\n");
}