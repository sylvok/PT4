#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void supp(int argc, char **argv)
{
    FILE * fSrc; // IN
    FILE * fDest;
    int nb = 2;
    char ligne[256];
 
    if ((fSrc = fopen("arrivee.txt", "r")) == NULL)
         printf("\nErreur: Impossible de lire le fichier\n");
 
    if ((fDest = fopen("arrivee.tmp", "w")) == NULL)
    {
        printf("\nErreur: Impossible de lire le fichier\n");
    }
 
    while (nb<argc && argc>1)
    {
        while (fgets(ligne, sizeof ligne, fSrc))
        {
            if (ligne[0] != argc)
                fputs(ligne, fDest);
        }
        nb++;
    }

    fclose(fSrc);
    fclose(fDest);
 
    rename("arrivee.tmp", "arrivee.txt");
    
    if ( debug = true ) 
			printf ( "\nLa suppression est terminee.\n" );
}
