#include <string>
#ifndef CASE_H
#define CASE_H
#include"Couleur.h"
using namespace std;

class Case{
    protected:

    int pos;
    std::string type;
     

    public:

    /**
     * @brief Construct a new Case object
     * 
     */
    Case();
    /**
     * @brief Construct a new Case object
     * 
     * @param i 
     */
  //  Case(int i);
    Case(int indice, std::string t);

    virtual ~Case();


/**
 * @brief Set the type object
 * 
 * @param letype 
 */

    void set_type(std::string letype);

    /**
     * @brief Get the pos object
     * 
     * @return int 
     */
    int get_pos()const;

//fonctions CasePropriete
    virtual int get_prix()const;

    virtual int get_loyer()const;
//fonction CaseArgent
    virtual int get_montant()const;
};



#endif