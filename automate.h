#pragma once

#include <string>
#include <stack>
#include "symbole.h"
using namespace std;

class Automate {

   public:
      Automate() { }
      ~Automate() { }

      void decalage(Symbole * sym, Etat * etat);
      void reduction(Symbole * sym, int aReduire);

   protected:
      stack<Etat> * pile;
};
