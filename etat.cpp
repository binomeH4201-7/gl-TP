//
// Created by Arthur Batel on 26/02/2021.
//

#include <map>
#include "etat.h"
#include "iostream"
using namespace std;

std::map<int,int> regleToNbMembres = {{1,1},{2,3},{3,3},{4,3},{5,1}};

Etat::~Etat(){}
void Etat::print() const{
    cout << name << endl;
}


bool E0::transition(Automate &automate, Symbole *s) {
    switch (*s){
        case OPENPAR:
            automate.decalage(new E2());
            break;
        case INT:
            automate.decalage(new E3());
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
    switch (*s){
        case PLUS:
            automate.decalage(new E4());
            break;
        case MULT:
            automate.decalage(new E5());
            break;
        case FIN:
            //TODO: Implémenter la fin
            cout << "FIN" <<endl;
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}

bool E2::transition(Automate &automate, Symbole *s) {
    switch (*s){
        case INT:
            automate.decalage(new E3());
            break;
        case OPENPAR:
            automate.decalage(new E2());
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
    switch (*s){
        case PLUS:
            automate.reduction(s,regleToNbMembres[5]);
            break;
        case MULT:
            automate.reduction(s,regleToNbMembres[5]);
            break;
        case OPENPAR:
            automate.reduction(s,regleToNbMembres[5]);
            break;
        case FIN:
            automate.reduction(s,regleToNbMembres[5]);
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
    switch (*s){
        case INT:
            automate.decalage(new E3());
            break;
        case OPENPAR:
            automate.decalage(new E2());
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
    switch (*s){
        case INT:
            automate.decalage(new E3());
            break;
        case OPENPAR:
            automate.decalage(new E2());
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
    switch (*s){
        case PLUS:
            automate.decalage(new E4());
            break;
        case MULT:
            automate.decalage(new E5());
            break;
        case CLOSEPAR:
            automate.decalage(new E9());
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
    switch (*s){
        case PLUS:
            automate.reduction(s, regleToNbMembres[2]);
            break;
        case MULT:
            automate.decalage(new E5());
            break;
        case CLOSEPAR:
            automate.reduction(s,regleToNbMembres[2]);
            break;
        case FIN:
            automate.reduction(s, regleToNbMembres[2]);
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
    switch (*s){
        case PLUS:
            automate.reduction(s, regleToNbMembres[3]);
            break;
        case MULT:
            automate.reduction(s, regleToNbMembres[3]);
            break;
        case CLOSEPAR:
            automate.reduction(s, regleToNbMembres[3]);
            break;
        case FIN:
            automate.reduction(s, regleToNbMembres[3]);
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
    switch (*s){
        case PLUS:
            automate.reduction(s, regleToNbMembres[4]);
            break;
        case MULT:
            automate.reduction(s, regleToNbMembres[4]);
            break;
        case CLOSEPAR:
            automate.reduction(s, regleToNbMembres[4]);
            break;
        case FIN:
            automate.reduction(s, regleToNbMembres[4]);
            break;
        case ERREUR:
            cout << "Erreur" <<endl;
            break;
        default :
            break;
    }
    return false;
}