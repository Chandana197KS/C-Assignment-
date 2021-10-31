#ifndef ASSIGNMENT2_H_INCLUDED
#define ASSIGNMENT2_H_INCLUDED


typedef struct employee{
   int employee_id;
  char employee_name[900];
  int employee_phone;
  char employee_designation[700];
  int employee_salary;
}Emp;


void put_employee_data_to_require();
//void display_file_data();
int  count_the_number_of_employees();
int count_of_employee_with_same_designation1();
int count_of_employee_with_same_designation2();
int total_salary_of_the_employee();
void move_the_information_of_employee_with_same_designation();


#endif // ASSIGNMENT2_H_INCLUDED
