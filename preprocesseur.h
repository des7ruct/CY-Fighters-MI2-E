#ifndef PREPROCESSEUR_H
  #define PREPROCESSEUR_H

  /* inclusions */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>

  /* constantes */

  /* Valeur de chaque type assignée à son nom pour faciliter l'écriture de code */

  #define FEU 1
  #define PLANTE 2
  #define EAU 3

  /* Pourcentage initial de bonus de type */
  #define TAUX_TYPE 0.25

  /* Pourcentage initial de coup critique */
  #define TAUX_CRITIQUE 15

  /* Pourcentage initial de stats de bases */
  #define HAUT 1
  #define MOYEN 0.75
  #define BAS 0.5

  /* Stats de base */
  #define PVMAX_BASE 50000
  #define ATTAQUE_BASE 4000
  #define DEFENSE_BASE 800
  #define AGILITE_BASE 100
  #define VITESSE_BASE 200

  //Constante utilisé pour les fgets//
  #define V 100

  /* Constantes utilisées pour les phases */
  #define MOI 1
  #define ENNEMI 2

  #define ATTAQUE 1
  #define DEFENSE 2
  #define PVSMAX 3

  /* Constantes pour les effets */
  /* Négatifs */ 
  #define FLAMES
  #define POISON
  #define GEL

  #define DIM_ATTAQUE
  #define DIM_DEFENSE
  #define DIM_AGILITE
  #define DIM_VITESSE

  #define SILENCE
  #define CONFUSION
  #define ETOURDISSEMENT
  #define ANTIHEAL

  /* Positifs */
  #define AUG_ATTAQUE
  #define AUG_DEFENSE
  #define AUG_AGILITE
  #define AUG_VITESSE
  #define AUG_CRITIQUE

  #define IMMUNITE
  #define EPINES
  
  /* structures */

  /* Effets */
  typedef struct {
    int tours ;
    int type ;
  } Effet ;

  /* Phases */
  typedef struct {
    /* calcul classique des dégats */
    int multiplicateur ;
    int stat ;

    /* cibles */
    int cible ;
    int aoe ;

    /* effets spéciaux */
    Effet* effets_positifs ;
    Effet* effets_negatifs ;
    

    /* effets suplémentaires */
    
  } Phase ;

  /* Compétences */
  typedef struct {
    char* nom ;
    char* description ;
    int rechargement ;
    Phase* phases ;
  } Competence ;

  /* Passifs */
  typedef struct {
    char* nom ;
    char* description ;

  } Passif ;

  /* Structure Combattant */

  typedef struct {
    char* nom ;
    int type ;
    int pv_max ;
    int attaque ;
    int defense ;
    int agilite ;
    int vitesse ;
    Competence* competences ;
    Passif passif ;

    /* Non Prédéfini */
    int stamina ;
    int pv_courants ;
    int protection ;
    Effet* effets_positifs ;
    Effet* effets_negatifs ;
  } Combattant ;

  /* Equipe */

#endif
