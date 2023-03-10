
#include"Couleur.h"
#include <string>
#ifndef _CASE_H
#define  _CASE_H


class Case{
    protected:

    int pos;
    std::string type;
     

    public:

    Case(int i);
    Case(int indice, std::string t);

    void set_type(std::string letype);
};

#endif