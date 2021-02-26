#include "automate.h"

void Automate::decalage(Etat * etat) {
  pile.push_back(etat);
}

void Automate::reduction(Symbole * sym, int aReduire) {

  /*Etape 1 : on dépile le nombre de symbole
    Etape 2 : on applique la transition depuis le NOUVEAU sommet de la pile avec le symbole sym
   */

  for(int i =0; i < aReduire; i++){
    pile.pop_back();
  }

  pile.back()->transition(*this, sym);
}
