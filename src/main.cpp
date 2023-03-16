#include "Plateau.h"
#include "vue.h"
#include <iostream>

using namespace std;
 
int main(){

SDL_Window*window = NULL; 
SDL_Renderer * renderer = NULL;  
SDL_Texture* images[24];
bool quit;
SDL_Event event;

window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,950,800,SDL_WINDOW_SHOWN);
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
            charger_images(renderer,images);
            dessiner_plateau(renderer,images);
            

        
         
  }
    
    
  
   
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}
