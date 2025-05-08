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


