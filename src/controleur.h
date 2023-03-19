#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Jeu.h"

/**
 * @brief prends le clic de l'utilisateur et applique la fonction jet_de si on appuie sur
 * l'image du de et verifiant les corrdonnees du clic
 * 
 * @param event 
 * @param jeu 
 * @param de_rect 
 */
void clic(SDL_Event event , Jeu &jeu, SDL_Rect de_rect);