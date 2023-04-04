#include"Jeu.h"
#include<iostream>
#include<stdlib.h>
using namespace std;


Jeu::Jeu() {
  

   
   joueurs[1].setid(1);

    joueur_actuel = 0; // Initialisation du joueur actuel
    gagnant = -1; // Initialisation du gagnant à -1 
}

/*Jeu::~Jeu(){
    /*
 for(int i=0;i<2;i++){
        joueurs[i]=NULL;
        
    } 
  

    joueur_actuel=0;
    gagnant=-1;  
} */

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
    //Joueur j1(0);
    //Joueur j2(1) ;
    //joueurs[0]= Joueur(0);
    //joueurs[1]= Joueur(1) ;
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
    
    int joueur_adverse;
    if (joueur_actuel==0) joueur_adverse=1;
    else joueur_adverse=0;
    int i=joueurs[joueur_actuel].getPosition();
    int argent_actuel=joueurs[joueur_actuel].getArgent();
    int argent_actuel_adverse=joueurs[joueur_adverse].getArgent();
    int eau_actuel=joueurs[joueur_actuel].getEau();
    int soleil_actuel=joueurs[joueur_actuel].getSoleil();
    
    
    if (i==1 || i==10 || i==16 || i==19){  //s'il est sur une case Argent
        cout<<"on est dans la boucle case argent "<<endl;
        int montant_case=plateau.getCase(i).get_montant();
        cout<<"montant case argent "<< montant_case<<endl;;
        joueurs[joueur_actuel].setArgent (argent_actuel + montant_case);
        cout<<"montan gagne"<<joueurs[joueur_actuel].getArgent ()<<endl;
    }

    if (i==5 || i==9 || i==14){  // s'il est sur une case ressources
        int nb_eau = plateau.getCase(i).get_eau();
        int nb_soleil = plateau.getCase(i).get_soleil();
        joueurs[joueur_actuel].setEau(eau_actuel + nb_eau);
        joueurs[joueur_actuel].setSoleil(soleil_actuel + nb_soleil);
    }

    if (i==2 || i==3 || i==4 || i==6 || i==7 || i==11 ||i==12|| i==13|| i==17|| i==18 ) { // s'il est sur une case Propriete
        int proprio_case=plateau.getCase(i).get_proprio();
        int loyer_case=plateau.getCase(i).get_loyer();
        if(proprio_case == joueur_adverse){ // si le proprio est le joueur adverse
            joueurs[joueur_actuel].setArgent(argent_actuel - loyer_case);
            joueurs[joueur_adverse].setArgent(argent_actuel_adverse + loyer_case);
        }
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