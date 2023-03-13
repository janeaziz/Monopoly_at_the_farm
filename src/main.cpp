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
SDL_Window*window = NULL; 
SDL_Renderer * renderer = NULL;  
bool quit;
Plateau p; 
SDL_Event event;

window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

while (!quit){
    while (SDL_PollEvent(&event)){
        if (event.type==SDL_QUIT){
            quit=true;
        }
    }
    

    p.dessiner(renderer);
}

    //SDL_RenderPresent(renderer);

    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


}
