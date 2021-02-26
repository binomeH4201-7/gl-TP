#include "automate.h"

void Automate::decalage(Etat * etat) {
  pileEtat.push_back(etat);
}

void Automate::reduction(Symbole * sym, int aReduire) {

  /*Etape 1 : on dépile le nombre de symbole
    Etape 2 : on depile le nombre d'état
    Etape 3 : on empile la partie gauche de la règle
    Etape 4 : on applique la transition depuis le NOUVEAU sommet de la pile avec le sommet de la pile de symbole
   */

  for(int i =0; i < aReduire; i++){
    pileEtat.pop_back();
    pileSymbole.pop_back();
  }

  pileSymbole.push_back(sym);

  pileEtat.back()->transition(*this, pileSymbole.back());
}
