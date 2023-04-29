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

    //~CaseArgent();

   virtual int get_montant()const;

    void set_montant(int monnaie);

    //fonction sur case? 
    //dans la classe jeu on va voir l'utilisateur il est ou et on
    //fait les modif, ajouter argent, il achete un proprio , il 
    //achete un arbre, il gagne de l'eau, il repond question....






};

#endif