#include "Plateau.h"
#include "vue.h"
#include "controleur.h"
#include <iostream>

using namespace std;
 
int main(){
const int case_width=130;
const int case_height=130;
Jeu j;
SDL_Window*window = NULL; 
SDL_Renderer * renderer = NULL;  
SDL_Texture* images[26];
bool quit;
SDL_Event event;
SDL_Rect rect_de;
rect_de.x=6*case_width +20;
rect_de.y=0;
rect_de.h=case_height;
rect_de.w=case_width;

window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,950,800,SDL_WINDOW_SHOWN);
renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

charger_images(renderer,images);
j.ajouter_joueur();

if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

while (!quit){
    while (SDL_PollEvent(&event)){
        if (event.type==SDL_QUIT){
            quit=true;
        }   else if (event.type == SDL_MOUSEBUTTONDOWN){
            clic(event,j,rect_de);
            
        }
        }
     
            
            dessiner_plateau(renderer,images);
            afficher_joueur (renderer,images,j.getJoueurs(0), j.getJoueurs(1));
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
        
         
  }
    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}