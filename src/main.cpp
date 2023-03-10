#include "Plateau.h"
#include <iostream>
using namespace std;
 
int main(){

   /* // Initialiser SDL
    

    Plateau plateau;
    SDL_Window * window= SDL_CreateWindow()
    SDL_Renderer* renderer = plateau.init_renderer();
     plateau.set_renderer(renderer);
    // Dessiner le plateau
    plateau.charger_images(renderer);
    plateau.dessiner(0, 0);

    // Libérer la mémoire allouée pour le rendu
    SDL_DestroyRenderer(renderer);

    // Quitter SDL
    SDL_Quit();

    return 0;
    */

Plateau p; 
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window*window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
    SDL_Renderer * renderer= SDL_CreateRenderer(window,-1,0);

    p.dessiner(renderer);

   /* SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();*/


}
