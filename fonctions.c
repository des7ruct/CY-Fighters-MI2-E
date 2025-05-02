#include "fonctions.h"

while ( ((choix = getchar()) != '\n') && (choix != EOF) ) { }

printf("\033[H\033[2J");


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


/* Pourcentage initial de coup critique */
#define TAUX_CRITIQUE 15


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

/* Pourcentage initial de bonus de type */
#define TAUX_TYPE 0.25

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
