#include <stdio.h>
#include <stdlib.h>

int header(void)
{
    FILE* fichier = NULL;
    int caractereActuel = 0;
    char *caractereSuivant;
    char ligne[90];
  
    fichier = fopen("arrivee.txt", "r");
  
    if (fichier != NULL)
    {
        caractereSuivant = fgets(ligne, sizeof ligne, fichier); // On lit le caractère
        printf("%s", caractereSuivant); // On l'affiche
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
           // printf("%c", caractereActuel); // On l'affiche

            if(caractereActuel == 'n')
            {
                caractereActuel = fgetc(fichier);
   	            caractereSuivant = fgets(ligne, sizeof ligne, fichier); // On lit le caractère
            	printf("%s", caractereSuivant); // On l'affiche

            }

        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
  
        fclose(fichier);
    }
  
    return 0;
}