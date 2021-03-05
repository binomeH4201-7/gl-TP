#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

int Symbole::getIdent() const {
    return ident;
}

void Symbole::ChangeIdent(int newIdent){
  ident = newIdent;
}

int Symbole::Eval(){
  return -1;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::Eval(){
  return valeur;
}

int Symbole::Operation(int a, int b){
    int res = -1;
    switch(this->ident){
        case PLUS:
            res = a+b;
            break;
        case MULT:
            res = a*b;
            break;
        default:
            break;
    }
    return res;
}

