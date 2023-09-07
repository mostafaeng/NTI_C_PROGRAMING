#ifndef _PROBLEM2_FUNCTION_H
#define _PROBLEM2_FUNCTION_H
#include<string.h>
#include<stdio.h>

typedef struct 
{
    char name[30];
    unsigned short id;
    float grade;

}student_data_t;




void get_data(student_data_t data[]);
void get_average_highest_lowest_grade(student_data_t data[]);
void print_data(student_data_t *data);



#endif
