//
// Created by Arthur Batel on 26/02/2021.
//

#ifndef GL_TP_ETAT_H
#define GL_TP_ETAT_H

//include
#include <string>
#include "symbole.h"
#include "automate.h"
#include <iostream>

using namespace std;

class Automate;

class Etat {
public :
    Etat(string aName) : name(aName){}
    virtual ~Etat(){}
    virtual bool transition(Automate & automate, Symbole * s) = 0;
    virtual void Affiche();

protected:
    string name;
};

class E0 : public Etat{
public :
    E0() : Etat("E0"){}
    virtual ~E0(){}
    bool transition(Automate &automate, Symbole *s);
};

class E1 : public Etat{
public :
    E1() : Etat("E1"){}
    virtual ~E1(){}
    bool transition(Automate &automate, Symbole *s);
};

class E2 : public Etat{
public :
    E2() : Etat("E2"){}
    virtual ~E2(){}
    bool transition(Automate &automate, Symbole *s);
};

class E3 : public Etat{
public :
    E3() : Etat("E3"){}
    virtual ~E3(){}
    bool transition(Automate &automate, Symbole *s);

};

class E4 : public Etat{
public :
    E4() : Etat("E4"){}
    virtual ~E4(){}
    bool transition(Automate &automate, Symbole *s);
};

class E5 : public Etat{
public :
    E5() : Etat("E5"){}
    virtual ~E5(){}
    bool transition(Automate &automate, Symbole *s);

};

class E6 : public Etat{
public :
    E6() : Etat("E6"){}
    virtual ~E6(){}
    bool transition(Automate &automate, Symbole *s);

};

class E7 : public Etat{
public :
    E7() : Etat("E7"){}
    virtual ~E7(){}
    bool transition(Automate &automate, Symbole *s);

};

class E8 : public Etat{
public :
    E8() : Etat("E8"){}
    virtual ~E8(){}
    bool transition(Automate &automate, Symbole *s);

};

class E9 : public Etat{
public :
    E9() : Etat("E9"){}
    virtual ~E9(){}
    bool transition(Automate &automate, Symbole *s);

};




#endif //GL_TP_ETAT_H
