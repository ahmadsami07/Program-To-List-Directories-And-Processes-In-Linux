//Ahmad As Sami
//SFU ID: 301404717
//CMPT 300 Assignment 1
//Q2
#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 



int main() {
    
    FILE* file = fopen("/proc/meminfo", "r");
  char line[256];
   char result[256];
   char result1[256];
   char result2[256];
   char result3[256];
   char result4[256];
    int i=0;
    int resultcounter=0;
  double t = 0, f = 0, b = 0, c = 0, s = 0;

  double memory_util;

    while (fgets(line, sizeof(line), file)) {
          //We will at first go over each line of the file, then
          //we know that which data is on which line.
          //So, we know the values of i we must target to get our 
          //total, free, buffer,cached and slab, which is 0,1 ,3 4 and 21 respectively
   
            if (i==0)
            {
                for (int j=0;j<strlen(line);j++)
                {
                  //Whenever we encoutner a number, we 
                  //store the number in the result array, and keep concatenating
                  //this removes all characters except digits in the line we need
                if(isdigit(line[j]))
                {
                  result[resultcounter]=line[j];
                  resultcounter++;
                
                }
                
                }
                char*res=result;
                t=strtod(res,NULL);
                resultcounter=0;

            }
            if(i==1)
            {
              //  printf("%s",line);
                for (int j=0;j<strlen(line);j++)
                {
                   //Whenever we encoutner a number, we 
                  //store the number in the result array, and keep concatenating
                  //this removes all characters except digits in the line we need
                if(isdigit(line[j]))
                {
                   
                  result1[resultcounter]=line[j];
                  resultcounter++;
                
                }
                }
                char*res=result1;
                f=strtod(res,NULL);
                resultcounter=0;
            }
     
              if(i==3)
            {
             //    printf("%s",line);
                for (int j=0;j<strlen(line);j++)
                {
                   //Whenever we encoutner a number, we 
                  //store the number in the result array, and keep concatenating
                  //this removes all characters except digits in the line we need
                if(isdigit(line[j]))
                {
                   
                  result2[resultcounter]=line[j];
                  resultcounter++;
                
                }
                }
                 char*res=result2;
                b=strtod(res,NULL);
                resultcounter=0;
            }


              if(i==4)
            {
                 //printf("%s",line);
                for (int j=0;j<strlen(line);j++)
                {
                   //Whenever we encoutner a number, we 
                  //store the number in the result array, and keep concatenating
                  //this removes all characters except digits in the line we need
                if(isdigit(line[j]))
                {
                   
                  result3[resultcounter]=line[j];
                  resultcounter++;
                
                }
                }
                char*res=result3;
                c=strtod(res,NULL);
                resultcounter=0;
            }


                if(i==21)
            {
                // printf("%s",line);
                for (int j=0;j<strlen(line);j++)
                {
                   //Whenever we encoutner a number, we 
                  //store the number in the result array, and keep concatenating
                  //this removes all characters except digits in the line we need
                if(isdigit(line[j]))
                {
                   
                  result4[resultcounter]=line[j];
                  resultcounter++;
                
                }
                }
                 char*res=result4;
                s=strtod(res,NULL);
            }
            i++;
         }

    
    memory_util = (t - f - b - c - s);
    memory_util=(memory_util/t)*100;

    printf("Memory utilization: %.lf%%\n", memory_util);



    fclose(file);
    printf("\n");

    return 0;
}