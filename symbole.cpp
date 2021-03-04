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

int Entier::Eval(){
   return 0;
}
