#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <dirent.h>
#include "aide.h"

int remove(const char * pathname);

int detailA(void)
{
    DIR *dp;
    struct dirent *ep;
    char* tar = NULL;
    dp = opendir("./" );
       
    if (dp != NULL)
    {
        const char* str = NULL;
        while (ep = readdir(dp))
            if ((str = strstr(ep->d_name, ".tar" )) && strlen(str) == strlen(".tar" )) {
                tar = ep->d_name;
            }
          
        closedir(dp);
    }
    else {
        perror("Impossible d'ouvrir le fichier\n" );
        return 1;
    }
   
    if (!tar) {
        perror("Le fichier Tar n'a pas été trouvé!\n" );
        return 1;
    }
   
    struct stat file_status;
    
    if (stat(tar, &file_status)) {
        fprintf(stderr, "impossible d'afficher info %s", tar);
        return 1;
    } else
        printf("Nom Tar: %s\n    size: %9jd Kb\n", tar, ((intmax_t)file_status.st_size) / 1024);
   
    return 0;
}

 
int lister(void)
{
    DIR * rep = opendir(".");
 
    if (rep != NULL)
    {
        struct dirent * ent;
 
        while ((ent = readdir(rep)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
 
        closedir(rep);
    }
 
    return 0;
}

int header(void)
{
    FILE* fichier = NULL;
    int caractereActuel = 0;
    char *caractereSuivant;
    char ligne[90];
  
    fichier = fopen("a.txt", "r");
  
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
           // printf("%c", caractereActuel); // On l'affiche

            if(caractereActuel == 'n')
            {
   	            caractereSuivant = fgets(ligne,90,fichier); // On lit le caractère
            	printf("caractère trouvé\n");
            	printf("%s", caractereSuivant); // On l'affiche

            }

        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
  
        fclose(fichier);
    }
  
    return 0;
}

void copier(int argc, char **argv)
{
		 FILE *fSrc;
		 FILE *fDest;
		 int nb=2;
		 char ligne[90];

		if ((fDest= fopen(argv[argc-1],"w")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		}
		while (nb<argc && argc>1)
		{			
			if ((fSrc = fopen(argv[nb],"r")) == NULL)
				fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);

			fgets(ligne, 90, fSrc);
			fputs(argv[nb],fDest);
			fputc('\n',fDest);

			while (!feof(fSrc))
			{
				fputs(ligne, fDest);
				fgets(ligne, 81, fSrc);
			    fputs("n\n", fDest);
			}

			fclose(fSrc);
			nb++;
		}
		fclose(fDest);
		printf("\nLa copie est terminee.\n");	
}


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
				detailA();
				break;
           default:
				fprintf(stderr, "Error\n");
           }          				        
     }
     return 0;
}

