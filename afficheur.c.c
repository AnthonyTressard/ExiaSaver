#include <stdio.h> 	// librairie qui définit des variables et des fonctions pour effectuer les entrées et les sorties
#include <stdlib.h>	// librairie qui définit des variables et des fonctions
#include <time.h>	// librairie qui permet de manipuler la date et l'heure
#include <string.h>	// librairie qui permet de manipuler des tableaux de caractères
#include <sys/ioctl.h>	// librairie qui permet de centrer l'image

void main()
{
FILE *fichier=NULL;	// FILE est un type destiné aux fichiers
char magic[2];		// Tableau de 2 cases en caractère
char com[4];		// Tableau de 4 cases en caractère
char size[5];		// Tableau de 5 cases en caractère
int caractere;		// Variable de type int
int ecranmagique;	// Variable de type int
int n;			// Variable de type int
struct winsize w;	// Fonction qui permet de trouver les colonnes, les lignes, pixels horizontale et verticale de la console

srand(time(NULL));	// Initialise la fonction srand sur le temps acutel
ecranmagique=rand()%3 + 1;     	// Genère un chiffre aléatoire entre 1 et 3
printf("Le second tirage est : "); // Ecrit sur le terminal
printf("%d \n", ecranmagique);	   // Ecrit sur le terminal
system("clear");		   // Permet d'effacer le contenue de la console

if(ecranmagique==1)		// On compare 1 a ecranmagique
{
	fichier = fopen("static.bmp", "r");	// le pointeur fichier pointe sur le fichier ouvert static.bmp. Nous pouvons ecrire dedans

	fread(magic, 3, 1,fichier); // fread permet de lire seulement une ligne du fichier

	fread(com, 5, 1, fichier);  // fread permet de lire seulement une ligne du fichier

	fread(size, 6, 1, fichier); // fread permet de lire seulement une ligne du fichier

	if(fichier !=NULL)		//  Si le fichier n'est pas NULL
	{
		while(caractere !=EOF)	// Tant qu'il y a un retour a la ligne
		{
	 	caractere=fgetc(fichier); // On lit caractere par caractere et on le stocke dans la variable caractere

			if(caractere == '0') // On compare 0 a caractere
			{
			caractere = 32;      // On affecte 96 a la variable caractere
			}

			else if (caractere == '1') // Sinon on compare 1 a caractere
			{
			caractere = 64;		// On affecte 64 a la variable caractere
			}

		      	ioctl(0, TIOCGWINSZ, &w);


//			for(n=0; n<((w.ws_row - 10) / 2); n++)
//			{
//			  printf(" ");
//			}

		printf("%c", caractere);
		}
	}

fclose(fichier); 	// Ferme le fichier ouvert
}

else if(ecranmagique==2) 	// On compare 2 a ecranmagique
{
	fichier = fopen("static2.bmp", "r");	// On ouvre le fichier static2.bmp en mode ecrire et on le stocke dans fichier

	fread(magic, 3, 1, fichier);		// On lit une ligne du fichier jusqu'a 3 caractere maximum

	fread(com, 5, 1, fichier);		// On lit une ligne du fichier jusqu'a 5 caractere maximum

	fread(size, 5, 1, fichier);		// On lit une ligne du fichier jusqu'a 5 caractere maximum

	if(fichier !=NULL)			//  Si le fichier n'est pas NULL
	{
		while(caractere !=EOF)		// Tant qu'il y a un retour a la ligne dans le fichier, tant qu'il y a des fichiers a lire
		{
		caractere = fgetc(fichier);	// On lit caractere par caractere et on stocke dans la variable caractere

			if(caractere == '0')	// On compare 0 a caractere
			{
			caractere = 32;		// On attribut la valeurs 96 a la variable caractere
			}

			else if(caractere == '1')	// Sinon on compare 1 a caractere
			{
			caractere = 64;			// On attribut la valeurs 64 a la variable caractere
			}
		 printf("%c", caractere); 		// On ecrit dans le terminal les valeurs de caractere en caractere
		}
	}
fclose(fichier);					// On ferme le fichier ouvert
}

if(ecranmagique==3)					// On compare 3 a ecranmagique
{

fichier = fopen("static3.bmp","r");			// On ouvre le fichier static3.bmp en mode ecriture et on le stocke dans fichier

fread(magic, 3, 1, fichier);				// On lit une ligne du fichier

fread(com, 5, 1, fichier);				// On lit une ligne du fichier

fread(size, 6, 1, fichier);				// On lit une ligne du fichier

if(fichier != NULL)					// Si il y a quelque chose a lire dans le fichier
{
	while(caractere != EOF)				// Tant qu'il y a un retour chariot
	{
	caractere = fgetc(fichier); 			// On lit caractere par caractere le fichier et on stocle dans caractere

		if(caractere == '0')			// On compose caractere a 0
		{
		caractere = 32;				// On attribut 96 a la variable caractere
		}

		else if(caractere == '1')		// Sinon on compare 1 a caractere
		{
		caractere = 64;				// On attribut 64 a la variable caractere
		}
	 printf("%c", caractere);			// On ecrit dans le terminal les caracteres en caractere
	}
}
fclose(fichier);					// On ferme le fichier ouvert
}

else							// J'ai ajouté else pour ne pas que le programme rencontre des problemes
{
}

return ;
}

