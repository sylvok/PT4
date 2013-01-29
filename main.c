#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


void main (int argc,char**argv)
{
	int i;
	
	printf("il y a %i arguments\n",argc);
	printf("les voici : \n");
	
	for (i=0;i<argc;i++)
		printf("%s \n", argv[i]);
	
	if ((argc==1)||(argc>2)) printf ("usage : main nomdefichier\n");
	else
	{
		
	}
	
}
