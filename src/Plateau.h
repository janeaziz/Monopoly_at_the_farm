
#include "Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef _PLATEAU_H
#define _PLATEAU_H

class Plateau{

    private:
    Case * cases[20]; // Tableau de pointeurs vers les 20 cases du plateau
    SDL_Texture* images[24]; // Tableau de pointeurs vers les images 
   
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
     * @brief Affiche la page d'accueil avec l'image d'accueil et l'image du bouton start
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void pageaccueil(SDL_Renderer* renderer);

    /**
     * @brief Dessine le plateau en utilisant les images des cases
     * 
     * @param x Position x du coin supérieur gauche du plateau
     * @param y Position y du coin supérieur gauche du plateau
     */
    void dessiner_plateau(SDL_Renderer* renderer);
    
    /**
     * @brief Get the Case object
     * 
     * @param x 
     * @return Case 
     */
    Case & getCase(unsigned int x) const;

    void afficher ();

};

#endif