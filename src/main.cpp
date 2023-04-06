#include "Plateau.h"
#include "vue.h"
#include "controleur.h"
#include <iostream>
//#include <unistd.h>

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
unsigned int valde;
SDL_Color rouge={255,0,0};
SDL_Color bleu={0,0,255};
SDL_Color vert={0,255,0};
SDL_Color blanc={255,255,255};
 

window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1100,900,SDL_WINDOW_SHOWN);
renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

charger_images(renderer,images);


if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

while (!quit){
    int jouertour;
    bool bouton_y_n=false;
    dessiner_plateau(renderer,images);
    afficher_joueur (renderer,images,j.getJoueurs(0), j.getJoueurs(1));
    afficher_info(renderer, j.getJoueurs(0),800, 150,rouge);
    afficher_info(renderer, j.getJoueurs(1),800, 300,bleu);

      
    
    //charger_questions(renderer,1,blanc);
           
    afficher_val_de( renderer,valde,800, 465, blanc);
    
    valde=0;    

    while (SDL_PollEvent(&event)){
        if (event.type==SDL_QUIT){
            quit=true;
        }   
        else if (event.type == SDL_MOUSEBUTTONDOWN){
            valde=clic(event,j,rect_de);
            
            
              
                 
        }
        else if (event.type==SDL_KEYDOWN){
           
            SDL_Keycode keyCode = event.key.keysym.sym;
            if (keyCode == SDLK_y || keyCode == SDLK_n ){
                bouton_y_n=true;
            }

        
       
        }
    }

    if(valde>0){
                j.bouge(valde);
                valde=0;
               // afficher_joueur (renderer,images,j.getJoueurs(0), j.getJoueurs(1));
                
                
               jouertour=j.joue_tour(renderer,blanc,event);           
               cout<<"JAFFICHEEEE"<<endl;
               j.tour_suivant(); 
                
           }
    if(bouton_y_n == false && jouertour==1 ){
        charger_questions(renderer,1,blanc);
        //sleep(10);
        cout<<"je suis dans charger question"<<endl;
    } 

    if(bouton_y_n == false && jouertour==2 ){
        charger_questions(renderer,0,blanc);
                     //sleep(10);
                    //cout<<"je suis dans charger question"<<endl;
    }

    if(jouertour==3){
        charger_questions(renderer,3,rouge);
    }
    
    if(jouertour==4){
        charger_questions(renderer,4,bleu);
    }

    if(jouertour==5){
        charger_questions(renderer,5,rouge);
    }
    
    if(jouertour==6){
        charger_questions(renderer,6,vert);
    }

    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

          
         
  } 
    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}