#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <dirent.h>
#include "aide.h"
#include "detailA.h"
#include "lister.h"
#include "header.h"
#include "supp.h"

int remove(const char * pathname);

int main (int argc, char **argv)
     {
	   int tflag = 0;
       int cflag = 0;
       int dflag = 0;
       int remove(const char * pathname);
       int c;
     
       if ((c = getopt (argc, argv, "hctfd")) != -1)
       {
         switch (c)
           {
           case 'h':
				afficherAide();
				break;
           case 'c':
				copier(argc, argv);
				break;
           case 't':
				header();
				break;
		   case 'f':
				copier(argc, argv);
				break;
            case 'd':
                supp(argc, argv);
                break;
           default:
				fprintf(stderr, "Error\n");
           }          				        
     }
     return 0;
}

