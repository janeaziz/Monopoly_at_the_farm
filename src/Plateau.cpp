

/*void Plateau::charger_images(SDL_Renderer* renderer) {
    // Pour chaque case
    for(int i = 0; i < 20; i++) {
        // On construit le nom du fichier image (exemple : "images/case_0.png")
        std::string filename = "images/case_" + std::to_string(i) + ".png";

        // On charge l'image depuis le fichier
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if(surface == nullptr) {
            std::cerr << "Erreur : impossible de charger l'image " << filename << std::endl;
            return;
        }

        // On crée une texture à partir de l'image
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(texture == nullptr) {
            std::cerr << "Erreur : impossible de créer la texture pour l'image " << filename << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        // On stocke la texture dans le tableau "images"
        images[i] = texture;

        // On libère la surface, car on n'en a plus besoin
        SDL_FreeSurface(surface);
    }
} */

#include "Plateau.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;


const int Screen_width=800;
const int Screen_height=800;

const int case_width=130;
const int case_height=130;


Plateau::Plateau() {
    // Création des cases du plateau
    
    for (int i = 0; i < 20; i++) {
        cases[i] = new Case(i);
        if (i == 0) {
            cases[i]->set_type("Case départ");
        } else if (i==2 || i==3 || i==4 || i==6 || i==7 || i==11 ||i==12|| i==13|| i==17|| i==18 ) {
            cases[i]->set_type("Case propriete");
        }
        else if (i==8 || i==15){
            cases[i]->set_type("Case enigme");
        }
        else if (i==1 || i==10 || i==16 || i==19)
        {
            cases[i]->set_type("Case argent");
        }
        else{
            cases[i]->set_type("Case Ressources") ;// il ya 3 cases 
        }
    }
}

Plateau::~Plateau() {
    // Suppression des cases du plateau
    for (int i = 0; i < 20; i++) {
        delete cases[i];
    }
}

/*void Plateau::charger_images(SDL_Renderer* renderer) {
    // Chargement des images de chaque case
    for (int i = 0; i < 20; i++) {
        std::string filename = "images/case" + std::to_string(i) + ".png";
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if (!surface) {
            std::cerr << "Erreur lors du chargement de l'image : " << filename << std::endl;
            SDL_FreeSurface(surface);
            continue;
        }
        images[i] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!images[i]) {
            std::cerr << "Erreur lors de la création de la texture : " << filename << std::endl;
            continue;
        }
    }
} */

void Plateau::charger_images(SDL_Renderer* renderer) {
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
/**
void Plateau::pageaccueil(SDL_Renderer* renderer){
    SDL_Rect RectAccueil;
    for (int i= 20; i< 24; i++) {
        if(i==20) RectAccueil.x = 6*case_width;
        if(i==21) RectAccueil.
    }
}
*/

void Plateau::dessiner_plateau(SDL_Renderer* renderer) {
    // Dessin du plateau en utilisant les images des cases
    
    SDL_Rect Rect;
    for (int i= 0; i< 21; i++) {

        if (i==20) {
            Rect.x = 6*case_width + 20;
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

Case& Plateau::getCase(unsigned int x) const {
    return *cases[x];
}
