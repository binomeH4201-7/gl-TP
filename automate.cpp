#include "automate.h"

using namespace std;

void Automate::avancer() {
  analyseur.Avancer();
}

Symbole * Automate::consulter(){
  return analyseur.Consulter();
}

void Automate::decalage(Etat * etat,bool terminal) {
  /* Empiler etat sur la pile des états
     Lire (sans avancer) le prochain symbole S sur le flux
     Empiler S sur la pile des symboles
     Avancer le pointeur du flux
     */
  pileEtat.push_back(etat);
  if(!terminal){
  Symbole * s = consulter();
  pileSymbole.push_back(s);
    avancer();
  }
}

void Automate::reduction(int aReduire) {

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
        
        if(pileSymbole.back()->Eval() != -1){ //si le premier est une valeur
          int a = pileSymbole.back()->Eval();
          pileSymbole.pop_back();
          Symbole* operateur = pileSymbole.back();
          pileSymbole.pop_back();
          expr = new Entier(operateur->Operation(a,pileSymbole.back()->Eval()));
          pileSymbole.pop_back();
        }else{ //sinon, c'est qu'il s'agit de la règle E -> ( E )
          pileSymbole.pop_back();
          expr = new Entier(pileSymbole.back()->Eval());
          pileSymbole.pop_back();
          pileSymbole.pop_back();
        }
    }
    expr->ChangeIdent(EXPR);
    pileSymbole.push_back(expr);
    pileEtat.back()->transition(*this, pileSymbole.back());
}

bool Automate::isOver(){return over;}

void Automate::next(){
    over = pileEtat.back()->transition(*this,consulter());
}
int Automate::answer(){
  if(!pileSymbole.empty())
    return pileSymbole.back()->Eval();
  else
    return -1;
}

Automate::Automate(string chaine) : analyseur(chaine) {
    pileEtat.push_back(new E0());
}
void Automate::Affiche(){
    cout << "Affichage de la pile Etat" << endl;
    for(int i = 0; i < pileEtat.size(); i++){
      pileEtat[i]->Affiche();
      cout << " | ";
    }

    cout << endl << "-------------------------" << endl;
    cout << "Affichage de la pile Symbole" << endl;
    for(int i = 0; i < pileSymbole.size(); i++){
      pileSymbole[i]->Affiche();
      cout << " | ";
    }
    cout << endl << endl;
}



