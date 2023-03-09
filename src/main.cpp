#include "Plateau.h"
#include <iostream>
using namespace std;
 
int main(){


Plateau plateau;
SDL_Renderer* renderer = plateau.init_renderer();

// Dessiner le plateau
plateau.charger_images(renderer);
plateau.dessiner(renderer, 0, 0);

// Libérer la mémoire allouée pour le rendu
SDL_DestroyRenderer(renderer);

}