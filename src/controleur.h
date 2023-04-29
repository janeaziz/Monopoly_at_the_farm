#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Jeu.h"

unsigned int clic(SDL_Event event , Jeu &jeu, SDL_Rect de_rect);

void clic_bouton_start(SDL_Event event , bool &bouton_start);

bool bouton(SDL_Event event);