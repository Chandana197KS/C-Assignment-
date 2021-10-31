/*
   *Author: Chandana K S
  *Date: 31/10/2021
  *Purpose: C assignment
  *Question: Create structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number, Designation and salary.
Store this information in “Employee.txt” file. Read the data from file and perform the following actions.
1. Count total number of employees.
2. Count number employees with same designation.
3. Total salary of all employees.
4. Place the employees in separate files based on their designation.
*/

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "assignment2.h"
int main()
{
    put_employee_data_to_require();
    //display_file_data();
    assert(count_the_number_of_employees() == 3);
    assert(count_of_employee_with_same_designation1()==2);
    assert(count_of_employee_with_same_designation2()==1);
    assert(total_salary_of_the_employee() == 150000);
     move_the_information_of_employee_with_same_designation();
    return 0;
}
