/* Effets */


/* Compétences */


/* Passifs */


/* Structure Combattant */

typedef struct {
  char* nom ;
  int pv_max ;
  int pv_courants ;
  int attaque ;
  int defense ;
  int agilite ;
  int vitesse ;
  Competence* competences ;
  Passif passif ;
  Effets* effets_positifs ;
  Effets* effets_negatifs ;
} Combattant ;

