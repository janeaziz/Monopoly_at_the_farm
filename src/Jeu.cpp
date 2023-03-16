#include"Jeu.h"
#include<iostream>
#include<stdlib.h>
using namespace std;



unsigned int Jeu::jete_de(){
    srand(time(NULL));
    unsigned int de;
    de = rand()% 6 +1;

    cout<<"la val du de "<<de <<endl;
    return de;

}

void Jeu::bouge(int x){
    joueurs[joueur_actuel].setPosition(joueurs[joueur_actuel].getPosition() + x);
    cout<<"la nv pos du j est "<< joueurs[joueur_actuel].getPosition() <<endl;
}

void Jeu::ajouter_joueur(SDL_Renderer *renderer,TTF_Font *font){
    Joueur j1(0,renderer,font);
    Joueur j2(1,renderer,font) ;
    joueurs[0]= Joueur(j1);
    joueurs[1]= Joueur(j2) ;
    //cout<< "2 joueurs sont initialises "<< joueurs[0]->id<< "le 2 eme "<< joueurs[1]->id<<endl;
}

void Jeu:: tour_suivant(){
    if(joueur_actuel==0){
        joueur_actuel=1;
    }else{
        joueur_actuel=0;
    }

}

void Jeu::joue_tour(){
    
}