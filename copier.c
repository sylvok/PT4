#include <stdio.h>
#include <stdlib.h>


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
