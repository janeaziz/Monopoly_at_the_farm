
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Jeu.h"
#include"controleur.h"

/**
     * @brief Charge les images des cases depuis le dossier "images"
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void charger_images(SDL_Renderer* renderer,SDL_Texture* images[]);


    /**jouter_joueur();
     * @brief Affiche la page d'accueil avec l'image d'accueil et l'image du bouton start
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void pageaccueil(SDL_Renderer* renderer,SDL_Texture* images[]);

    /**
     * @brief Dessine le plateau en utilisant les images des cases
     * 
     * @param x Position x du coin supérieur gauche du plateau
     * @param y Position y du coin supérieur gauche du plateau
     */
    void dessiner_plateau(SDL_Renderer* renderer,SDL_Texture* images[]);
    
   

    void afficher_joueur (SDL_Renderer* renderer,SDL_Texture* images[],Joueur p1, Joueur p2);

    // void afficher_texte(SDL_Renderer* renderer, int x, int y);

    void afficher_info(SDL_Renderer * renderer,Joueur j,int x, int y,SDL_Color c);

    void afficher_val_de(SDL_Renderer * renderer,unsigned int val_de,int x, int y,SDL_Color c);

    void charger_questions(SDL_Renderer* renderer,unsigned int indice,SDL_Color c);