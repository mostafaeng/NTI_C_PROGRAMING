#include"problem2_function.h"


void get_data(student_data_t data[]){
        unsigned char counter = 0;
        for(counter =0; counter<10; counter++)
        {    
             printf("Enter student[%d] name  : ",counter+1);
             fflush(stdin);fflush(stdout);
             gets(data[counter].name);
             printf("Enter student[%d] id    : ",counter+1);
             scanf("%d",&(data[counter].id));
             printf("Enter student[%d] grade : ",counter+1);
             scanf("%f",&(data[counter].grade)); 
             
             printf("\n");
        }


}
void get_average_highest_lowest_grade(student_data_t data[]) {
       unsigned int counter = 0;
       float max_grade = data[0].grade;
       float min_grade = data[0].grade;
       unsigned char std_max_grade_index = 0;
       unsigned char std_min_grade_index = 0;
       float grades_sum = 0;

       for(counter=0; counter<10; counter++)
       {
             if(max_grade<data[counter].grade)
             {
                max_grade = data[counter].grade;
                std_max_grade_index = counter;
             }

             if(min_grade>data[counter].grade)
             {
                min_grade = data[counter].grade;
                std_min_grade_index = counter;
             }
             grades_sum += data[counter].grade;

       }
       printf("=========student lowest grade data============\n");
       print_data(&data[std_min_grade_index]);
       printf("===============================================\n\n");

       printf("=========student highest grade data============\n");
       print_data(&data[std_max_grade_index]);
       printf("===============================================\n\n");

       printf("average of grades : %0.2f\n",grades_sum/10);
       printf("===============================================\n\n");

}
void print_data(student_data_t *data){

    printf("Name   : %s\n",data->name);
    printf("Id     : %d\n",data->id);
    printf("Grade  : %0.2f\n",data->grade);
}