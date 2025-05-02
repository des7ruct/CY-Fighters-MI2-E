/* inclusions */
#include "procedures.h"


/* contenu */


void Menu(){
    int n=0;
    char tampon[100];
    printf(" Choisissez une option en entrant le chiffre adequat\n\n 1-Jouer contre un autre joueur\n 2-Jouer contre l'ordinateur\n");
    printf(" 3-Tutoriel\n 4-Credits\n 5-Quitter le jeu\n\n");
    printf("Reponse :   ");

    // récupère la chaîne avec un fgets pour faciliter la vérification//
    fgets(tampon, V, stdin);
    n=VerifScanf(tampon);

    if(n==-1){
        Menu();
    }

    switch (n){

        case 1:

            break;


        case 2:

            break;


        case 3:

            break;

        
        case 4:
            /* 
                Affiche les crédits et ferme le programme ou redirige 
                au menu selon le choix de l'utilisateur    
            */
            n=Credit();
            if(n==1){
                printf("\033[H\033[2J");
                Menu();
            }
            else if(n==2){
                printf("Fermeture du programme");
                exit(0);
            }
            else{
                printf("ERREUR, fermeture du programme\n");
                exit(1);
            }
            break;
            

        case 5:
            // Ferme le programme//
            printf("Merci d'avoir joue a notre jeu !");
            exit(0);
            break;


        default :
            printf("\033[H\033[2J");
            printf("Choix invalide, veuillez recommencer\n\n");
            Menu();
            break;


    }
}
