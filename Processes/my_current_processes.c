//Ahmad As Sami
//SFU ID: 301404717
//CMPT 300 Assignment 1
//Q1
#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 



int main() {

  DIR* procfolder;
  struct dirent *folderaccess;
  //The string filepath will contain our total filepath
  char filepath[1024];
  
  


  //Using opendir, we will return a pointer at the first of the directory stream of files in the directory.
  procfolder=opendir("/proc");


    //Now, we will use a while loop and use readdir
    //to sequentially go over each file in the directory,
    //and if not NULL, we will check if the file is numerical at first.
    while ((folderaccess = readdir(procfolder)) != NULL)
    {
      {
        int i;
        FILE *fs;
        char *ptr, *name = filepath;

        /* Process ID must be numeric */
        for (i = 0; folderaccess->d_name[i] != '\0'; ++i)
        {
            int is_it_numeric=isdigit(folderaccess->d_name[i]);
            if(is_it_numeric)
            {
              //We will use snprintf, as so that we can use it similar to using print with format, so taht
              //we can add the specific process ID to access each file in the proc folder.The filepath later is
              //sent into the string filepath, which we can process further. Mainly using snprintf allows us
              //to put the path into our filepath stream, and we can be able to replace the "%s" with folderaccess->d_name
                snprintf(filepath, 1024, "/proc/%s/cmdline", folderaccess->d_name);


                //Now we will take out the name from the file path we have, by opening file
                fs = fopen(filepath, "r");
                if (fgets(filepath, 1024, fs) != NULL)
                {


                    //First, we will use empty delimiter, and remove whitespace
                    ptr = strtok(filepath, " ");

                    //Now, we will get the last token of the filepath
                   //strrchr gives us the last occurence of a /
                    char *last = strrchr(ptr, '/');
                    if (last != NULL) {
                              
                            
                            //Since there is a last / left, we remove it by shifting the string array in the left direction by one.
                            for(i=0;i<strlen(last)-1;i++)
                              {
                                  last[i]=last[i+1];
                              }

                              //removing extra character
                              last[strlen(last)-1]='\0';

                              name=last;
                            
                        }    
                }

                else
                {
                  //for empty cmdfile with no name
                    filepath[0] = '\0';
                }
                printf("%s  %s\n", folderaccess->d_name, name);
                break;

                fclose(fs);
            }
            
        }

    }


}
    closedir(procfolder);
    return 0;
}