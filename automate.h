#pragma once

#include <string>
#include <deque>
#include "symbole.h"
#include "etat.h"
#include "lexer.h"
#include <iostream>

class Etat;
class Automate {

   public:
      Automate(string chaine);
      ~Automate() { }

      void decalage(Etat * etat, bool isSymbolTerminal);
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
      void avancer(); 
      Symbole * consulter();
};
