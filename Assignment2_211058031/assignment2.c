#include "assignment2.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void put_employee_data_to_require()
{
  FILE  *ptr = fopen("Employee.txt", "w");
  assert(ptr != NULL);
  Emp e1 = {1,"Chandana",9847514226,"Manager",50000};
  Emp e2 = {2,"Roja", 9458965478,"Manager",50000};
  Emp e3 = {3,"Greeshma",944996823,"Employee",50000};
  //fwrite(&e1, sizeof(Emp), 1, ptr); for binary
  fprintf(ptr, "%6d%20s%20d%20s%20d\n" ,e1.employee_id, e1.employee_name, e1.employee_phone, e1.employee_designation, e1.employee_salary);
 fprintf(ptr, "%6d%20s%20d%20s%20d\n" ,e2.employee_id, e2.employee_name, e2.employee_phone, e2.employee_designation, e2.employee_salary);
 fprintf(ptr, "%6d%20s%20d%20s%20d\n" ,e3.employee_id, e3.employee_name, e3.employee_phone, e3.employee_designation, e3.employee_salary);
  fclose(ptr);
}

/*void display_file_data()
{
  Emp  e;
  FILE *file = fopen ("Employee.txt", "r");
  assert(file != NULL);
  fread(&e, sizeof(e), 1, file);
  printf("Contents in the file:");
    printf("\n%7d%7s%7d%7s%7d\n", e.employee_id, e.employee_name, e.employee_phone, e.employee_designation, e.employee_salary);
  fclose (file);
}*/

int  count_the_number_of_employees()
{
   int count=0;
    char ch;
    FILE  *ptr = fopen("Employee.txt","r");
    while(!feof(ptr))
    {
        ch = fgetc(ptr);
        if(ch == '\n')
            count = count+1;
    }
    //printf("\n\nThe count of the employees: %d\n", count);
    return count;
    fclose(ptr);
}

int count_of_employee_with_same_designation1()
{
     int count=0;
     Emp em;
     char manager[100] = "Manager";
    FILE  *ptr = fopen("Employee.txt","r");
    while(!feof(ptr))
    {
        //fscanf(ptr,"%d%20s%20d%20s%20d" , &em.employee_id, em.employee_name, &em.employee_phone, em.employee_designation, &em.employee_salary);
        fscanf(ptr, "%s", &em.employee_designation);
        if(strcmp(manager, em.employee_designation)==0)
            count = count + 1;
    }
    return count;
fclose(ptr);
}

int count_of_employee_with_same_designation2()
{
     int count1=0;
     Emp em;
     char employee1[100] = "Employee";
    FILE  *ptr = fopen("Employee.txt","r");
    while(!feof(ptr))
    {
        //fscanf(ptr,"%d%20s%20d%20s%20d" , &em.employee_id, em.employee_name, &em.employee_phone, em.employee_designation, &em.employee_salary);
        fscanf(ptr, "%s", &em.employee_designation);
        if(strcmp(employee1, em.employee_designation)==0)
            count1 = count1 + 1;
    }
    return count1;
fclose(ptr);
}


int total_salary_of_the_employee( )
{
    FILE *re = fopen("Employee.txt","r");
    int sum=0;
    Emp em;
    fscanf(re,"%d%20s%20d%20s%20d" , &em.employee_id, em.employee_name, &em.employee_phone, em.employee_designation, &em.employee_salary);
    while(!feof(re))
    {
        //printf("%d\n", em.employee_salary);
        sum = sum + em.employee_salary;
        fscanf(re,"%d%20s%20d%20s%20d" ,&em.employee_id, em.employee_name, &em.employee_phone, em.employee_designation, &em.employee_salary);
    }
    //printf("\n\nThe total sum of the salary:%d", sum);
    return sum;
    fclose(re);
}

void move_the_information_of_employee_with_same_designation()
{
     Emp em;
     //char manager[100] = "Manager";
     //char employee1[100] = "Employee";
    FILE  *ptr = fopen("Employee.txt","r");
    while(!feof(ptr))
    {
        fscanf(ptr,"%d%s%d%s%d" ,&em.employee_id, em.employee_name, &em.employee_phone, em.employee_designation, &em.employee_salary);
        if(strcmp("Manager", em.employee_designation)==0)
        {
            FILE *fp = fopen("Manage.txt","a");
            fprintf(fp, "%6d%20s%20d%20s%20d\n" ,em.employee_id, em.employee_name, em.employee_phone, em.employee_designation, em.employee_salary);
        }
        else if(strcmp("Employee", em.employee_designation)==0)
        {
            FILE *fp = fopen("Employ.txt","w");
            fprintf(fp, "%6d%20s%20d%20s%20d\n" ,em.employee_id, em.employee_name, em.employee_phone, em.employee_designation, em.employee_salary);
        }
    }
fclose(ptr);
}




