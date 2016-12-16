#include <stdio.h>         //On intègre ici toutes les bibliothèques necessaires pour utiliser les fonctions necessaires.
#include <stdlib.h>
#include <time.h>
#include <string.h>

int aleatoire=0;        //On intègre ici une variable nommée aléatoire qui sera ensuite utile dans la fonction main.

void affichageStats(void)       //La fonction affichageStats est ici utilisé pour lire le fichier historique.txt.
{
	char caractere;
	FILE* fichier = fopen("historique.txt", "r");   //Le "r" signifie read pour dire que le fichier txt doit être lu.

	if(fichier != NULL){
		while(caractere !=EOF){
			caractere = fgetc(fichier);
			printf("%c", caractere);
		}
		printf("\n");
	}
	fclose(fichier);
	}

int menu(void)                  //La fonction menu est simplement utilisé pour avoir un menu visuel dans le programme

{

        printf("================================Menu du programme===============================\n\n");
        printf("Afficher l'ecran des statistiques\t\t\t Appuyez sur la touche s\n");
        printf("Afficher l'ecran de veille statique\t\t\t Appuyer sur la touche e\n");
        printf("Afficher l'ecran de veille dynamique\t\t\t Appuyer sur la touche d\n");
        printf("Afficher l'ecran de veille interactif\t\t\t Appuyer sur la touche i\n");
        printf("Quitter le programme\t\t\t\t\t Appuyez sur la touche q\n\n ");
}


int AffichageMenu(void)         //La fonction AffichageMenu est une fonction qui permet de rendre utilisable les différentes commandes écrites dans le programme menu.
{
    char touche;
	int fin = 0;

	menu();



    	while(fin !=1)
    {
        	scanf("%c", &touche);

		if(touche == 's'){      //Si l'on appuie sur la touche 's' alors les statistiques du fichier 'historique.txt' s'affiche dans la console.

            system("clear");
			printf("test debug\n");
            affichageStats();
	    	printf("Pour revenir sur le menu appuyez sur la touche m\n");
            continue;

        	}

        	else if(touche == 'd'){     //Si l'on appuie sur la touche 'd' alors l'écran de veille dynamique se lance.

            system("clear");
            printf("Voici l'ecran de veille dynamique\n");
	    	system("/home/sebastien/partage/...");
	    	printf("Pour revenir sur le menu appuyez sur la touche m\n");
            continue;

        	}

       		else if(touche == 'i'){     //Si l'on appuie sur la touche 'i' alors l'écran de veille interactif se lance.

           	system("clear");
            printf("Voici l'ecran de veille interactif\n");
	    	system("/home/sebastien/partage/...");
	    	printf("Pour revenir sur le menu appuyez sur la touche m \n");
            continue;

       		}

            else if(touche == 'e'){     //Si l'on appuie sur la touche 'e' alors l'écran de veille statique se lance.

           	system("clear");
            printf("Voici l'ecran de veille statique\n");
	    	system("/home/sebastien/partage/afficheur");
	    	printf("Pour revenir sur le menu appuyez sur la touche m \n");
            continue;

       		}

       		else if(touche == 'm'){     //Si l'on appuie sur la touche 'm' alors le menu est lancé.

			system("clear");
            menu();

            }

            else if(touche == 'q'){     //Si l'on appuie sur la touche 'q' alors le programme quitte le menu.

            system("clear");
            printf("A bientot\n\n");
			fin = 1;
            		break;
        	}
	}
}

int main (void)             //La fonction main permet de dire au programme l'ordre d'exécution des fonctions définies auparavant.
{
    srand(time(NULL));      //Le programme lance la fonction srand qui va choisjr un nombre au hasard définie entre 1 et 3.
    aleatoire=rand() %3 + 1;


        if(aleatoire==1)    //Si le nombre aléatoire tombe sur 1 alors le programme affiche du texte et le programme 'afficheur' est lancé
        {
        printf("Le chiffre aleatoire est 1, execution du statique \n");
        system("/home/sebastien/partage/afficheur");
        }

        if(aleatoire==2)    //Si le nombre aléatoire tombe sur 2 alors le programme affiche du texte et le programme du dynamique est lancé
        {
        printf("Le chiffre aleatoire est 2, execution du dynamique \n");
        system("/home/sebastien/partage/...");
        }

        if(aleatoire==3)    //Si le nombre aléatoire tombe sur 3 alors le programme affiche du texte et le programme de l'interactif est lancé
        {
        printf("Le chiffre aleatoire est 3, execution de l'intéractif \n");
        system("/home/sebastien/partage/...");
        }
int ecrire_fonction (void){     //La fonction ecrire_fonction est ici utilisé pour écrire les statistiques dans le fichier 'historique.txt.
                                //Elle est placé ici pour utilisé la variable aléatoire afin d'écrire le type d'écran de veille dans les statistiques.

        FILE *fichier = fopen ("historique.txt", "a");

        if (fichier != NULL){   //Les paramètres ci-contres sont utilisés pour pouvoir récupérer l'heure pour qu'elle soit inscrite sur le fichier 'historique.txt'

		time_t secondes;
		struct tm instant;

		time(&secondes);
		instant=*localtime(&secondes);

		int theu = instant.tm_hour, heure0, heure1;
		int tmin = instant.tm_min, min0, min1;
		int tsec = instant.tm_sec, sec0, sec1;


		time_t t = time (NULL);
          	struct tm tm_t = *localtime(&t);
            char s_t[sizeof "JJ/MM/AAAA HH:MM:SS"];

	  	  	strftime(s_t, sizeof s_t, "%d/%m/%y %H:%M:%S", &tm_t); //Cette fonction permet de redéfinir la structure de données utilisée par la fonction time

            if(aleatoire==1)
            {
            fprintf (fichier, "%s Statique;\n", s_t);     //Si la variable aléatoire tombe sur 1 alors le programme statique est lancé et le mot statique est inscrit dans les statistiques.
            }
         	if(aleatoire==2)
            {
            fprintf (fichier, "%s Dynamique;\n", s_t);      //Si la variable aléatoire tombe sur 2 alors le programme dynnamique est lancé et le mot dynamique est inscrit dans les statistiques.
            }
            if(aleatoire==3)
            {
            fprintf (fichier, "%s Interactif;\n", s_t);      //Si la variable aléatoire tombe sur 3 alors le programme interactif est lancé et le mot interactif est inscrit dans les statistiques.
            }
          	fclose (fichier);
          	}
return 0;

}

    printf("\n");
    ecrire_fonction();

    char touche; //On crée ici une variable pour pouvoir utiliser les touches pour le menu.
    printf("Appuyez sur la touche 'm' pour afficher le menu\nAppuyez sur la touche 'Entrée' pour quitter le programme ");
    scanf("%c", &touche);

        if(touche == 'm')
        {
        AffichageMenu();
        menu();
        }
}




