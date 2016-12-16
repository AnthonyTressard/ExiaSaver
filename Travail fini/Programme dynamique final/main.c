#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/time.h>

//Déclaration des fonctions
int demandeDelai();
void centrer(const char* str);

int main()
{
    //Nettoyage de la console
    system("clear");

    //Récupération du délai d'actualisation
    int delai;
    delai=demandeDelai();

    while(1)
    {
        //Nettoyage de la console
        system("clear");

        //#########################################
        //Récupération de l'heure stockée dans une structure tm
        time_t secondes;
        struct tm t;
        time(&secondes);
        t =*localtime(&secondes);

        //Conversion de l'heure obtenue en chaine de caractere
        int h0, h1, m0, m1, s0, s1;
        char tab[8];
        if(t.tm_hour<10)
        {
            h0=0;
            h1=t.tm_hour;
        }
        else
        {
            h0=t.tm_hour%10;
            h0=t.tm_hour-h0;
            h0/=10;
            h1=t.tm_hour%10;
        }
        if(t.tm_min<10)
        {
            m0=0;
            m1=t.tm_min;
        }
        else
        {
            m0=t.tm_min%10;
            m0=t.tm_min-h0;
            m0/=10;
            m1=t.tm_min%10;
        }
        if(t.tm_sec<10)
        {
            s0=0;
            s1=t.tm_sec;
        }
        else
        {
            s0=t.tm_sec%10;
            s0=t.tm_sec-h0;
            s0/=10;
            s1=t.tm_sec%10;
        }
        sprintf(tab, "%d%d:%d%d:%d%d", h0, h1, m0, m1, s0, s1);

        //Calcul de la largeur de l'image
        int largeur_image, i;
        char nom_fichier[50], caractere;
        /*for(i=0; i<strlen(tab); i++)
        {
            caractere=tab[i];
            if(caractere==':')//Si le caractère un ':'
            {
                sprintf(nom_fichier, "/Images/Chiffres/points.bmp\n");
            }
            else//Sinon le caractère est un chiffre donc on va chercher son fichier bmp correspondant
            {
                sprintf(nom_fichier, "../Images/Chiffres/%c.bmp\n", caractere);
            }
            printf("Nom du fichier : %s", nom_fichier);

            //Ouverture du fichier
            FILE *fichier=NULL;
            fichier=fopen(nom_fichier, "r");
            if(fichier==NULL){printf("Le fichier ne s'est pas ouvert correctement");}
            else
            {
                while(fgetc(fichier)!='\n'){}
                caractere=fgetc(fichier);
                printf("%c", caractere);
            }

            //Ajout d'un espace entre les caractères
            if(i<8)
            {
                sprintf(nom_fichier, "../Images/Chiffres/espace\n.bmp");
            }
            printf("Nom du fichier : %s", nom_fichier);
        }*/

        //Centrage de l'image
        centrer(tab);

        //Affichage d'un message d'actualisation avec apparition de "." toutes les secondes
        int t_depart=time(NULL), t_ecoule;
        char phrase[50];
        sprintf(phrase, "L'heure va s'actualiser dans %d secondes", delai);//Affichage du message d'actualisation de l'heure
        centrer(phrase);
        for (i = 0; i < delai; i++)//Tant que i ne depasse pas le nombre de secondes demandé par l'utilisateur
        {
            printf(".");//Affichage d'un point
            fflush(stdout);//Actualise l'affichage de la console
            do
            {
                t_ecoule=time(NULL);
            }while(t_ecoule-t_depart==0);
            t_depart=time(NULL);
        }
    }
}

int demandeDelai()
{
    int delai;//Création de la variable
    printf("A quelle frequence souhaitez vous actualiser l'heure ?\nEntrez une duree en secondes : ");//Affichage de la demande
    scanf("%d", &delai);//Stockage de la valeur entrée dans la variable
    return delai;//Revoit de la variable
}

void centrer(const char* str)
{
    unsigned int n;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    for(n=0; n<(w.ws_row-1)/2; n++)
    {
        putchar('\n');
    }
    for(n=0; n<(w.ws_col-strlen(str))/2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
}
