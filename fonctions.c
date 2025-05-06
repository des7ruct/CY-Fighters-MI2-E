#include "fonctions.h"


int VerifNb(char* test){
//Vérifie que chaque caractère est bien un chiffre//
    for(int i=0; test[i]!='\0'; i++){
        if(test[i]<'0' || test[i]>'9'){
            return 0;
        }
    }
    return(1);
}


int VerifScanf(char* test){
    //Vérifie que la chaine reçu ne soit pas vide//
    if (test==NULL){
        printf("\033[H\033[2J");
        printf("ERREUR, veuillez-recommencer\n");
        return(-1);
    }
    else if(test!=NULL){
        test[strcspn(test, "\n")]=0;
    }
    /*Après avoir vérifier que la chaine ne contiennent que des chiffres,
    retourne la chaîne en tant que int*/
    if(VerifNb(test)){
        return(atoi(test));
    }
    else{
        printf("\033[H\033[2J");
        printf("ERREUR, veuillez-recommencer\n");
        return(-1);
    }
    return(0);

}


//Fonction de réduction des dégats par l'esquive

float DegatsEsquive(int x, int y){
/* Calcul les dégats réduis par l'agilité. On calcul le quotient des
deux esquives et le résultat nous donnera le montant de dégats esquivé.
*/
    if(x<0 || y<0){
        exit(1);
    }

    float a=x;
    float b=y;
    float coeff=1-(a/b);
    if (x>y){
        coeff=0;
    }
    return coeff;

}



int aleatoire(int minimum, int maximum) {
  /*
  Fonction prenant un minimum et un maximum positifs et génére un nombre aléatoire entre les deux. 
  */
  
  int resultat ;
  
  if ((minimum >= maximum) || (maximum <= 0)) {
    printf("Erreur dans la fonction aleatoire avec les nombres minimums et maximums.\n") ;
    exit(1) ;
  }
  
  resultat = minimum + (rand() % ((maximum - minimum) + 1)) ;
  
  if ((resultat < 0) || (resultat < minimum) || (resultat > maximum)) {
    printf("Erreur dans la fonction aleatoire avec le retour de la fonction.\n") ;
    exit(2) ;
  }

  return resultat ;
}


int multiplicateur_critique(int valeur_critique) {
  /*
  Prend une valeur de pourcentage de chance d'effectuer un coup critique et renvoie 2 si le coup est critique, 1 sinon.
  */
    
  if (valeur_critique < TAUX_CRITIQUE) {
    printf("Erreur dans la fonction critique avec le pourcentage de coup critique.\n") ;
    exit(1) ;
  }

  else if (valeur_critique >= 100) {
    return 2 ;      
  }

  else {
    if (aleatoire(1, 100) > valeur_critique) {
      return 1 ;  
    }

    else {
      return 2 ;
    }
  }
}

int application_effet() {
  /*
  A partir de la constante APPLICATION_EFFETS, renvoie 1 si l'effet s'applique et 0 sinon.
  */

  if ((APPLICATION_EFFETS < 0) || (APPLICATION_EFFETS > 100)) {
    printf("Erreur dans la fonction application_effet avec la constante APPLICATION_EFFETS.") ;
    exit(1) ;
  }

  else if (APPLICATION_EFFETS == 100) {
    return 1 ;
  }

  else {
    if (aleatoire(1, 100) > APPLICATION_EFFETS) {
      return 0 ;
    }

    else {
      return 1 ;
    }
  }
}

float multiplicateur_type(int type_lanceur, int type_cible) {
  /* 
  Fonction prenant le type du lanceur de l'attaque et le type de la cible et renvoie
  1 + TAUX_TYPE si le lanceur est en avantage, 1 si les types sont identiques et 1 - TAUX_TYPE sinon.
  */

  if ((type_lanceur != FEU) && (type_lanceur != PLANTE) && (type_lanceur != EAU)) {
    printf("Erreur dans la fonction multiplicateur type avec le type du lanceur.\n") ;
    exit(1) ;
  }

  else if ((type_cible != FEU) && (type_cible != PLANTE) && (type_cible != EAU)) {
    printf("Erreur dans la fonction multiplicateur type avec le type de la cible.\n") ;
    exit(2) ;
  }

  else {
    if (type_lanceur == type_cible) {
      return 1 ;  
    }

    else if(((type_lanceur == FEU) && (type_cible == PLANTE)) || ((type_lanceur == PLANTE) && (type_cible == EAU)) || ((type_lanceur == EAU) && (type_cible == FEU))) {
      return 1 + TAUX_TYPE ;
    }

    else {
      return 1 - TAUX_TYPE ;
    }
  }
}


float Calcul_Coeff(char* stats){
    //Calcul le coefficient pour calculer la valeur de la stat en fonction de sa qualité
    
    if (strcmp(stats, "HAUT")==0){
        return(1);
    }
    else if(strcmp(stats, "MOYEN")==0){
        return(0.75);
    }
    else if (strcmp(stats, "BAS")==0){
        return(0.5);
    }
    else{
        printf("ERREUR, Fermeture du programme");
        exit(2);
    }
    return;

}



Combattant* RemplirTabCombattant(){
    //Crée un tableau avec tous les combattants disponible
    
    Combattant* tab;
    int nb_combattants;
    FILE* fic=NULL;
    fic=fopen("combattants.txt", "r");
    char ligne[V];
    
    //Calcul le nombre de combattants
    if(fic!=NULL){
        int nb_ligne=0;
        while(fgets(ligne, V, fic)){
            nb_ligne++;
        }
        rewind(fic);

        nb_combattants=nb_ligne/2;

        //Création du tableau de combattant avec allocation dynamique
        tab = malloc(sizeof(Combattant) * nb_combattants);
        if(tab==NULL){
            printf("Erreur, sortie du programme");
            exit(2);
        }
        
        //Remplit le tableau avec tous les combattants et leur stats
        char ligne_stats[V];
        float coeff;
        int type=1;
        for(int i=0; i<nb_combattants; i++){
            tab[i].nom=malloc(V);
            fgets(tab[i].nom, V, fic);

            fgets(ligne_stats, V, fic);
            char* pvmax=strtok(ligne_stats, " ");
            tab[i].pv_max = PVMAX_BASE * Calcul_Coeff(pvmax);
            char* att=strtok(NULL, " ");
            tab[i].attaque = ATTAQUE_BASE * Calcul_Coeff(att);
            char* def=strtok(NULL, " ");
            tab[i].defense = DEFENSE_BASE * Calcul_Coeff(def);
            char* agi=strtok(NULL, " ");
            tab[i].agilite = AGILITE_BASE * Calcul_Coeff(agi);
            char* vit=strtok(NULL, "\n");
            tab[i].vitesse = VITESSE_BASE * Calcul_Coeff(vit);
            
            //Application du type, sachant qu'ils sont triés dans le fichier : FEU - PLANTE - EAU
            tab[i].type=type;
            if(type==1 || type==2){
                type++;
            }
            else if(type==3){
                type=1;
            }
            else{
                printf("ERREUR de type");
                exit(3);
            }

        }


       fclose(fic);
    }
    else{
        printf("ERREUR, Echec d'ouverture du fichier\n\n\n");
        exit(1);
    }
    Affiche_tab(tab, nb_combattants);
    return(tab);
}

