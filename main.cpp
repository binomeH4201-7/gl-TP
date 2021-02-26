#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");

    Automate* automate = new Automate(chaine);
    
   /*Creer l'automate, init la pile à l'état 0
    Lire le premier symbole
    Empiler le symbole
    Faire la transition (etat.transition qui appelle automate.reduction ou automate.decalage)
    Si on a un decalage, on deplace la tete de lecture (pas dans le cas d'une reduction
    */

    /*
    Lexer l(chaine);

    Symbole * s;
   while(*(s=l.Consulter())!=FIN) { 
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
     */
   return 0;
}

