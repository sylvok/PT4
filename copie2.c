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


void afficherAide()
{			
	printf("\n");       
	printf("-h : affiche l'aide de votre commande\n");
	printf("-v : pour activer le mode verbose (affiche des détails sur l'execution)\n");
	printf("-c : pour créer une archive à partir d'une liste de fichier\n");
	printf("-t : pour lister les fichiers contenus dans une archive\n");
	printf("-r : pour ajouter de nouveaux fichiers\n");
	printf("-u : pour mettre à jour l'archive si les fichiers liés sont plus récents que ceux archivés\n");
	printf("-x : pour extraire les fichiers de l'archive\n");
	printf("-f : pour indiquer le nom du fichier archive\n");
	printf("-z : pour compresser le fichier d'archive\n");
	printf("-d : pour suprimer un fichier d'une archive\n");
	printf("-sparse : pour économiser de la place pour stocker les fichiers contenant beaucoup de zéros consécutifs\n");
	printf("-m : afficher les différences entre les fichiers archivés et les fichiers existants\n");
	printf("\n"); 
}

int header(void)
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
        perror("Impossible d'ouvrir lefichier\n" );
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


int main (int argc, char **argv)
     {
	   int tflag = 0;
       int cflag = 0;
       
       int c;
     
       if ((c = getopt (argc, argv, "hctf")) != -1)
       {
		   int nb=1;
         switch (c)
           {
           case 'h':
				afficherAide();
				break;
           case 'c':
				cflag = 1;
				break;
           case 't':
				tflag = 1;
				break;
		   case 'f':
				header();
				break;
           default:
				fprintf(stderr, "Error\n");
           }          				        
     }
     
	 if (cflag == 1)
	 {
		 FILE *fSrc;
		 FILE *fDest;
		 int nb=2;
		 char ligne[90];

		if ((fSrc = fopen(argv[argc-1],"w")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		}
		while (nb<argc && argc>1)
		{			
			if ((fDest = fopen(argv[nb],"r")) == NULL)
				fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);

			fgets(ligne, 90, fDest);

			while (!feof(fDest))
			{
				fputs(ligne, fSrc);
				fgets(ligne, 81, fDest);
			}


			fclose(fDest);
			nb++;
		}
		fclose(fSrc);
		printf("\nLa copie est terminee.\n");	
	 }
	 
     return 0;
}
