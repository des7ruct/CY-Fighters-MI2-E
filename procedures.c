/* inclusions */
#include "procedures.h"


/* contenu */

void Codex (Combattant* tab, int taille){
    //Affiche les informations de tous les combattants
    FILE* fic = NULL;
    fic=fopen("lore_combattants.txt", "r");
    char ligne[V];

    int j=1;
    for(int i=0; i<taille; i++){
        printf("%d : Nom : %s // Type : ", j, tab[i].nom);
        j++;
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
        printf("Competence 1: %s \nCompetence 2: %s \n", tab[i].competences[0].nom, tab[i].competences[1].nom);
        fgets(ligne, V, fic);
        printf("%s\n\n\n", ligne);
    }
     printf(" 1-Retourner au menu.\n\n");
}

void Tuto() {
    /* Affichage du tutoriel */
  
    printf(" Bienvenue dans le tutoriel de CY-Fighters\n\n") ;
    printf(" Chaque joueur choisira entre 3 et 6 combattants (en fonction du mode) parmis la liste des 18 combattants disponibles.\n") ;
    printf(" Chaque combattant possede une type : Eau, Feu ou Plante.\n") ;
    printf(" Le type Eau est faible au type Plante.\n") ;
    printf(" Le type Plante est faible au type Feu.\n") ;
    printf(" Le type Feu est faible au type Eau.\n") ;
    printf(" Chaque combattant possedera également 2 competences (actives) et un passif qui lui sont propre. Les competences ont des temps de chargements\n") ;
    printf(" tandis que les passifs ont effet a chaque tours.\n") ;
    printf(" Durant leur tour, chaque combattant aura 4 choix possibles :\n") ;
    printf("- Il pourra utiliser une attaque normale, pour infliger des degats.\n") ;
    printf("- Il pourra se défendre, pour avoir un bonus de réduction de degats jusqu'à son prochain tour\n") ;
    printf("- Il pourra utiliser une competence spéciale, pour infliger plus de degats ou mettre un effet a un autre combattant (ou lui même)\n") ;
    printf("- Ou alors, si il en possede, il pourra utiliser un consommable.\n") ;
    printf(" Le combattant ayant le plus de stamina sera celui qui jouera sont tour en premier.\n\n") ;
    printf(" Si vous avez des combattants en reserve, il remplaceront vos combattants K.O au 3eme tour.\n\n") ;
    printf(" 1-Retourner au menu.\n\n") ;
}


void Menu(){
    int nb_combattant;
    nb_combattant=Calcul_Nb_Combattant();
    Combattant* tab;
    tab=RemplirTabCombattant();
    int n=0;
    char tampon[100];
    printf(" Choisissez une option en entrant le chiffre adequat\n\n ");
    printf("1-Jouer\n ");
    printf("2-Codex\n ");
    printf("3-Tutoriel\n ");
    printf("4-Credits\n ");
    printf("5-Quitter le jeu\n\n");
    printf("Reponse :   ");

    //récupère la chaîne avec un fgets pour faciliter la vérification//
    fgets(tampon, V, stdin);
    n=VerifScanf(tampon);

    if(n==-1){
        Menu();
    }

    switch (n){

        case 1:
            Combat(tab, nb_combattant, MAX_COMBATTANTS_EQUIPE);
            break;


        case 2:
            n=0;
            Codex(tab, nb_combattant);
            while(n!=1){
                fgets(tampon, V,stdin);
                n=VerifScanf(tampon);
                if(n!=1){
                    printf("Erreur, pour retourner au menu, entrez '1'\n ");
                }
            }
                Menu();
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
                Menu();

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



void Creation_Equipe(Combattant* tab, int nb_combattant_tot, int nb_combattant_eq, Equipe* A, Equipe* B) {
     /*
      Remplis 2 équipes en fonction des choix de joueurs avec deux phases :
        Une phase de sélection de combattant, 2 par 2.
        Et une phase de bannissement pour bannir un combattant par equipe.
     */

        printf("\033[H\033[2J") ;
        char tampon[V] ;


        printf("Match : %s VS %s\n", A -> nom, B -> nom);
        sleep(3);
        printf("\033[H\033[2J") ;




        /* Tirage de l'équipe choisissant en premier un combattant */
        int num_choix = 1 ;
        int choix ;
        int piece = pile_ou_face() ;

        switch (piece) {


            case 0 :
                /* Choix des combattants de chaque equipe */
                printf("L'Equipe %s choisit en premier.\n\n", A -> nom);
                sleep(2);
                for (int i = 0 ; i < nb_combattant_eq / 2 ; i++) {
                    printf("Voici la liste des combattants :\n\n") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;

                    printf("Choix de 2 combattants supplementaire.\n") ;
                    printf("Equipe %s choisit un combattant en saisissant son numero\n", A -> nom) ;
                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;


                    printf("Vous avez selectionne %s \n", tab[choix].nom) ;

                    if (mettre_dans_equipe(tab, A, choix) != 0) {
                        printf("ERREUR D'AFFECTION\n") ;
                        exit(14) ;
                    }

                    num_choix++ ;

                    printf("\033[H\033[2J") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;


                    if (mettre_dans_equipe(tab, A, choix) != 0) {
                        printf("ERREUR D'AFFECTION 2") ;
                        exit(14) ;
                    }

                    num_choix = 1 ;

                    printf("Voici la liste des combattants :\n\n") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    printf("Choix de 2 combattants.\n") ;
                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;
                    printf("\033[H\033[2J") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    printf("Vous avez selectionne %s \n", tab[choix].nom) ;

                    if (mettre_dans_equipe(tab, B, choix) != 0) {
                        printf("ERREUR D'AFFECTION") ;
                        exit(14) ;
                    }

                    num_choix++ ;

                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;
                    printf("\033[H\033[2J");
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    printf("Vous avez selectionne %s \n", tab[choix].nom) ;

                    if (mettre_dans_equipe(tab, B, choix) != 0) {
                        printf("ERREUR D'AFFECTION 2") ;
                        exit(14) ;
                    }

                    num_choix = 1 ;
                  }


        /* Phase de bannissement */
        printf("\033[H\033[2J");
        printf("Equipe %s :\n", A -> nom) ;
        Liste_Combattant(A -> combattants, nb_combattant_eq) ;
        printf("Choisissez un combattant a bannir en selectionnant son numero\n") ;
        printf("Choix : ") ;
        fgets(tampon, V, stdin) ;
        choix = VerifScanf(tampon) ;
        bannir_combattant(A, choix) ;

        switch(choix){
            case 1 :
                A -> combattants[0]= A -> combattants[3];
                break;

            case 2 :
                A -> combattants[1]= A -> combattants[3];
                break;

            case 3 :
                A -> combattants[2] = A-> combattants[3];
                break;

            case 4 :
                break;

            default :
                printf("ERREUR BAN");
                exit(17);

        }

        printf("\033[H\033[2J");
        printf("Equipe %s :\n", B -> nom) ;
        Liste_Combattant(B -> combattants, nb_combattant_eq) ;
        printf("Choisissez un combattant a bannir en selectionnant son numero\n") ;
        printf("Choix : ") ;
        fgets(tampon, V, stdin) ;
        choix = VerifScanf(tampon) ;
        bannir_combattant(B, choix) ;

        switch(choix){
            case 1 :
                A -> combattants[0]= B -> combattants[3];
                break;

            case 2 :
                A -> combattants[1]= B -> combattants[3];
                break;

            case 3 :
                A -> combattants[2] = B-> combattants[3];
                break;

            case 4 :
                break;

            default :
                printf("ERREUR BAN");
                exit(17);

        }

        printf("Voici les 2 equipes : \n %s:\n ", A -> nom);
        Liste_Combattant(A -> combattants, nb_combattant_eq-1) ;
        printf("%s:\n", B -> nom);
        Liste_Combattant(B -> combattants, nb_combattant_eq-1) ;

                break;


         case 1 :
                /* Choix des combattants de chaque equipe */
                printf("L'Equipe %s choisit en premier.\n\n", B -> nom);
                sleep(2);
                for (int i = 0 ; i < (nb_combattant_eq / 2) ; i++) {
                    printf("Voici la liste des combattants :\n\n");
                    Liste_Combattant(tab, nb_combattant_tot) ;

                    printf("Choix de 2 combattants supplementaire.\n") ;
                    printf("Equipe %s choisit un combattant en saisissant son numero\n", B -> nom) ;
                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;


                    printf("Vous avez selectionne %s \n", tab[choix].nom) ;

                    if (mettre_dans_equipe(tab, B, choix) != 0) {
                        printf("ERREUR D'AFFECTION") ;
                        exit(14) ;
                    }

                    num_choix++ ;

                    printf("\033[H\033[2J") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;


                    if (mettre_dans_equipe(tab, B, choix) != 0) {
                        printf("ERREUR D'AFFECTION 2") ;
                        exit(14) ;
                    }

                    num_choix = 1 ;

                    printf("Voici la liste des combattants :\n\n") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    printf("Choix de 2 combattants.\n") ;
                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;
                    printf("\033[H\033[2J") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    printf("Vous avez selectionne %s \n", tab[choix].nom) ;

                    if (mettre_dans_equipe(tab, A, choix)!=0) {
                        printf("ERREUR D'AFFECTION");
                        exit(14);
                    }

                    num_choix++ ;

                    choix = Choix_Combattant(tab, nb_combattant_tot, num_choix) ;
                    printf("\033[H\033[2J") ;
                    Liste_Combattant(tab, nb_combattant_tot) ;
                    printf("Vous avez selectionne %s \n", tab[choix].nom) ;

                    if (mettre_dans_equipe(tab, A, choix) != 0) {
                        printf("ERREUR D'AFFECTION 2") ;
                        exit(14) ;
                    }

                    num_choix = 1 ;
        }

        /* Phase de bannissement */

        printf("\033[H\033[2J");
        printf("Equipe %s :\n", B -> nom);
        Liste_Combattant(B -> combattants, nb_combattant_eq) ;
        printf("Choisissez un combattant a bannir en selectionnant son numero\n") ;
        printf("Choix : ") ;
        fgets(tampon, V, stdin) ;
        choix = VerifScanf(tampon) ;
        bannir_combattant(B, choix-1) ;

        switch(choix){
            case 1 :
                B -> combattants[0]= B -> combattants[3];

                break;

            case 2 :
                B -> combattants[1]= B -> combattants[3];

                break;

            case 3 :
                B -> combattants[2] = B-> combattants[3];

                break;

            case 4 :

                break;

            default :
                printf("ERREUR BAN");
                exit(17);

        }

        printf("\033[H\033[2J");
        printf("Equipe %s :\n", A -> nom) ;
        Liste_Combattant(A -> combattants, nb_combattant_eq) ;
        printf("Choisissez un combattant a bannir en selectionnant son numero\n") ;
        printf("Choix : ") ;
        fgets(tampon, V, stdin) ;
        choix = VerifScanf(tampon) ;
        bannir_combattant(A, choix-1) ;

        switch(choix){
            case 1 :
                A -> combattants[0]= A -> combattants[3];

                break;

            case 2 :
                A -> combattants[1]= A -> combattants[3];

                break;

            case 3 :
                A -> combattants[2] = A-> combattants[3];

                break;

            case 4 :

                break;

            default :
                printf("ERREUR BAN");
                exit(17);

        }

        printf("Voici les 2 equipes : \n A:\n ") ;
        Liste_Combattant(A -> combattants, nb_combattant_eq-1) ;
        printf("B:\n") ;
        Liste_Combattant(B -> combattants, nb_combattant_eq-1) ;

        break ;

         default :
            printf("ERREUR PILE OU FACE") ;
            exit(16) ;
        }
 }






void Interface_Combat(Equipe* A, Equipe* B, Combattant Attaquant){


        char *c1, *c2, *c3, *c4, *c5, *c6;
        char* type;

        //Verifie quels combattants sont KO//

        if(A -> combattants[0].pv_courants==0){
            c1="%";
        }
        else{
            c1="1";
        }

        if(A -> combattants[1].pv_courants==0){
            c2="%";
        }
        else{
            c2="2";
        }

        if(A -> combattants[2].pv_courants==0){
            c3="%";
        }
        else{
            c3="3";
        }

        if(B -> combattants[0].pv_courants==0){
            c4="%";
        }
        else{
            c4="4";
        }

        if(B -> combattants[1].pv_courants==0){
            c5="%";
        }
        else{
            c5="5";
        }

        if(B -> combattants[2].pv_courants==0){
            c6="%";
        }
        else{
            c6="6";
        }

        //Affichage//

    for(int i=0; i<115; i++){
            if(i==0){
                printf("\xE2\x94\x8C");
            }
            if(i==114){
              printf("\xE2\x94\x90");
            }
            else{
                printf("\xE2\x94\x80");
            }
    }

    for(int j=0; j<30; j++){
        printf("\n");
        for(int k=0; k<116; k++){



            if(j==3){
                printf("| Equipe : %-103s |", A -> nom);
                break;

            }

            else if(j==5){
                printf("| [%s] %-15s %-9s [%s] %-15s %-9s [%s] %-15s %-26s      |", c1, A -> combattants[0].nom, convertir_type(A -> combattants[0].type), c2, A -> combattants[1].nom, convertir_type(A -> combattants[1].type), c3, A -> combattants[2].nom, convertir_type(A -> combattants[2].type));
                break;
            }

            else if(j==6){
                printf("| PV : %d/%d", A -> combattants[0].pv_courants, A -> combattants[0].pv_max_courants);
                for(int i=0; i<18; i++){
                    printf(" ");
                }
                printf("PV : %d/%d", A -> combattants[1].pv_courants, A -> combattants[1].pv_max_courants);
                for(int i=0; i<12; i++){
                    printf(" ");
                }
                printf("PV : %d/%d", A -> combattants[2].pv_courants, A -> combattants[2].pv_max_courants);
                for(int i=0; i<36; i++){
                    printf(" ");
                }
                printf("|");
                break;
            }



            else if(j==17){
                printf("| Equipe : %-103s |", B -> nom);
                break;

            }


            else if(j==20){
                printf("| [%s] %-15s %-9s [%s] %-15s %-9s [%s] %-15s %-21s    |", c4, B -> combattants[0].nom, convertir_type(B -> combattants[0].type), c5, B -> combattants[1].nom,convertir_type(B -> combattants[1].type), c6, B -> combattants[2].nom, convertir_type(B -> combattants[2].type));
                break;
            }

            else if(j==21){
                printf("| PV : %d/%d", B -> combattants[0].pv_courants, B -> combattants[0].pv_max_courants);
                for(int i=0; i<18; i++){
                    printf(" ");
                }
                printf("PV : %d/%d", B -> combattants[1].pv_courants, B -> combattants[1].pv_max_courants);
                for(int i=0; i<12; i++){
                    printf(" ");
                }
                printf("PV : %d/%d", B -> combattants[2].pv_courants, B -> combattants[2].pv_max_courants);
                for(int i=0; i<36; i++){
                    printf(" ");
                }
                printf("|");

                break;
            }



            else if(k==0 || k==115){
                printf("\xE2\x94\x82");
            }


            else{
                printf(" ");
            }


        }


    }

    printf("\n");

    //Attaquant

    for(int i=0; i<115; i++){
            if(i==0){
                printf("\xE2\x94\x94");
            }
            if(i==114){
              printf("\xE2\x94\x98");
            }
            else{
                printf("\xE2\x94\x80");
            }
    }

    for(int j=0; j<15; j++){
        printf("\n");
        for (int i=0; i<116; i++){
            if(j==1){
                printf(" Attaquant : %s ", Attaquant.nom);
                break;
            }

            else if(j==2){
                printf(" 1 : %s  %d/%d ", Attaquant.competences[0].nom, Attaquant.competences[0].rechargement_courant, Attaquant.competences[0].rechargement);
                break;
            }
            else if(j==3){
                printf(" %s ", Attaquant.competences[0].description);
                break;
            }

            else if(j==5){
                printf(" 2 : %s  %d/%d ", Attaquant.competences[1].nom, Attaquant.competences[1].rechargement_courant, Attaquant.competences[1].rechargement);
                break;
            }
            else if(j==6){
                printf(" %s ", Attaquant.competences[1].description);
                break;
            }
            else if(j==8){
                printf(" 3- Attaque basique");
                break;
            }

            else if(j==10){
                printf("\n 4- Bloquer");
                break;
            }
        }
    }

 }


void Combat(Combattant* tab, int n_tot, int n_eq){
    int victoire=0;
    int compteur_tours=1;
    char tampon[V];
     /* Initialisations des équipes */
        Equipe A ;
        initialisation_combattants_equipe(&A) ;
        printf("Choisissez un nom pour la premiere equipe:\n\nChoix : ");
        fgets(tampon, V, stdin);
        A.nom=tampon;
        Equipe B ;
        initialisation_combattants_equipe(&B) ;
        printf("Choisissez un nom pour la deuxieme equipe:\n\nChoix : ");
        fgets(tampon, V, stdin);
        B.nom=tampon;
        printf("%s\n\n", A.nom);
        printf("\033[H\033[2J") ;
        Supp_SautDeLigne(A.nom);
        Supp_SautDeLigne(B.nom);

        //Creation des équipes : Ajout combattant//
        Creation_Equipe(tab, n_tot, n_eq, &A, &B);


        //Initialisation du combat//
        initialisation_effets(&A);
        initialisation_effets(&B);

        initialisation_combat(&A);
        initialisation_combat(&B);

        Combattant Attaquant;

        //Début du combat, une boucle correspond à un tour//
        while(victoire==0){
            int choix=-1;
            int equipe;
            Attaquant.nom=calcul_tour(&A, &B);

            Attaquant=Compare_Attaquant(&A, &B, Attaquant);
            printf("%d %d\n", (Attaquant.competences + 1) -> rechargement_courant, (Attaquant.competences + 1) -> rechargement) ;
            debut_tour(&Attaquant) ;

            if(Attaquant.nom==A.combattants[0].nom || Attaquant.nom==A.combattants[1].nom || Attaquant.nom==A.combattants[2].nom){
                equipe=1;
            }

            else if(Attaquant.nom==B.combattants[0].nom || Attaquant.nom==B.combattants[1].nom || Attaquant.nom==B.combattants[2].nom){
                equipe=2;
            }

            Interface_Combat(&A, &B, Attaquant);
            //Choix de l'action
            while(choix<1 || choix>4){
                fgets(tampon, V, stdin);
                choix=VerifScanf(tampon);
                if(choix<1 || choix>4){
                    printf("Choix invalide, selectionnez une nouvelle action");
                }
            }

            //résultat de l'action

            switch(choix){

                case 1 :
                    choix=0;
                    printf("Qui souhaitez vous attaquer ?\n");
                    while(choix<1 ||choix >6){
                        fgets(tampon, V, stdin);
                        choix=VerifScanf(tampon);
                        if(choix<1 ||choix >6){
                            printf("Erreur, veuillez de nouveau choisir une cible");
                        }
                        if((equipe==1) && (choix==1 || choix==2 || choix==3)){
                            printf("Choisissez un adversaire\n");
                            choix=0;
                           }
                        if((equipe==2) && (choix==4 || choix==5 || choix==6)){
                            printf("Choisissez un adversaire\n");
                            choix=0;
                           }
                    }

                    switch(choix){

                        case 1 :
                            utiliser_competence(&Attaquant, &A.combattants[1], 0) ;
                            break;

                        case 2 :
                            utiliser_competence(&Attaquant, &A.combattants[1], 0);
                            break;

                        case 3 :
                            utiliser_competence(&Attaquant, &A.combattants[2], 0);
                            break;

                        case 4 :
                            utiliser_competence(&Attaquant, &B.combattants[0], 0);
                            break;

                        case 5 :
                            utiliser_competence(&Attaquant, &B.combattants[1], 0);
                            break;

                        case 6 :
                            utiliser_competence(&Attaquant, &B.combattants[2], 0);
                            break;

                    }


                    break;

                case 2 :
                    choix=0;
                    printf("Qui souhaitez vous attaquer ?\n");
                    while(choix<1 ||choix >6){
                        fgets(tampon, V, stdin);
                        choix=VerifScanf(tampon);
                        if(choix<1 ||choix >6){
                            printf("Erreur, veuillez de nouveau choisir une cible");
                        }
                        if((equipe==1) && (choix==1 || choix==2 || choix==3)){
                            printf("Choisissez un adversaire\n");
                            choix=0;
                           }
                        if((equipe==2) && (choix==4 || choix==5 || choix==6)){
                            printf("Choisissez un adversaire\n");
                            choix=0;
                           }
                    }

                    switch(choix){

                        case 1 :
                            utiliser_competence(&Attaquant, &A.combattants[1], 1) ;
                            break;

                        case 2 :
                            utiliser_competence(&Attaquant, &A.combattants[1], 1);
                            break;

                        case 3 :
                            utiliser_competence(&Attaquant, &A.combattants[2], 1);
                            break;

                        case 4 :
                            utiliser_competence(&Attaquant, &B.combattants[0], 1);
                            break;

                        case 5 :
                            utiliser_competence(&Attaquant, &B.combattants[1], 1);
                            break;

                        case 6 :
                            utiliser_competence(&Attaquant, &B.combattants[2], 1);
                            break;

                    }

                    break;


                case 3 :
                    choix=0;
                    printf("Qui souhaitez vous attaquer ?\n");
                    while(choix<1 ||choix >6){
                        fgets(tampon, V, stdin);
                        choix=VerifScanf(tampon);
                        if(choix<1 ||choix >6){
                            printf("Erreur, veuillez de nouveau choisir une cible");
                        }
                        if((equipe==1) && (choix==1 || choix==2 || choix==3)){
                            printf("Choisissez un adversaire\n");
                            choix=0;
                           }
                        if((equipe==2) && (choix==4 || choix==5 || choix==6)){
                            printf("Choisissez un adversaire\n");
                            choix=0;
                           }
                    }

                    switch(choix){

                        case 1 :
                            attaque_basique(&Attaquant, &A.combattants[0]) ;
                            break;

                        case 2 :
                            attaque_basique(&Attaquant, &A.combattants[1]);
                            break;

                        case 3 :
                            attaque_basique(&Attaquant, &A.combattants[2]);
                            break;

                        case 4 :
                            attaque_basique(&Attaquant, &B.combattants[0]);
                            break;

                        case 5 :
                            attaque_basique(&Attaquant, &B.combattants[1]);
                            break;

                        case 6 :
                            attaque_basique(&Attaquant, &B.combattants[2]);
                            break;

                    }

                    break;


                case 4 :
                    bloquer(&Attaquant);

                    break;
            }

            fin_de_tour(&Attaquant) ;

        }
 }


void vide_malloc(){
    free(tab);
    for (int i=0; i<18; i++){
        free(tab[i].nom);
        free(tab[i].competences);
        for(int j=0; j<2; j++){
            free(tab[i].competences.nom);
            free(tab[i].competences[j].description);
            free(tab[i].competences[j].phases);
            for(int k=0; k<10; k++){
                free(tab[i].competences[j].phases[k].effets_positifs);
                free(tab[i].competences[j].phases[k].effets_negatifs);
            }
        }
    }
    free(chaines);
    free(equipe.combattants);
    for(int l=0; l<8; l++){
        free(equipe.combattants[i].effets_positifs);
        free(equipe.combattants[i].effets_negatifs);
    }
}
        
