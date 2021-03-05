//
// Created by Arthur Batel on 26/02/2021.
//

#include <map>
#include "etat.h"
#include "iostream"
using namespace std;

std::map<int,int> regleToNbMembres = {{1,1},{2,3},{3,3},{4,3},{5,1}};

void Etat::print() const{
    cout << name << endl;
}


bool E0::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case OPENPAR:
            automate.decalage(new E2(), false);
            break;
        case INT:
            automate.decalage(new E3(),false);
            break;
        case EXPR:
            automate.decalage(new E1(),true);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E1::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case PLUS:
            automate.decalage(new E4(),false);
            break;
        case MULT:
            automate.decalage(new E5(),false);
            break;
        case FIN:
            return true;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E2::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case INT:
            automate.decalage(new E3(),false);
            break;
        case OPENPAR:
            automate.decalage(new E2(),false);
            break;
        case EXPR:
            automate.decalage(new E6(),true);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E3::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case PLUS:
            automate.reduction(regleToNbMembres[5]);
            break;
        case MULT:
            automate.reduction(regleToNbMembres[5]);
            break;
        case CLOSEPAR:
            automate.reduction(regleToNbMembres[5]);
            break;
        case FIN:
            automate.reduction(regleToNbMembres[5]);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E4::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case INT:
            automate.decalage(new E3(),false);
            break;
        case OPENPAR:
            automate.decalage(new E2(),false);
            break;
        case EXPR:
            automate.decalage(new E7(),true);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E5::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case INT:
            automate.decalage(new E3(),false);
            break;
        case OPENPAR:
            automate.decalage(new E2(),false);
            break;
        case EXPR:
            automate.decalage(new E8(),true);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E6::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case PLUS:
            automate.decalage(new E4(),false);
            break;
        case MULT:
            automate.decalage(new E5(),false);
            break;
        case CLOSEPAR:
            automate.decalage(new E9(),true);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}


bool E7::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case PLUS:
            automate.reduction(regleToNbMembres[2]);
            break;
        case MULT:
            automate.decalage(new E5(),false);
            break;
        case CLOSEPAR:
            automate.reduction(regleToNbMembres[2]);
            break;
        case FIN:
            automate.reduction(regleToNbMembres[2]);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E8::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case PLUS:
            automate.reduction(regleToNbMembres[3]);
            break;
        case MULT:
            automate.reduction(regleToNbMembres[3]);
            break;
        case CLOSEPAR:
            automate.reduction(regleToNbMembres[3]);
            break;
        case FIN:
            automate.reduction(regleToNbMembres[3]);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E9::transition(Automate &automate, Symbole *s) {
    switch (s->getIdent()){
        case PLUS:
            automate.reduction(regleToNbMembres[4]);
            break;
        case MULT:
            automate.reduction(regleToNbMembres[4]);
            break;
        case CLOSEPAR:
            automate.reduction(regleToNbMembres[4]);
            break;
        case FIN:
            automate.reduction(regleToNbMembres[4]);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}
