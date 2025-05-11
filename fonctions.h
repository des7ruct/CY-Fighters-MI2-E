#ifndef FONCTIONS_H
  #define FONCTIONS_H

  /* Déclarations Fonctions */

  int choix_securise(int minimum, int maximum) ;
  char* Supp_SautDeLigne (char ligne[]) ;
  int VerifNb(char* test) ;
  int VerifScanf(char* test) ;
  int Credit() ;
  float DegatsEsquive(int agi_lanceur, int agi_cible) ;
  int aleatoire(int minimum, int maximum) ;
  int pile_ou_face() ;
  int multiplicateur_critique(int valeur_critique) ;
  int application_effet() ;
  float multiplicateur_type(int type_lanceur, int type_cible) ;
  float Calcul_Coeff(char* stats) ;
  int VerifCst (char* mot) ;
  int VerifEffet(char* mot) ;
  Combattant* AjouterCompetence(Combattant* tab, int taille) ;
  Combattant* RemplirTabCombattant() ;
  int nombre_effets(int effet, Effet* effets) ;
  int appliquer_effet_negatif(Effet* effets_positifs, Effet effet, Effet* effets) ;
  int appliquer_effet_positif(Effet effet, Effet* effets) ;
  int reduction_tour_effets(Combattant* combattant) ;
  int initialisation_combattants_equipe(Equipe* equipe) ;
  int choix_combattant_correct(Combattant* combattants, int choix) ;
  int mettre_dans_equipe(Combattant* tab_combattants, Equipe* equipe, int choix) ;
  int bannir_combattant(Equipe* equipe, int choix) ;
  int Liste_Combattant(Combattant* tab, int nb_combattant) ;
  int Choix_Combattant(Combattant* tab, int nb_combattant, int num_choix) ;
  int initialisation_effets(Equipe* equipe) ;
  int initialisation_combat(Equipe* equipe) ;
  float calcul_passif(Combattant* combattant) ;
  float coefficient_effet(int nb_effet, float coefficient) ;
  int stamina_max_tab(int tab[]) ;
  char* calcul_tour(Equipe* equipe_a, Equipe* equipe_b) ;
  int fin_de_tour(Combattant* combattant) ;
  int  bloquer(Combattant* combattant) ;
  int debut_tour(Combattant* combattant) ;
  float coefficients_basiques_attaque(Combattant* lanceur, Combattant* cible) ;
  float coefficient_stat_attaque(int stat, Combattant* lanceur) ;
  float coefficient_defense(Combattant* cible) ;
  int attaque_basique(Combattant* lanceur, Combattant* cible) ;
  int donner_effets_positifs(Combattant* cible, Effet* effets) ;
  int donner_effets_negatifs(Combattant* cible, Effet* effets) ;
  float coefficient_multiplicatif_nefaste(Phase* phase, Combattant* cible) ;
  float coefficient_multiplicateur_pv_restants(Phase* phase, Combattant* lanceur, Combattant* cible) ;
  float coefficient_ignore_defense(Phase* phase, Combattant* lanceur, Combattant* cible) ;
  int phase_competence_effets(Phase* phase, Combattant* cible) ;
  int phase_competence_attaque(Combattant* lanceur, Combattant* cible, Phase* phase) ;
  int utiliser_competence(Combattant* lanceur, Combattant* cible, int c) ;
  int plus_faible(Equipe* equipe) ;
  int bot_cible(Equipe* equipe, int difficulte) ;
  char* convertir_type(int t) ;
  Combattant Compare_Attaquant(Equipe* A, Equipe* B, Combattant Attaquant) ;
  int Calcul_Nb_Combattant() ;


#endif
