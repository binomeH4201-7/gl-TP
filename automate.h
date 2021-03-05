#pragma once

#include <string>
#include <deque>
#include "symbole.h"
#include "etat.h"
#include "lexer.h"
#include <iostream>
using namespace std;

class Etat;
class Automate {

   public:
      Automate(string chaine);
      ~Automate() { }

      void decalage(Etat * etat);
      void reduction(int aReduire);
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
      Symbole * consulter() {cout << "Symbole lu :" << analyseur.Consulter()->Eval() << endl;return analyseur.Consulter();}
};
