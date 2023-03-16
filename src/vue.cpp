
#include <iostream>
#include "vue.h"

using namespace std;

void charger_images(SDL_Renderer* renderer, SDL_Texture* images[24]) {
    // Tableau contenant le nom de fichier pour chaque type de case
    const char* images_filenames[9] = {
        "data/CasePropriete.png", 
        "data/CaseRessources.png", 
        "data/CaseEnigme.png", 
        "data/CaseArgent.png",
        "data/CaseDepart.png", // On ajoute une image pour la case départ
        "data/de.png",
        "data/photocentre.png",
        "data/pageaccueil.png",
        "data/boutonstart.png"

    };

    for (int i = 0; i < 24; i++) {
        // Charger l'image correspondante au type de case de la case i
        if (i == 0) {
            // Case départ
            images[i] = IMG_LoadTexture(renderer, images_filenames[4]);
        } else if (i == 2 || i == 3 ||i == 4 || i == 6 ||i == 7 || i == 11 ||i == 12 ||
         i == 13 ||i == 17 || i == 18) {
            // Cases de type CasePropriete
            images[i] = IMG_LoadTexture(renderer, images_filenames[0]);
        } else if (i == 8 || i== 15) {
            // Case de type CaseEnigme
            images[i] = IMG_LoadTexture(renderer, images_filenames[2]);
        } else if (i == 1 || i== 10 || i == 16 || i== 19){
            // Case de type CaseArgent
            images[i] = IMG_LoadTexture(renderer, images_filenames[3]);
        } else if (i == 5 || i== 9 || i == 14){
            //Case de type Ressources
            images[i] = IMG_LoadTexture(renderer, images_filenames[1]);
        } else if (i ==  20){
            //le de
            images[i] = IMG_LoadTexture(renderer, images_filenames[5]);
        } else if (i ==  21){
            //photo du centre du plateau
            images[i] = IMG_LoadTexture(renderer, images_filenames[6]);
        } else if (i ==  22){
            //photo de la page d'accueil
            images[i] = IMG_LoadTexture(renderer, images_filenames[7]);
        } else if (i ==  23){
            //Bouton Start
            images[i] = IMG_LoadTexture(renderer, images_filenames[8]);
        }


        if(!images[i]){
            cout<< "l'image " <<i << "n'a pas ete charge"<<endl;
        }
        
    }

    
}


void dessiner_plateau(SDL_Renderer* renderer, SDL_Texture* images[24]) {
    // Dessin du plateau en utilisant les images des cases
    
    SDL_Rect Rect;

    const int case_width=130;
    const int case_height=130;


    for (int i= 0; i< 21; i++) {

        if (i==20) {
            Rect.x = 6* case_width + 20;
            Rect.y = 0;
        }

        else if (i==6 || i == 7 || i == 8 || i == 9){
           Rect.x = 5 * case_width; 
           if (i==6) Rect.y= case_height;
           if (i==7) Rect.y= 2*case_height;
           if (i==8) Rect.y= 3*case_height;
           if (i==9) Rect.y= 4*case_height;
        }
        else if(i==16 || i == 17 || i == 18 || i == 19){
            Rect.x = 0;
            if (i==16) Rect.y= 4*case_height;
            if (i==17) Rect.y= 3*case_height;
            if (i==18) Rect.y= 2*case_height;
            if (i==19) Rect.y= case_height;
        }
        else { 
            
            

            if(i<16 && i>9){
                if(i==15) Rect.x= 0;
                if(i==14) Rect.x= 1*case_width;
                if(i==13) Rect.x= 2*case_width;
                if(i==12) Rect.x= 3*case_width;
                if(i==11) Rect.x= 4*case_width;
                if(i==10) Rect.x= 5*case_width; 
                Rect.y = 5 * case_height;
            }

            else { 
                Rect.x = i%6 * case_width;
                Rect.y = 0;
            }    
        }
        Rect.w = case_width;
        Rect.h = case_height;
        SDL_RenderCopyEx(renderer, images[i], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
        
    }
    
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    
}
