#ifndef PROCEDURES_H
  #define PROCEDURES_H

  /* inclusions */


  /* déclarations */

void Codex (Combattant* tab, int taille) ;
void Tuto() ;
void Menu() ;
void Creation_Equipe(Combattant* tab, int nb_combattant_tot, int nb_combattant_eq, Equipe* A, Equipe* B) ;
void Interface_Combat(Equipe* A, Equipe* B, Combattant Attaquant) ;
void Combat(Combattant* tab, int n_tot, int n_eq) ;


#endif
