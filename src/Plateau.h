#include "Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef _PLATEAU_H
#define _PLATEAU_H

class Plateau{

    private:
    Case* cases[20]; // Tableau de pointeurs vers les 20 cases du plateau
    SDL_Texture* images[20]; // Tableau de pointeurs vers les images de chaque case
    SDL_Renderer* renderer; // Pointeur vers le renderer SDL

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
     * @brief Charge les images des cases depuis le dossier "images"
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void charger_images(SDL_Renderer* renderer);

    /**
     * @brief Dessine le plateau en utilisant les images des cases
     * 
     * @param x Position x du coin supérieur gauche du plateau
     * @param y Position y du coin supérieur gauche du plateau
     */
    void dessiner(SDL_Renderer* renderer,int x, int y);
    
    /**
     * @brief Get the Case object
     * 
     * @param x 
     * @return Case 
     */
    Case & getCase(unsigned int x) const;

};

#endif