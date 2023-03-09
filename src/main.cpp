#include "Plateau.h"
#include <iostream>
using namespace std;
 
int main(){

    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    Plateau plateau;
    SDL_Renderer* renderer = plateau.init_renderer();

    // Dessiner le plateau
    plateau.charger_images(renderer);
    plateau.dessiner(0, 0);

    // Libérer la mémoire allouée pour le rendu
    SDL_DestroyRenderer(renderer);

    // Quitter SDL
    SDL_Quit();

    return 0;
}
