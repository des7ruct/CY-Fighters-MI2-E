/* inclusions */
#include "procedures.h"


/* contenu */

void Tuto(){
//Affichage du tutoriel//
    printf(" Bienvenue dans le tutoriel de CY-Fighters\n\n");
    printf(" Chaque joueur choisira entre 3 et 6 combattants (en fonction du mode) parmis la liste des 18 combattants disponibles.\n");
    printf(" Chaque combattant possede une type : Eau, Feu ou Plante.\n");
    printf(" Le type Eau est faible au type Plante.\n");
    printf(" Le type Plante est faible au type Feu.\n");
    printf(" Le type Feu est faible au type Eau.\n");
    printf(" Chaque combattant possedera également 2 competences (actives) et un passif qui lui sont propre. Les competences ont des temps de chargements\n");
    printf(" tandis que les passifs ont effet a chaque tours.\n");
    printf(" Durant leur tour, chaque combattant aura 4 choix possibles :\n");
    printf("- Il pourra utiliser une attaque normale, pour infliger des degats.\n");
    printf("- Il pourra se défendre, pour avoir un bonus de réduction de degats jusqu'à son prochain tour\n");
    printf("- Il pourra utiliser une competence spéciale, pour infliger plus de degats ou mettre un effet a un autre combattant (ou lui même)\n");
    printf("- Ou alors, si il en possede, il pourra utiliser un consommable.\n");
    printf(" Le combattant ayant le plus de stamina sera celui qui jouera sont tour en premier.\n\n");
    printf(" Si vous avez des combattants en reserve, il remplaceront vos combattants K.O au 3eme tour.\n\n");
    printf(" 1-Retourner au menu.\n\n");

}

void Menu(){
    int n=0;
    char tampon[100];
    printf(" Choisissez une option en entrant le chiffre adequat\n\n 1-Jouer\n 2-Codex\n");
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
            n=0;
            Tuto();
            while(n!=1){
                fgets(tampon, V,stdin);
                n=VerifScanf(tampon);
                if(n!=1){
                    printf("Erreur, pour retourner au menu, entrez '1'\n ");
                }

            }
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

void Affiche_tab(Combattant* tab, int taille){
    //Affiche les informations de tous les combattants
    for(int i=0; i<taille; i++){
        printf("Nom : %s // Type : ", tab[i].nom);
        switch (tab[i].type){
            case 1:
                printf("Feu");
                break;

            case 2:
                printf("Plante");
                break;

            case 3:
                printf("Eau");
                break;

            default:
                printf("ERREUR");
                exit(4);
        }
        printf("\n Pvmax : %d / Attaque : %d / Defense : %d / Agilite : %d / Vitesse : %d \n", tab[i].pv_max, tab[i].attaque, tab[i].defense, tab[i].agilite, tab[i].vitesse);
        printf("Competence 1: %s \nCompetence 2: %s \n\n\n", tab[i].competences[0].nom, tab[i].competences[1].nom);
    }
}



void Creation_Equipe(Combattant* tab, int nb_combattant_tot, int nb_combattant_eq){
    printf("\033[H\033[2J");

    //Initialisations des équipes
    Equipe A;
    initialisation_combattants_equipe(&A);
    Equipe B;
    initialisation_combattants_equipe(&B);



    //Tirage de l'équipe choisissant en premier un combattant
    int num_choix=1;
    int choix;
    int piece=0;
    int tampon[V];

    switch(piece){


        case 0:
            //Choix des combattants de chaque equipe
            printf("L'Equipe A choisit en premier.\n\n");
            for (int i=0; i<nb_combattant_eq/2; i++){
            printf("Voici la liste des combattants :\n\n");
            Liste_Combattant(tab, nb_combattant_tot);

            printf("Choix de 2 combattants supplémentaire.\n");
            printf("Equipe A choisit un combattant en saisissant son numero\n");
            choix=Choix_Combattant(tab, nb_combattant_tot, num_choix);


            printf("Vous avez selectionne %s \n", tab[choix].nom);
            if(mettre_dans_equipe(tab, &A, choix)!=0){
                printf("ERREUR D'AFFECTION");
                exit(14);
            }
            num_choix++;

            printf("\033[H\033[2J");
            Liste_Combattant(tab, nb_combattant_tot);
            choix=Choix_Combattant(tab, nb_combattant_tot, num_choix);


            if(mettre_dans_equipe(tab, &A, choix)!=0){
                printf("ERREUR D'AFFECTION 2");
                exit(14);
            }
            num_choix=1;

            printf("Voici la liste des combattants :\n\n");
            Liste_Combattant(tab, nb_combattant_tot);
            printf("Choix de 2 combattants.\n");
            choix=Choix_Combattant(tab, nb_combattant_tot, num_choix);
            printf("\033[H\033[2J");
            Liste_Combattant(tab, nb_combattant_tot);
            printf("Vous avez selectionne %s \n", tab[choix].nom);
            if(mettre_dans_equipe(tab, &B, choix)!=0){
                printf("ERREUR D'AFFECTION");
                exit(14);
            }
            num_choix++;

            choix=Choix_Combattant(tab, nb_combattant_tot, num_choix);
            printf("\033[H\033[2J");
            Liste_Combattant(tab, nb_combattant_tot);
            printf("Vous avez selectionne %s \n", tab[choix].nom);
            if(mettre_dans_equipe(tab, &B, choix)!=0){
                printf("ERREUR D'AFFECTION 2");
                exit(14);
            }
            num_choix=1;
            }
    }

    printf("Equipe A :\n") ;
    Liste_Combattant(A.combattants, nb_combattant_eq) ;
    printf("Choisissez un combattant a bannir en selectionnant son numero\n");
    printf("Choix : ");
    fgets(tampon, V, stdin);
    choix=VerifScanf(tampon);
    bannir_combattant(&A, choix);

    printf("Equipe B :\n") ;
    Liste_Combattant(B.combattants, nb_combattant_eq) ;
     printf("Choisissez un combattant a bannir en selectionnant son numero\n");
    printf("Choix : ");
    fgets(tampon, V, stdin);
    choix=VerifScanf(tampon);
    bannir_combattant(&B, choix);

    printf("Voici les 2 equipes : \n A:\n ");
    Liste_Combattant(A.combattants, nb_combattant_eq) ;
    printf("B:\n");
    Liste_Combattant(B.combattants, nb_combattant_eq);
}
