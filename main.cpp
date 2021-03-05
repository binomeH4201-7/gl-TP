#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(int argc, char *argv[]) {
   //string chaine("(1+34)*123");
   //string chaine("2*(2)");
    
    if(argc != 2){
      cout << "Il ne faut passer qu'un seul argument, la chaîne à évaluer\n"
              "Exemple : \"2+78\"\n"
              "La chaine ne doit pas contenir d'espace, et uniquement les symbôles \"+\", \"*\", \"(\",\")\".\n"
              "Les nombres doivent être des entiers positifs."
              << endl;
      return -1;
    }

    string chaine(argv[1]);

    Automate* automate = new Automate(chaine);
    while(!automate->isOver()){
        automate->next();
    }
    int res = automate->answer();
    cout << res << endl;

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

