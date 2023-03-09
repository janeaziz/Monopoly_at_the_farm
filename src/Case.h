
#include"Couleur.h"
#include <string>
#ifndef _CASE_H
#define  _CASE_H


class Case{
    protected:

    int pos;
    std::string type;
    Couleur c;

    public:
    Case();
    Case(std::string t) : type(t);

};

#endif