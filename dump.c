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
  
  if ((resultat < 0) || (resultat < minimum) || (resultat > maximum)) {
    printf("Erreur dans la fonction aleatoire avec le retour de la fonction.") ;
    exit(2) ;
  }

  return resultat ;
}



int multiplicateur_critique()



int multiplicateur_type()







//Constante utilisé pour les fgets//
#define V 100

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


int main(){

Menu();
return(0);
}
