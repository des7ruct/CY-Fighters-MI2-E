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
