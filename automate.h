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
      Automate(string chaine) : analyseur(chaine) { }
      ~Automate() { }

      void decalage(Etat * etat);
      void reduction(Symbole * sym, int aReduire);

   protected:
      deque <Etat *> pileEtat;
      deque <Symbole *> pileSymbole;
      Lexer analyseur;
      void avancer() {analyseur.Avancer(); };
      void consulter() {analyseur.Consulter() ;};
};
