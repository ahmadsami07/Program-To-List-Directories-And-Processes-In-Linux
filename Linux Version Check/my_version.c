//Ahmad As Sami
//SFU ID: 301404717
//CMPT 300 Assignment 1
//Q3
#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 



int main() {
    
    FILE* file = fopen("/etc/os-release", "r");
    char line[256];
    char result[256];
    char *result1;
    int i=0;
    int resultcounter=0;
    char* osstring;
    char*versionstring;


    while (fgets(line, sizeof(line), file)) {
         //printf("%s",line);
         //We will iterate over the file with all lines, and only take the 4th line, which has the OS. We will then pass it
         //on to the string array osstring
          
          for (int j=0;j<strlen(line);j++)
                {
                if(i==4)
                    {
                      result[resultcounter]=line[j];
                      resultcounter++;
                    
                    
                    }
                    //Find the last occurence of the equal, and get that part of the string, as OS is after the equal sign.
                    result1=strrchr(result,'=');
                    }
                      i++;
                    }
                  if (result1 != NULL) {
                              
                            
                            //Since there is a = sign left, we remove it by shifting the string array in the left direction by one.
                              for(i=0;i<strlen(result1)-1;i++)
                                    {
                                        result1[i]=result1[i+1];
                                    }

                                    

                                    //removing extra character
                                    result1[strlen(result1)-1]='\0';

                                    //We also need to remove the quotation marks at the beginning and end.

                                       for(i=0;i<strlen(result1)-1;i++)
                                    {
                                        result1[i]=result1[i+1];
                                    }

                   

                                    result1[strlen(result1)-3]='\0';

                                    osstring=result1;
                              
                              }    
    fclose(file);


//The following part of the program is for getting the version
  file = fopen("/proc/version", "r");

        
    while (fgets(line, sizeof(line), file)) {
            versionstring=line;

    }

//Tokenizing until the first bracket appears in the linux version
    versionstring=strtok(versionstring,"(");
    fclose(file);
    
    

    printf("OS : %s",osstring);
    printf("\n");
    printf("%s",versionstring);
        printf("\n");
    return 0;
}