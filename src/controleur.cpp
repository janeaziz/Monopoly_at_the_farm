#include <iostream>
#include "controleur.h"

using namespace std;

unsigned int clic(SDL_Event event , Jeu &jeu, SDL_Rect de_rect){
    int x=event.motion.x;
    int y=event.motion.y;
    int val_de =0;

    if(x>= de_rect.x && x<=de_rect.x + de_rect.w && y<= de_rect.y + de_rect.h && y>=de_rect.y ){
        val_de=jeu.jete_de();
        cout<<"la valeur du de est"<<val_de<<endl;  
    }
    return val_de;
    
}