//
// Created by Arthur Batel on 26/02/2021.
//

#ifndef GL_TP_ETAT_H
#define GL_TP_ETAT_H

//include
#include <string>
#include "symbole.h"
#include "automate.h"

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
    E0(string name);
    ~E0();
};

class E1 : public Etat{
public :
    E1(string name);
    ~E1();
};

class E2 : public Etat{
public :
    E2(string name);
    ~E2();
};

class E3 : public Etat{
public :
    E3(string name);
    ~E3();
};

class E4 : public Etat{
public :
    E4(string name);
    ~E4();
};

class E5 : public Etat{
public :
    E5(string name);
    ~E5();
};

class E6 : public Etat{
public :
    E6(string name);
    ~E6();
};

class E7 : public Etat{
public :
    E7(string name);
    ~E7();
};

class E8 : public Etat{
public :
    E8(string name);
    ~E8();
};

class E9 : public Etat{
public :
    E9(string name);
    ~E9();
};




#endif //GL_TP_ETAT_H
