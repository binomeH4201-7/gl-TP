#pragma once

#include <string>
#include <iostream>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, EXPR, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT","EXPR", "FIN", "ERREUR" };

class Symbole {
    public:
        Symbole() : ident(ERREUR), value(true){}
        Symbole(int i) : ident(i) {value = (i==INT | i==EXPR);}
        virtual ~Symbole() { }
        virtual void Affiche();
        virtual void ChangeIdent(int newIdent);
        virtual int Eval();
        virtual int Operation(int a, int b);
        int getIdent() const;

protected:
      int ident;
      bool value;
};

class Entier : public Symbole {
   public:
      Entier() : Symbole(INT), valeur(-1){}
      Entier(int v) : Symbole(INT), valeur(v) {}
      ~Entier() { }
      virtual void Affiche();
      virtual int Eval();
   protected:
      int valeur;
};

