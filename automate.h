#pragma once

#include <string>
#include <deque>
#include "symbole.h"
#include "etat.h"
#include "lexer.h"
using namespace std;

class Etat;
class Automate {

   public:
      Automate(string chaine);
      ~Automate() { }

      void decalage(Etat * etat);
      void reduction(Symbole * sym, int aReduire);
      bool isOver();
      void next();
      int answer();
      void Affiche();

   protected:
      deque <Etat *> pileEtat;
      deque <Symbole *> pileSymbole;
      Lexer analyseur;
        bool over;

    void avancer() {analyseur.Avancer(); };
      Symbole * consulter() {return analyseur.Consulter() ;}
};
