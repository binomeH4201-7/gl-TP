#include "automate.h"

void Automate::decalage(Etat * etat) {
  /* Empiler etat sur la pile des états
     Lire (sans avancer) le prochain symbole S sur le flux
     Empiler S sur la pile des symboles
     Avancer le pointeur du flux
     */

  pileEtat.push_back(etat);
  Symbole * s = consulter();
  pileSymbole.push_back(s);
  avancer();
}

void Automate::reduction(Symbole * sym, int aReduire) {

   /*depiler de la pile d'état le nombre aReduire
     depiler de la pile de symboles le nombre aReduire
     A partir des symboles dépilés, évaluer l'expression Expr
     Empiler expr dans la pile des symboles
     Calculer l'état suivant eNext à partir du sommet de la pile des état et expr
     Empiler eNext
    */

    Entier* expr;

    if(aReduire ==1){
        expr = new Entier(pileSymbole.back()->Eval());
        pileEtat.pop_back();
        pileSymbole.pop_back();
    }else{
        pileEtat.pop_back();
        pileEtat.pop_back();
        pileEtat.pop_back();

        int a = pileSymbole.back()->Eval();
        pileSymbole.pop_back();
        Symbole* operateur = pileSymbole.back();
        pileSymbole.pop_back();
        expr = new Entier(operateur->Operation(a,*pileSymbole.back()));
        pileSymbole.pop_back();
    }

    pileSymbole.push_back(expr);
    pileEtat.back()->transition(*this, pileSymbole.back());
}
