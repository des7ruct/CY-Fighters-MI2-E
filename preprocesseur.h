#ifndef PREPROCESSEUR_H
  #define PREPROCESSEUR_H

  /* inclusions */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <string.h>
  #include <unistd.h>

  /* constantes */

  /* Valeur de chaque type assignée à son nom pour faciliter l'écriture de code */

  #define FEU 1
  #define PLANTE 2
  #define EAU 3

  /* Pourcentage initial de bonus de type */
  #define TAUX_TYPE 0.25

  /* Pourcentage initial d'application des effets négatifs */
  #define APPLICATION_EFFETS 75

  /* Pourcentage initial de coup critique */
  #define TAUX_CRITIQUE 15

  /* Taille de la barre de stamina */
  #define STAMINA_MAX 1000

  /* Nombre d'effet (positif OU négatif) max sur un combattant */
  #define NOMBRE_EFFETS_MAX 20

  /* Nombre max de combattants dans une equipe (bans inclus) */
  #define MAX_COMBATTANTS_EQUIPE 8

  /* Nombre total de combattants */
  #define NB_COMBATTANTS_TOTAL 18

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
  #define V 1000

  /* Constantes utilisées pour les phases */
  #define MOI 1
  #define ENNEMI 2
  #define ALLIE 3

  #define ATTAQUE 1
  #define DEFENSE 2
  #define PVSCOURANTS 3

  #define MOINS 1
  #define PLUS 2

  #define NON_ACTIF 0
  #define ACTIF 1  

  #define STAT 1
  #define EFFET 2

  /* Constantes pour les effets */
  #define AUCUNS 0

  /* Négatifs */ 
  #define FLAMMES 1
  #define POISON 2
  #define GEL 3

  #define DIM_ATTAQUE 4
  #define DIM_DEFENSE 5
  #define DIM_AGILITE 6
  #define DIM_VITESSE 7

  #define SILENCE 8
  #define CONFUSION 9
  #define ETOURDISSEMENT 10
  #define ANTIHEAL 11

  /* Positifs */
  #define AUG_ATTAQUE 1
  #define AUG_DEFENSE 2
  #define AUG_AGILITE 3
  #define AUG_VITESSE 4
  #define AUG_CRITIQUE 5

  #define IMMUNITE 6
  #define EPINES 7

  /* structures */

  /* Effets */
  typedef struct {
      int tours ;
      int type ;
  } Effet ;


  /* Phases */
  typedef struct {
      /* calcul classique des dégats */
      float multiplicateur ;
      int stat ;
      int cible ;

      /* effets spéciaux */
      Effet* effets_positifs ;
      Effet* effets_negatifs ;

      /* effets suplémentaires */
      /* actifs / inactifs */
      int soin ;
      int vampirisme ;
      int aire ;
      int destruction ;
      int nefastes_multiplicateur ;

      /* effets complexes */
      float barriere ;
      int red_rechargement ;
      float red_stamina ;
      int red_nefastes ;

      int ignore_defense ;
      int degats_pvs_restants_type ;
      int degats_pvs_restants_cible ;
  } Phase ;


  /* Compétences */
  typedef struct {
      char* nom ;
      char* description ;
      int rechargement ;
      int rechargement_courant ;
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
      int ko ;
      int stamina ;
      int pv_courants ;
      int pv_max_courants ;
      int barriere ;
      int blocage ;
      Effet* effets_positifs ;
      Effet* effets_negatifs ;
  } Combattant ;


  /* Objets */

  typedef struct {
      char* nom ;

  } Objet ;


  /* Equipe */

  typedef struct {
      char* nom ;
      Combattant* combattants ;
      Objet* objets ;
      int pieces ;
  } Equipe ;
#endif
