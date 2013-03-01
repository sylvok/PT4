#include <stdio.h>
#include <stdlib.h>

int nombreLignes (FILE* fichier) {

  char ligne[90];
  int nb_ligne;

  while (!feof(fichier))
  { 
    fgets(ligne, 90, fichier);
    ++nb_ligne;
  }
  fclose(fichier);

  return nb_ligne;
}
