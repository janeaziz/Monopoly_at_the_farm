#include "Joueur.h"

Joueur::Joueur(int id, SDL_Renderer *renderer, TTF_Font *font){
    
    id =id;
    argent=1500;
    quantite_eau=3;
    quantite_soleil=3;
    nb_arbre=0;
    nb_jardin=0;
    this->renderer=renderer;
    this->font=font;
    this->image(0,0,100,100);
    tab_propriete=nullptr;
    position=0;



}

Joueur::Joueur(){
    if(tab_propriete!= nullptr){
        delete [] tab_propriete;
         tab_propriete = nullptr;
}
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(image);
    TTF_CloseFont(font);
}

int& Joueur::getEau()const{
    return quantite_eau;
}

int& Joueur::getSoleil()const{
    return quantite_soleil;
}

unsigned int& Joueur::getArgent()const{
    return argent;
}

int& Joueur:: getPosition()const{
    return position;
}

SDL_Rect & Joueur:: getImage() const{
    return this->image;

}

void Joueur:: setImage(SDL_Rect rect){
    image=rect;
}

void setEau (int x){
    quantite_eau=x;
}

void setSoleil (int x){
    quantite_soleil=x;
}

void setArgent (unsigned int x){
    argent=x;
}

void setPosition (unsigned int x){
    position=x;
}

