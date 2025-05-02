#ifndef STRUCTURES_H
  #define STRUCTURES_H

  /* inclusions */


  /* contenu */

  /* Valeur de chaque type assignée à son nom pour faciliter l'écriture de code */

  #define FEU 1
  #define PLANTE 2
  #define EAU 3


  /* Effets */
  typedef struct {
    int num ;
    int type ;
    float coeff ;
  }Effet;
 

  /* Compétences */
  typedef struct {
    int id ;
    char* nom ;
    char* description ;

  } Competence ;

  /* Passifs */
  typedef struct {
    int id ;
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
    Effets* effets_positifs ;
    Effets* effets_negatifs ;
  } Combattant ;

  /* Equipe */

#endif
