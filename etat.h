//
// Created by Arthur Batel on 26/02/2021.
//

#ifndef GL_TP_ETAT_H
#define GL_TP_ETAT_H

//include
#include <string>
#include "symbole.h"

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
};

class E1 : public Etat{
public :
    E1();
    ~E1();
};

class E2 : public Etat{
public :
    E0();
    ~E0();
};

class E3 : public Etat{
public :
    E0();
    ~E0();
};

class E4 : public Etat{
public :
    E0();
    ~E0();
};

class E5 : public Etat{
public :
    E0();
    ~E0();
};

class E6 : public Etat{
public :
    E0();
    ~E0();
};

class E7 : public Etat{
public :
    E0();
    ~E0();
};

class E8 : public Etat{
public :
    E0();
    ~E0();
};

class E9 : public Etat{
public :
    E0();
    ~E0();
};




#endif //GL_TP_ETAT_H
