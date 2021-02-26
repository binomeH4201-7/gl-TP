//
// Created by Arthur Batel on 26/02/2021.
//

#ifndef GL_TP_ETAT_H
#define GL_TP_ETAT_H

//include
#include <string>

//import
#import "symbole.h"

using namespace std;


class Etat {
public :
    Etat(string name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole * s) = 0;

protected:
    string name;
};

class E0 : public Etat{
public :
    E0();
    ~E0();

protected:
    string name;
};


#endif //GL_TP_ETAT_H
