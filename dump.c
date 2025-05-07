int Credit(){
//Affichage des crédits du jeu//
    char tampon[100];

    printf("\033[H\033[2J");
    printf("Voici les credits du jeu : \n\n");
    printf("Jeu : Cy-Fighters\n\n");
    printf("Developpeurs : \n -CAN Axel\n -ROUSSAUX Zachary\n -FARSAN Youssef\n");
    printf("Inspire de : Summoners wars, Pokemon et Hearthstone\n");

    //Choix entre retourner au menu ou quittez le programme//
    printf("\n\nSouhaitez-vous : \n1-Retourner au menu\n\nou\n\n2-Quitter le jeu ?\n\n");
    fgets(tampon, V, stdin);
    int n=VerifScanf(tampon);

    if(n!=1 && n!=2){
        printf("ERREUR, fermeture du programme\n\n");
        exit(1);
    }

    else{
        return(n);
    }
}


int initialisation_equipes(Combattant* equipe_a, Combattant* equipe_b) {
  /*
  Prend deux listes de combattants et initialise tout les combattants comme "NON_DISPO"
  Renvoie 0 si l'opération réussie.
  */

  int i ;
  char* chaine = NULL ;

  chaine = malloc(V) ;

  if ((equipe_a == NULL) || (equipe_b == NULL)) {
    printf("Erreur dans la fonction initialisation_equipes avec les listes combattants.\n") ;
    exit(1) ;
  }
      
  else if (chaine == NULL) {
    printf("Erreur dans fonction initialisation_equipes, l'allocation a échouée\n") ;
    exit(2) ;
  }

  else {
    *chaine = "NON_DISPO" ;
      
    for (i = 0 ; i < 8 ; i++) {
      (combattants + i).nom = chaine ;
    }

    for (i = 0 ; i < 8 ; i++) {
      (combattants + i).nom = chaine ;
    }

    return 0 ;
  }
}


int choix_combattant_correct(Combattant* combattants, int choix) {
  /*
  Retourne 0 si le combattant d'indice choix est dispo, 1 sinon.
  */

  if (choix < 0) {
    printf("Erreur dans la fonction choix_combattant_correct avec la variable choix.\n") ;
    exit(1) ;
  }

  else if (combattants == NULL) {
    printf("Erreur dans la fonction choix_combattant_correct avec la liste des combattants.\n") ; 
    exit(2) ;
  }

  else {
    if (((combattants + choix) -> nom) == "NON_DISPO") {
      return 1 ;
    }

    else {
      return 0 ;
    }
  } 
}

int mettre_dans_equipe(Combattant* tab_combattants, Combattant* equipe, int choix) {
  if (choix < 0) {
    printf("Erreur dans la fonction mettre_dans_equipe, le choix est incorrect.\n") ;
    exit(1) ;  
  }

  else if ((tab_combattants == NULL) || (equipe == NULL)) {
    printf("Erreur dans la fonction mettre_dans_equipe avec les listes de combattants.\n") ;
    exit(2) ;
  }

  else {
    for (int i = 0 ; i <= 8 ; i++) {
      if (((equipe + i) -> nom) == "NON_DISPO") {
        (equipe + i) = 
      }
    }
  }
}


