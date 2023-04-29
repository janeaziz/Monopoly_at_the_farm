#include "Case.h"
#ifndef _CASEARGENT_H
#define _CASEARGENT_H

class CaseArgent: public Case{

    private:

    int montant;
   // Couleur couleur;

    public:


    /**
     * @brief Construct a new Case Argent object
     * 
     * @param argent 
     * @param c 
     */
    CaseArgent(int argent, int position, std::string letype);

    virtual int get_montant()const;

    void set_montant(int monnaie);


};

#endif