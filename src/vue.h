
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Jeu.h"

/**
     * @brief Charge les images des cases depuis le dossier "images"
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void charger_images(SDL_Renderer* renderer,SDL_Texture* images[24]);


    /**
     * @brief Affiche la page d'accueil avec l'image d'accueil et l'image du bouton start
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void pageaccueil(SDL_Renderer* renderer,SDL_Texture* images[24]);

    /**
     * @brief Dessine le plateau en utilisant les images des cases
     * 
     * @param x Position x du coin supérieur gauche du plateau
     * @param y Position y du coin supérieur gauche du plateau
     */
    void dessiner_plateau(SDL_Renderer* renderer,SDL_Texture* images[24]);
    
   

    void afficher_joueur (SDL_Texture* images[24]);
