#pragma once

#include <string>
#include <deque>
#include "symbole.h"
#include "etat.h"
using namespace std;

class Etat;
class Automate {

   public:
      Automate() { }
      ~Automate() { }

      void decalage(Etat * etat);
      void reduction(Symbole * sym, int aReduire);

   protected:
      deque <Etat *> pile;
};
