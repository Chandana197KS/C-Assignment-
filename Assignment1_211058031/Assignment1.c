#include<stdio.h>
#include<stdlib.h>
#include "Assignment1.h"
#define SIZE 5


int sum_of_n_numbers_persent_in_the_file()
{
    FILE* file = fopen ("text.txt", "r");
  int i = 0, sum = 0;
  fscanf (file, "%d", &i);
  while (!feof(file))
    {
       sum = sum + i;          // counts the sum of the numbers present in the file.
      fscanf (file, "%d", &i);
    }
    //printf("\n%d", sum);
    return sum;
  fclose (file);
}

void generate_square_of_a_number()
{
    FILE *file = fopen ("text.txt", "r");
  int i = 0, square = 0;
  fscanf (file, "%d", &i);
  while (!feof(file))
    {
       square = i * i;
       FILE *ptr =fopen("square.txt","a"); // the computed square is written to the new file called square.txt.
       fprintf(ptr,"%d\t", square); // here it writes to the file.
      fscanf (file, "%d", &i); // here fscanf is used to read the content of the file in string form.
    }
  fclose (file);
}

int number_of_times_substring_present(char sub)
{
    int count=0;
    char temp[10];
    FILE *file = fopen("longsentence.txt","r");
    while(fgets(temp,10,file)!= NULL)
    {
        char *p = temp;
        while((p = strstr(p,sub)) !=NULL)
        {
            count = count +1; // here counts the number of times the pattern is matched.
            ++p;
        }
    }
    fclose(file);
    return count;
}

int length_of_longest_sentence()
{
     FILE *f1,*f2;
    char c;
    int count=0,longlen=0;
    f1=fopen("longsentence.txt","r");
    f2=fopen("lengthsentences.txt","w");
    while((c=getc(f1))!=EOF)
    {
        count++;
        if(c=='\n')
        {
            if(longlen<count)
            {
                longlen=count;
            }
        fprintf(f2,"%d\n",count);
        count=0;
        }
    }
    fclose(f1);
    fclose(f2);
    return longlen;
}

void reverse_order()
{
      FILE *file;
    file = fopen("numbers.txt","r");
    int arr3[SIZE],i;
    //opening the file to write the array in reverse order
    FILE *myfile = fopen("write_file.txt","w");

    //storing the numbers in file numbers.txt to an array
    for(i=0;i<SIZE;i++)
    {
        fscanf(file,"%d",&arr3[i]);
    }
    //storing the elements of an array in reverse order in write_file.txt file
    for(i=SIZE-1;i>=0;i--)
    {
        fprintf(myfile,"%d\n",arr3[i]);
    }
}

