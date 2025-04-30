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
    printf("Erreur dans la fonction aleatoire avec les nombres minimums et maximums.") ;
    exit(1) ;
  }
  
  resultat = minimum + (rand() % ((maximum - minimum) + 1)) ;
  
  if ((resultat < 0) || (resultat )  ) {
  }
  
}



int multiplicateur_critique()



int multiplicateur_type()
