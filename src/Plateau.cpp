

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
//#include "CasePropriete.h"
//#include "Couleur.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;



Plateau::Plateau() {
    // Création des cases du plateau
    
    for (int i = 0; i < 20; i++) {

        int proprietaire_terrain=-1;
        Couleur rouge;
        rouge= Couleur(255,255,255);
        /*rouge.setRouge(255);
        rouge.setVert(0);
        rouge.setBleu(0); */
       
        
        if (i == 0) {
            cases[i] = new Case(i, "Case départ");
            //cases[i]->set_type();
        } else if (i==2 || i==3 || i==4 || i==6 || i==7 || i==11 ||i==12|| i==13|| i==17|| i==18 ) {
            cases[i] = new CasePropriete(rouge, 200,i, "Case propriete", 50, proprietaire_terrain, 0, 0, 3 );
             cout<<"ca marche"<<endl;
            cout<<"le prix est "<<cases[i]->get_prix()<<endl;
           
        }
        else if (i==8 || i==15){
            cases[i] = new Case(i, "Case enigme");
            //cases[i]->set_type("Case enigme");
        }
        else if (i==1 || i==10 || i==16 || i==19)
        {
            //cases[i] = new Case(i, "Case argent");
            if (i==1 || i==10){
                cases[i]=new CaseArgent(200,i,"Case Argent");
                cout<< "Il a gagne "<<cases[i]->get_montant()<<" euros"<<endl;
            }
            else{
                cases[i]=new CaseArgent(-200,i,"Case Argent");
                cout<< "Il a perdu "<<cases[i]->get_montant()<<" euros"<<endl;
            }    
        }
        else{
            cases[i] = new Case(i, "Case Ressources");
           // cases[i]->set_type("Case Ressources") ;// il ya 3 cases 
        }


    }
}

 Plateau::~Plateau() {
    // Suppression des cases du plateau
    for (int i = 0; i < 20; i++) {
     delete cases[i];
    }
}




Case& Plateau::getCase(unsigned int x) const {
    return *cases[x];
}
