#include <stdio.h>
#include <stdlib.h>

int supp2(void)
{
    FILE* fSrc;
    FILE* fDest;
    int caractereActuel = 0;
    char *caractereSuivant;
    char *caractereSuivant2;
    char ligne[90];
  
    if ((fSrc = fopen("arrivee.txt", "r")) == NULL)
         printf("\nErreur: Impossible de lire le fichier\n");
 
    if ((fDest = fopen("arrivee.tmp", "w")) == NULL)
    {
        printf("\nErreur: Impossible de lire le fichier\n");
    }
  
    if (fSrc != NULL)
    {
        caractereSuivant = fgets(ligne, sizeof ligne, fSrc); // On lit le caractère
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fSrc); // On lit le caractère

            if(caractereActuel == '#')
            {
                caractereActuel = fgetc(fSrc);
                caractereSuivant = fgets(ligne, sizeof ligne, fSrc); // On lit le caractère
   	            
                caractereSuivant2 = fgets(ligne, sizeof ligne, fSrc); // On lit le caractère
            	printf("%s", caractereSuivant2); // On l'affiche

            }

        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fSrc)
  
        fclose(fSrc);
        fclose(fDest);
    }
        rename("arrivee.tmp", "arrivee.txt");
        printf("\nLa suppression est terminee.\n");
  
    return 0;
}