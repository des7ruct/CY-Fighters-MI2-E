#include "fonctions.h"


char* Supp_SautDeLigne (char ligne[]) {
  /*
  Supprime les sauts de lignes en fin de chaines pour des soucis de récupération de 
  donnée et d'affichage
  */
  
  int i = 0 ;
  while (ligne[i] != '\0') {
      if (ligne[i] == '\n') {
          ligne[i] = '\0' ;
      }
    
      i++ ;
  }
  
  return(ligne) ;
}


int VerifNb(char* test) {
  /*
  Vérifie que chaque caractère est bien un chiffre
  */
  
  for (int i = 0 ; test[i] != '\0' ; i++) {
      if (test[i] < '0' || test[i] > '9') {
          return 0 ;
      }
  }
  
  return(1) ;
}


int VerifScanf(char* test) {
  /*
  Vérifie que la chaine reçu ne soit pas vide
  */
  
  if (test == NULL) {
      printf("\033[H\033[2J") ;
      printf("ERREUR, veuillez-recommencer\n") ;
      return(-1) ;
  }
    
  else if (test != NULL) {
      test[strcspn(test, "\n")] = 0 ;
  }
  
  /*
  Après avoir vérifier que la chaine ne contiennent que des chiffres,
  retourne la chaîne en tant que int
  */
  
  if (VerifNb(test)) {
      return(atoi(test)) ;
  }
    
  else {
      printf("\033[H\033[2J") ;
      printf("ERREUR, veuillez-recommencer\n") ;
      return(-1) ;
  }
  
  return(0) ;
}


int Credit() {
  /*
  Affichage des crédits du jeu
  */
  
  char tampon[1000] ;

  printf("\033[H\033[2J") ;
  printf("Voici les credits du jeu : \n\n") ;
  printf("Jeu : Cy-Fighters\n\n") ;
  printf("Developpeurs : \n -CAN Axel\n -ROUSSAUX Zachary\n -FARSAN Youssef\n") ;
  printf("Inspire de : Summoners War, Pokémon et Hearthstone\n") ;

  /*
  Choix entre retourner au menu ou quittez le programme
  */
  
  printf("\n\nSouhaitez-vous : \n1-Retourner au menu\n\nou\n\n2-Quitter le jeu ?\n\n") ;
  fgets(tampon, V, stdin) ;
  int n = VerifScanf(tampon) ;

  if ((n != 1) && (n != 2)) {
      printf("ERREUR, fermeture du programme\n\n") ;
      exit(1) ;
  }

  else {
      return(n) ;
  }
}


/*
Fonction de réduction des dégats par l'esquive
*/

float DegatsEsquive(int agi_lanceur, int agi_cible) {
  /* 
  Calcul les dégats réduis par l'agilité. On calcul le quotient des
  deux esquives et le résultat nous donnera le montant de dégats esquivé.
  */
  
  if (agi_lanceur < 0 || agi_cible < 0) {
      exit(1) ;
  }

  float a = agi_lanceur ;
  float b = agi_cible ;
  float coeff = 1 - (a / b) ;
  
  if (agi_lanceur > agi_cible) {
      coeff = 0 ;
  }
  
  return coeff ;
}



int aleatoire(int minimum, int maximum) {
  /*
  Fonction prenant un minimum et un maximum positifs et génére un nombre aléatoire entre     les deux. 
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


int pile_ou_face() {
  /*
  Retourne 0 ou 1.
  */

  return aleatoire(0, 1) ;
}


int multiplicateur_critique(int valeur_critique) {
  /*
  Prend une valeur de pourcentage de chance d'effectuer un coup critique et renvoie 2 si     le coup est critique, 1 sinon.
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
      printf("Erreur dans la fonction application_effet avec la constante APPLICATION_EFFETS.\n") ;
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
  1 + TAUX_TYPE si le lanceur est en avantage, 1 si les types sont identiques et 1 TAUX_TYPE sinon.
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


float Calcul_Coeff(char* stats) {
  /*
  Calcul le coefficient pour calculer la valeur de la stat en fonction de sa qualité
  */

  if (strcmp(stats, "HAUT") == 0) {
      return(1) ;
  }
    
  else if (strcmp(stats, "MOYEN") == 0) {
      return(0.75) ;
  }
    
  else if (strcmp(stats, "BAS") == 0) {
      return(0.5) ;
  }
    
  else {
      printf("ERREUR, Fermeture du programme") ;
      exit(2) ;
  }
}


int VerifCst (char* mot) {
  /*
  Verifie les données récupérés et retourne les constantes de ces dernières
  */

  if (strcmp(mot, "ATTAQUE") == 0) {
      return (ATTAQUE) ;
  }
    
  else if (strcmp(mot, "DEFENSE") == 0) {
      return (DEFENSE) ;
  }
    
  else if (strcmp(mot, "PVSCOURANTS") == 0) {
      return (PVSCOURANTS) ;
  }
    
  else if (strcmp(mot, "ENNEMI") == 0) {
      return (ENNEMI) ;
  }
    
  else if (strcmp(mot, "MOI") == 0) {
      return (MOI) ;
  }
    
  else if (strcmp(mot, "ALLIE") == 0) {
      return (ALLIE) ;
  }
    
  else if (strcmp(mot, "NON_ACTIF") == 0) {
      return (NON_ACTIF) ;
  }
    
  else if (strcmp(mot, "ACTIF") == 0) {
      return (ACTIF) ;
  }

  else {
      printf("ERREUR OU OUBLI???") ;
      exit(8) ;
  }

  return (-1) ;
}


int VerifEffet(char* mot) {
  /* 
  Verifie les données récupérés et retourne les constantes de ces dernières
  (comme pour la fonction Verifcst mais pour les constantes d'effet 
  */

  if (strcmp(mot, "AUCUNS") == 0) {
      return (AUCUNS) ;
  }
    
  else if (strcmp(mot, "AUG_ATTAQUE") == 0) {
      return (AUG_ATTAQUE) ;
  }
    
  else if (strcmp(mot, "AUG_DEFENSE") == 0) {
      return (AUG_DEFENSE) ;
  }
    
  else if (strcmp(mot, "AUG_AGILITE") == 0) {
      return (AUG_AGILITE) ;
  }
    
  else if (strcmp(mot, "AUG_VITESSE") == 0) {
      return (AUG_VITESSE) ;
  }
    
  else if (strcmp(mot, "AUG_CRITIQUE") == 0) {
      return (AUG_CRITIQUE) ;
  }
    
  else if (strcmp(mot, "IMMUNITE") == 0) {
      return (IMMUNITE) ;
  }
    
  else if (strcmp(mot, "EPINES") == 0) {
      return (EPINES) ;
  }
    
  else if (strcmp(mot, "FLAMMES") == 0) {
      return (FLAMMES) ;
  }
    
  else if (strcmp(mot, "POISON") == 0) {
      return (POISON) ;
  }
    
  else if (strcmp(mot, "GEL") == 0) {
      return (GEL) ;
  }
    
  else if (strcmp(mot, "DIM_ATTAQUE") == 0) {
      return (DIM_ATTAQUE) ;
  }
    
  else if (strcmp(mot, "DIM_DEFENSE") == 0) {
      return (DIM_DEFENSE) ;
  }
    
  else if (strcmp(mot, "DIM_AGILITE") == 0) {
      return (DIM_AGILITE) ;
  }
    
  else if (strcmp(mot, "DIM_VITESSE") == 0) {
      return (DIM_VITESSE) ;
  }
    
  else if (strcmp(mot, "SILENCE") == 0) {
      return (SILENCE) ;
  }
    
  else if (strcmp(mot, "CONFUSION") == 0) {
      return (CONFUSION) ;
  }
    
  else if (strcmp(mot, "ETOURDISSEMENT") == 0) {
      return (ETOURDISSEMENT) ;
  }
    
  else if (strcmp(mot, "ANTIHEAL") == 0) {
      return (ANTIHEAL) ;
  }

  else if (strcmp(mot, "STAT") == 0) {
      return (STAT) ;
  }
    
   else if (strcmp(mot, "EFFET") == 0) {
      return (EFFET) ;
  }
     
   else if (strcmp(mot, "MOINS") == 0) {
      return (MOINS) ;
  }
     
   else if (strcmp(mot, "PLUS") == 0) {
      return (PLUS) ;
  }
     
   else if (strcmp(mot, "MOI") == 0) {
      return (MOI) ;
  }
     
   else if (strcmp(mot, "ENNEMI") == 0) {
      return (ENNEMI) ;
  }

  else if (strcmp(mot, "NON_ACTIF") == 0) {
      return (NON_ACTIF) ;
  }
    
  else if (strcmp(mot, "ACTIF") == 0) {
      return (ACTIF) ;
  }

  else {
      printf("ERREUR EFFET") ;
      exit(8) ;
  }

  return (-1) ;
}


Combattant* AjouterCompetence(Combattant* tab, int taille) {
  /*
  Cette fonction ajoute les compétences aux comabattants déjà mis dans le tableau
  */

  FILE* fic = NULL ;
  fic = fopen("competences.txt", "r") ;
  
  if (fic == NULL) {
      exit(5) ;
  }

  char ligne[V] ;
  
  int NbCompetence = taille * 2 ; /* l y a deux compétences par combattant */

  int j = 0 ;
      for (int i = 0 ; i < NbCompetence ; i++) {
              /* Boucle par rapport au nombre de competences */
              tab[i].competences = malloc(sizeof(Competence) * 2) ;
              if (tab[i].competences == NULL) {
                  printf("Erreur malloc") ;
                  exit(9) ;
              }

          for (int j = 0 ; j < 2 ; j++) {
              /* Boucle par rapport au nombre de phases */

              /* Récupération du nom de la compétence */
              tab[i].competences[j].nom = malloc(V) ;
              if (tab[i].competences[j].nom == NULL) {
                  printf("Erreur malloc 2") ;
                  exit(10) ;
              }
            
              fgets(tab[i].competences[j].nom, V, fic) ; 
              Supp_SautDeLigne(tab[i].competences[j].nom) ;

              /* Récupération de la description de la compétence */
              tab[i].competences[j].description = malloc(V) ;
              if (tab[i].competences[j].description == NULL) {
                  printf("Erreur malloc 3") ;
                  exit(13) ;
              } 
            
              fgets(tab[i].competences[j].description, V, fic) ; 
              if (fscanf(fic, "%d\n", &tab[i].competences[j].rechargement) != 1) {
                  printf("ERREUR SORTIE DU PROGRAMME") ;
                  exit(6) ;
              }

              /* Ajout de phases */

              tab[i].competences[j].phases = malloc(sizeof(Phase) * 2) ;
              int c = 0 ;
              char* mot ;
              fgets(ligne, V, fic) ;
            
              while(c == 0) {
                  int k = 0 ;

                  Supp_SautDeLigne(ligne) ;
                  mot = strtok(ligne, " ") ;
                  tab[i].competences[j].phases[k].multiplicateur = atof(mot) ;
                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].stat = VerifCst(mot) ;
                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].cible = VerifCst(mot) ;

                  /* Ajout des effets des phases */
                  fgets(ligne, V, fic) ;
                  Supp_SautDeLigne(ligne) ;
                  int e = 0 ;
                  int x = 0 ;
                
                  while (ligne[x] != '\0') {
                      if (ligne[x] == ' ') {
                          e++ ;
                      }
                      x++ ;
                  }
                
                  int l = 0 ;

                  tab[i].competences[j].phases[k].effets_positifs = malloc(sizeof(Effet) * 10) ;
                  if (tab[i].competences[j].phases[k].effets_positifs == NULL) {
                      printf("ERREUR DE MALLOC") ;
                      exit(11) ;
                  }
                
                  mot = strtok(ligne, " ") ;
                  tab[i].competences[j].phases[k].effets_positifs[l].type = VerifEffet(mot) ;
                  tab[i].competences[j].phases[k].effets_positifs[l].tours = 2 ;
                  l++ ;
                
                  for (int i2 = 0 ; i2 < e ; i2++) {
                      mot = strtok(NULL, " ") ;
                      tab[i].competences[j].phases[k].effets_positifs[l].type = VerifEffet(mot) ;
                      tab[i].competences[j].phases[k].effets_positifs[l].tours = 2 ;
                      l++ ;
                  }
                
                  int l2 = 0 ;

                  fgets(ligne, V, fic) ;
                  Supp_SautDeLigne(ligne) ;
                  x = 0 ;
                  e = 0 ;
                
                  while (ligne[x] != '\0') {
                      if (ligne[x] == ' ') {
                          e++ ;
                      }
                    
                      x++ ;
                  }
                
                  tab[i].competences[j].phases[k].effets_negatifs = malloc(sizeof(Effet) * 10) ;
                
                  if (tab[i].competences[j].phases[k].effets_negatifs == NULL) {
                      printf("ERREUR DE MALLOC") ;
                      exit(12) ;
                  }
                
                  mot = strtok(ligne, " ") ;
                  tab[i].competences[j].phases[k].effets_negatifs[l2].type = VerifEffet(mot) ;
                  tab[i].competences[j].phases[k].effets_negatifs[l].tours = 2 ;
                  l2++ ;
                
                  for (int i2 = 0 ; i2 < e ; i2++) {
                      mot = strtok(NULL, " ") ;
                      tab[i].competences[j].phases[k].effets_negatifs[l2].type = VerifEffet(mot) ;
                      tab[i].competences[j].phases[k].effets_negatifs[l].tours = 2 ;
                      l2++ ;
                  }

                  /* On récupère les dernières données */

                  fgets(ligne, V, fic) ;
                  Supp_SautDeLigne(ligne) ;

                  mot = strtok(ligne, " ") ;
                  tab[i].competences[j].phases[k].soin = VerifCst(mot) ;


                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].vampirisme = VerifCst(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].aire = VerifEffet(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].destruction = VerifEffet(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].nefastes_multiplicateur = VerifEffet(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].barriere = atof(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].red_rechargement = atoi(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].red_nefastes = atof(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].ignore_defense = atoi(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].ignore_defense = VerifEffet(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].degats_pvs_restants_type = VerifEffet(mot) ;

                  mot = strtok(NULL, " ") ;
                  tab[i].competences[j].phases[k].degats_pvs_restants_cible = VerifEffet(mot) ;

                  k++ ; /* Decompte du numéro de compétence */


                  /*
                  Si le nom de cette compétence est celle de la dernière du document, on retourne le tableau
                  */
                  if (strcmp(tab[i].competences[j].nom, "Ragnarok") == 0) {
                      return(tab) ;
                  }

                  /* On vérifie si il y a une deuxième phase ou non */
                  fgets(ligne, V, fic) ;
                  if (ligne != NULL) {
                      if (ligne[0] == '\n') {
                          c = 1 ;
                      }

                      else {
                          c = 0 ;
                      }
                  }
              }
          }
      }

  fclose(fic) ;
  return(tab) ;
}


int Affiche_tab(Combattant* tab, int taille) {
    /* Affiche les informations de tous les combattants */
    for (int i = 0 ; i < taille ; i++) {
        printf("Nom : %s // Type : ", tab[i].nom) ;
        switch (tab[i].type) {
            case 1 :
                printf("Feu") ;
                break ;

            case 2 :
                printf("Plante") ;
                break ;

            case 3 :
                printf("Eau") ;
                break ;

            default :
                printf("ERREUR") ;
                exit(4) ;
        }
      
        printf("\n Pvmax : %d / Attaque : %d / Defense : %d / Agilite : %d / Vitesse : %d \n", tab[i].pv_max, tab[i].attaque, tab[i].defense, tab[i].agilite, tab[i].vitesse) ;
        printf("Competence 1: %s \nCompetence 2: %s \n\n\n", tab[i].competences[0].nom, tab[i].competences[1].nom) ;
    }
  return 0 ;
}


Combattant* RemplirTabCombattant() {
  /* Crée un tableau avec tous les combattants disponible */

  Combattant* tab ;
  int nb_combattants ;
  FILE* fic = NULL ;
  fic = fopen("combattants.txt", "r") ;
  char ligne[V] ;

  /* Calcul le nombre de combattants */
  if (fic != NULL) {
      int nb_ligne = 0 ;
      while (fgets(ligne, V, fic)) {
          nb_ligne++ ;
      }
    
      rewind(fic) ;
    
      nb_combattants=nb_ligne / 2 ;

      /* Création du tableau de combattant avec allocation dynamique */
      tab = malloc(sizeof(Combattant) * nb_combattants) ;
      if (tab == NULL) {
          printf("Erreur, sortie du programme") ;
          exit(2) ;
      }

      /* Remplit le tableau avec tous les combattants et leur stats */
      char ligne_stats[V] ;
      float coeff ;
      int type = 1 ;
      for (int i = 0 ; i < nb_combattants ; i++) {
          tab[i].nom = malloc(V) ;
          fgets(tab[i].nom, V, fic) ;

          fgets(ligne_stats, V, fic) ;
        
          char* pvmax = strtok(ligne_stats, " ") ;
          tab[i].pv_max = PVMAX_BASE * Calcul_Coeff(pvmax) ;
        
          char* att = strtok(NULL, " ") ;
          tab[i].attaque = ATTAQUE_BASE * Calcul_Coeff(att) ;
        
          char* def = strtok(NULL, " ") ;
          tab[i].defense = DEFENSE_BASE * Calcul_Coeff(def) ;
        
          char* agi = strtok(NULL, " ") ;
          tab[i].agilite = AGILITE_BASE * Calcul_Coeff(agi) ;
        
          char* vit = strtok(NULL, "\n") ;
          tab[i].vitesse = VITESSE_BASE * Calcul_Coeff(vit) ;

          /* Application du type, sachant qu'ils sont triés dans le fichier : FEU - PLANTE - EAU */
          tab[i].type = type ;
          if (type == FEU || type == PLANTE) {
              type++ ;
          }
            
          else if (type == EAU) {
              type = FEU ;
          }
            
          else {
              printf("ERREUR de type") ;
              exit(3) ;
          }
      }

     fclose(fic) ;
  }
    
  else {
      printf("ERREUR, Echec d'ouverture du fichier\n\n\n") ;
      exit(1) ;
  }

  tab = AjouterCompetence(tab, nb_combattants) ;
  Affiche_tab(tab, nb_combattants) ;
  return (tab) ;
}


int nombre_effets(int effet, Effet* effets) {
  /*
  Fonction retournant le nombre de fois d'un effet dans une liste d'effets.
  il faut obligatoirement que l'effet et la liste correspondent ou le résultat sera faussé.
  */

  int somme = 0 ;

  if (NOMBRE_EFFETS_MAX < 0) {
      printf("Erreur dans la fonction nombre_effets avec la constante NOMBRE_EFFETS_MAX.\n") ;
      exit(1) ;
  }

  else if (NOMBRE_EFFETS_MAX == 0) {
      return 0 ;
  } 

  else if (effets == NULL) {
      printf("Erreur dans la fonction nombre_effets avec la variable effets.\n") ;
      exit(2) ;
  }

  else {
      for (int i = 0 ; i < NOMBRE_EFFETS_MAX ; i++) {
          if (((effets + i) -> type) == effet) {
              somme++ ;
          }
      }
      return somme ;
  }
}


int appliquer_effet(Effet effet, Effet* effets) {
  /*
  Fonction ajoutant un effet dans une liste d'effets.
  il faut obligatoirement que l'effet et la liste correspondent ou le résultat sera faussé.
  retourne 0 si l'opération a réussie, 1 sinon.
  */

  if (NOMBRE_EFFETS_MAX < 0) {
      printf("Erreur dans la fonction appliquer_effet avec la constante NOMBRE_EFFETS_MAX.\n") ;
      exit(1) ;
  }

  else if (NOMBRE_EFFETS_MAX == 0) {
      return 1 ;
  } 

  else if (effets == NULL) {
      printf("Erreur dans la fonction appliquer_effet avec la variable effets.\n") ;
      exit(2) ;
  }

  else {
      for (int i = 0 ; i < NOMBRE_EFFETS_MAX ; i++) {
          if (((effets + i) -> type) == AUCUNS) {
              if (application_effet() == 1) {
                  ((effets + i) -> tours) = effet.tours ;
                  ((effets + i) -> type) = effet.type ;
                  return 0 ;
              }
                  
              else {
                  return 0 ;
              }
          }
      }
      return 1 ;
  }
}


int reduction_tour_effets(Combattant* combattant) {
  /*
  Fonction prenant l'adresse d'un combattant et réduisant les tours de tout ses effets de 1.
  Le tour n'est pas réduit si l'effet est AUCUNS
  Si le tour d'un effet est a 0 le type de celui si est changé en AUCUNS.
  renvoie 0 si l'opération a réussie, 1 sinon.
  */

  int i ;

  if (NOMBRE_EFFETS_MAX < 0) {
      printf("Erreur dans la fonction reduction_tour_effets avec la constante NOMBRE_EFFETS_MAX.\n") ;
      exit(1) ;
  }

  else if (NOMBRE_EFFETS_MAX == 0) {
      return 1 ;
  } 

  else if (((combattant -> effets_positifs) == NULL) || ((combattant -> effets_negatifs) == NULL)) {
      printf("Erreur dans la fonction reduction_tour_effets avec l'une des variables effets du combattant.\n") ;
      exit(2) ;
  }

  else {
      for (i = 0 ; i < NOMBRE_EFFETS_MAX ; i++) {
          if ((((combattant -> effets_positifs) + i) -> type) != AUCUNS) {
              (((combattant -> effets_positifs) + i) -> tours)-- ;
          }
      }

      for (i = 0 ; i < NOMBRE_EFFETS_MAX ; i++) {
          if ((((combattant -> effets_negatifs) + i) -> type) != AUCUNS) {
              (((combattant -> effets_negatifs) + i) -> tours)-- ;
          }
      }

      for (i = 0 ; i < NOMBRE_EFFETS_MAX ; i++) {
          if ((((combattant -> effets_positifs) + i) -> type) != AUCUNS) {
              if ((((combattant -> effets_positifs) + i) -> tours) == 0) {
                  (((combattant -> effets_positifs) + i) -> type) = AUCUNS ;
              }
          }
      }

      for (i = 0 ; i < NOMBRE_EFFETS_MAX ; i++) {
          if ((((combattant -> effets_negatifs) + i) -> type) != AUCUNS) {
              if ((((combattant -> effets_negatifs) + i) -> tours) == 0) {
                  (((combattant -> effets_negatifs) + i) -> type) = AUCUNS ;
              }
          }
      }

      return 0 ;
    }
}


int initialisation_combattants_equipe(Equipe* equipe) {
  /*
  Prend l'adresse d'une équipe et initialise tout ses combattants comme "NON_DISPO"
  Renvoie 0 si l'opération réussie.
  */

  int i ;
  char* chaine = NULL ;

  equipe -> combattants = NULL ;

  chaine = malloc(sizeof("NON_DISPO") * sizeof(char)) ;

  equipe -> combattants = malloc(MAX_COMBATTANTS_EQUIPE * sizeof(Combattant)) ;

  if ((equipe -> combattants == NULL) || (chaine == NULL)) {
      printf("Erreur dans la fonction initialisation_combattants_equipe, l'allocation a échouée.\n") ;
      exit(1) ;
  }

  else {
      chaine = "NON_DISPO" ;

      for (i = 0 ; i < MAX_COMBATTANTS_EQUIPE ; i++) {
          ((equipe -> combattants) + i) -> nom = chaine ;
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
      if (strcmp(((combattants + choix) -> nom), "NON_DISPO") == 0) {
          return 1 ;
      }

      else {
          return 0 ;
      }
  } 
}


int mettre_dans_equipe(Combattant* tab_combattants, Equipe* equipe, int choix) {
  /*
  Fonction prenant une liste de combattants et l'adresse d'une équipe, mettant le combattant choisi
  dans l'équipe a un emplacement libre et l'enlevant de la liste des combattants.
  retourne 0 si l'opération a réussie, 1 sinon.
  */

  if (choix < 0) {
      printf("Erreur dans la fonction mettre_dans_equipe, le choix est incorrect.\n") ;
      exit(1) ;  
  }

  else if(equipe == NULL) {
      printf("Erreur dans la fonction mettre_dans_equipe avec l'équipe choisie.\n") ;
  }

  else if ((tab_combattants == NULL) || ((equipe -> combattants) == NULL)) {
      printf("Erreur dans la fonction mettre_dans_equipe avec les listes de combattants.\n") ;
      exit(2) ;
  }

  else {
      for (int i = 0 ; i <= MAX_COMBATTANTS_EQUIPE ; i++) {
          if (strcmp(((equipe -> combattants) + i) -> nom, "NON_DISPO") == 0) {
              memcpy(((equipe -> combattants) + i), tab_combattants + choix, sizeof(Combattant)) ;

              (tab_combattants + choix) -> nom = "NON_DISPO" ;
              return 0 ;
          }
      }

      return 1 ;
  }
}


int bannir_combattant(Equipe* equipe, int choix) {
  /*
  Prend l'adresse d'une équipe et un choix et rend le combattant correspondant non dispo.
  retourne 0 si l'opération a réussie.
  */

  if ((choix < 0) || (choix >= MAX_COMBATTANTS_EQUIPE)) {
      printf("Erreur dans la fonction bannir_combattant avec le choix.\n") ;
      exit(1) ;
  }

  else if(equipe == NULL) {
      printf("Erreur dans la fonction bannir_combattant avec equipe.\n") ;
      exit(2) ;
  }

  else {
      ((equipe -> combattants) + choix) -> nom = "NON_DISPO" ;

      return 0 ;
  }
}


int Liste_Combattant(Combattant* tab, int nb_combattant) {
  /*
  Affiche la liste des combattants contenue dans un tableau
  */
  
  int decompte_type = 1 ;
  int j = 1 ;
  for (int i = 0 ; i < nb_combattant ; i++) {

        printf(" %d : %s, Type : ", j, tab[i].nom) ;
    
        if (decompte_type == 1) {
            printf("FEU\n\n") ;
            decompte_type++ ;
        }
          
        else if (decompte_type == 2) {
            printf("PLANTE\n\n") ;
            decompte_type++ ;
        }
          
        else if (decompte_type == 3) {
            printf("EAU\n\n") ;
            decompte_type = 1 ;
        }
    
        j++ ;
    }
}  


int Choix_Combattant(Combattant* tab, int nb_combattant, int num_choix) {
  /*
  Permet de choisir un combattant parmis un tableau de combattants
  */
  
  char tampon[V] ;
  int choix ;
  int verif = -1 ;

  printf("Choix %d : ", num_choix) ;
  fgets(tampon, V, stdin) ;
  choix = VerifScanf(tampon) ;

  verif = choix_combattant_correct(tab, choix-1) ;
  while (verif != 0) {
      printf("\033[H\033[2J") ;
      Liste_Combattant(tab, nb_combattant) ;
      printf("Erreur, veuillez reselectionner un combattant disponible\n\n") ;
      printf("Choix %d : ", num_choix) ;
      fgets(tampon, V, stdin) ;
      choix = VerifScanf(tampon) ;
      verif = choix_combattant_correct(tab, choix - 1) ;
  }
  return (choix - 1) ;
}
