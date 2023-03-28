
#include "Case.h"
#include "CasePropriete.h"
#include "CaseArgent.h"
#include "Couleur.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef _PLATEAU_H
#define _PLATEAU_H

class Plateau{

    private:
    Case * cases[20]; // Tableau de pointeurs vers les 20 cases du plateau
    //CasePropriete * caseprop[20];
    public:

    /**
     * @brief Constructeur de Plateau
     * 
     */
    Plateau ();

    /**
     * @brief Destructeur de Plateau
     * 
     */
    ~Plateau();


    
    /**
     * @brief Get the Case object
     * 
     * @param x 
     * @return Case 
     */
    Case & getCase(unsigned int x) const;


};

#endif