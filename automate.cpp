#include "automate.h"
#include <iostream>

using namespace std;

void Automate::decalage(Etat * etat,bool terminal) {
  /* Empiler etat sur la pile des états
     Lire (sans avancer) le prochain symbole S sur le flux
     Empiler S sur la pile des symboles
     Avancer le pointeur du flux
     */
  cout << "Début décalage à l'état "; etat->Affiche(); cout << endl;
  pileEtat.push_back(etat);
  if(!terminal){
  Symbole * s = consulter();
  pileSymbole.push_back(s);
    avancer();
  }
  cout << "Fin décalage à l'état "; etat->Affiche(); cout << endl;
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
    cout << "Début réduction de "<< aReduire << " symboles."<< endl;

    if(aReduire ==1){
        expr = new Entier(pileSymbole.back()->Eval());
        pileEtat.pop_back();
        pileSymbole.pop_back();
    }else{
        pileEtat.pop_back();
        pileEtat.pop_back();
        pileEtat.pop_back();

        int a = pileSymbole.back()->Eval();
        cout<<"from automate.cpp a="<<a<<endl;
        pileSymbole.pop_back();
        Symbole* operateur = pileSymbole.back();
        pileSymbole.pop_back();
        cout<<"from automate.cpp b="<<pileSymbole.back()->Eval()<<endl;
        expr = new Entier(operateur->Operation(a,pileSymbole.back()->Eval()));
        pileSymbole.pop_back();
    }
    expr->ChangeIdent(EXPR);
    pileSymbole.push_back(expr);
    pileEtat.back()->transition(*this, pileSymbole.back());
    
    cout << "Fin réduction de "<< aReduire << " symboles."<< endl;
}

bool Automate::isOver(){return over;}

void Automate::next(){
    over = pileEtat.back()->transition(*this,consulter());
}
int Automate::answer(){ return pileSymbole.back()->Eval();}

Automate::Automate(string chaine) : analyseur(chaine) {
    pileEtat.push_back(new E0());
}
void Automate::Affiche(){
    cout << "-------------------------" << endl;
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



