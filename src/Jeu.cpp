#include"Jeu.h"
#include<iostream>
#include<stdlib.h>
using namespace std;


Jeu::Jeu() {
    plateau = Plateau(); // Initialisation du plateau
    joueurs = new Joueur[2]; // Initialisation des joueurs
    ajouter_joueur();
    joueur_actuel = 0; // Initialisation du joueur actuel
    gagnant = -1; // Initialisation du gagnant à -1 
}

Jeu::~Jeu(){
    
    if (joueurs != nullptr) {
        delete [] joueurs;
        joueurs = nullptr;
    }
    joueur_actuel=-1;
    gagnant=-1;
}

unsigned int Jeu::jete_de(){
    srand(time(NULL));
    unsigned int de;
    de = rand()% 6 +1;

    cout<<"la val du de "<<de <<endl;
    return de;

}

void Jeu::bouge(int x){
    int pos;
    pos =joueurs[joueur_actuel].getPosition() + x;
    if (pos <20){
        joueurs[joueur_actuel].setPosition(joueurs[joueur_actuel].getPosition() + x);
        cout<<"la nv pos du j est "<< joueurs[joueur_actuel].getPosition() <<endl;
    }else{
        pos= pos -20;
        joueurs[joueur_actuel].setPosition(pos);
        cout<<"la nv pos du j est "<< joueurs[joueur_actuel].getPosition() <<endl;
    }
    
    
}

void Jeu::ajouter_joueur(){
    Joueur j1(0);
    Joueur j2(1) ;
    joueurs[0]= Joueur(j1);
    joueurs[1]= Joueur(j2) ;
    //cout<< "2 joueurs sont initialises "<< joueurs[0]->id<< "le 2 eme "<< joueurs[1]->id<<endl;
}

void Jeu:: tour_suivant(){
    if(joueur_actuel==0){
        joueur_actuel=1;
    }
    else{
        joueur_actuel=0;
    }

}

void Jeu::joue_tour(){
    int i=joueurs[joueur_actuel].getPosition();
    int argent_actuel=joueurs[joueur_actuel].getArgent();
    
    if (i==1 || i==10 || i==16 || i==19){  //s'il est sur une case Argent
        int montant_case=plateau.getCase(i).get_montant();
        joueurs[joueur_actuel].setArgent (argent_actuel + montant_case);
    }
}

Joueur Jeu::getJoueurs(int id) const{
    return joueurs[id];
}

unsigned int Jeu::getJoueurActuel()const{
    return joueur_actuel;
}

void Jeu:: setJoueurActuel(unsigned int i){
    joueur_actuel=i;
}