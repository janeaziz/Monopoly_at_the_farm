#include "Case.h"


#ifndef _PLATEAU_H
#define _PLATEAU_H

class Plateau{

    private:
    Case * cases;

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