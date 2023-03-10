

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
    const char* images_filenames[5] = {
        "data/CasePropriete.png", 
        "data/CaseRessources.png", 
        "data/CaseEnigme.png", 
        "data/CaseArgent.png",
        "data/CaseDepart.png" // On ajoute une image pour la case départ
    };

    for (int i = 0; i < 20; i++) {
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
        } else {
            //Case de type Ressources
            images[i] = IMG_LoadTexture(renderer, images_filenames[1]);
        }
        if(images[i]){
            cout<< "l'image " <<i << "n'a pas ete charge"<<endl;
        }
        
    }
}


void Plateau::dessiner(SDL_Renderer* renderer) {
    // Dessin du plateau en utilisant les images des cases
    charger_images(renderer);
    for (int i = 0; i < 20; i++) {
        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = case_width;
        rect.h = case_height;
        
        SDL_RenderCopy(renderer, images[i], nullptr, &rect);
        /*if (i % 5 == 4) {
            rect.x = 0;
            rect.y += 100;
        } else {
            rect.x += 100;
        }*/
        rect.x= i%5 * case_width *2 + case_width;
        rect.y=i/5 * case_height *2 + case_height;

    }
    SDL_RenderPresent(renderer);
}

Case& Plateau::getCase(unsigned int x) const {
    return *cases[x];
}
