#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

int Symbole::getIdent() const {
    return ident;
}

bool Symbole::isValue() const {
    return value;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
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

