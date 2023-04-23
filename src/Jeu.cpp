#include"Jeu.h"
#include "controleur.h"
#include"vue.h"
#include<iostream>
#include<stdlib.h>
using namespace std;


Jeu::Jeu() {
  

   
   joueurs[1].setid(1);

    joueur_actuel = 0; // Initialisation du joueur actuel
    gagnant = 2; // Initialisation du gagnant à -1 
}

/*Jeu::~Jeu(){
    
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


 void Jeu::set_gagnant(unsigned int i){
    gagnant=i;
 }

unsigned int Jeu::get_gagnant()const{
    return gagnant;
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

/*void Jeu::ajouter_joueur(){
    //Joueur j1(0);
    //Joueur j2(1) ;
    //joueurs[0]= Joueur(0);
    //joueurs[1]= Joueur(1) ;
    //cout<< "2 joueurs sont initialises "<< joueurs[0]->id<< "le 2 eme "<< joueurs[1]->id<<endl;
}*/

bool Jeu:: tour_suivant(){
    if(joueur_actuel==0){
        joueur_actuel=1;
    }
    else{
        joueur_actuel=0;
    }
    return true;

}


int Jeu::joue_tour(SDL_Renderer* renderer,SDL_Color c,SDL_Event event,bool &propriete_achetee,bool &non_achetee){
    int questions=-1;
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
        
        if (montant_case<0){
            if(argent_actuel>=200) questions=3;    //si argent suffisant
            else if(argent_actuel<200) questions=25; //si argent pas suffisant
        } else questions=4;
        
        cout<<"montant case argent "<< montant_case<<endl;;
        joueurs[joueur_actuel].setArgent (argent_actuel + montant_case);
        cout<<"montan gagne"<<joueurs[joueur_actuel].getArgent ()<<endl;
    }

    if(i==8 || i== 15){
        cout<<"on est dans la boucle de case enigme"<<endl;
        srand(time(NULL));
        int indice;
        indice= rand()%7;

        int indice_joueur=rand()% 2;
        int eau_actuel=joueurs[joueur_actuel].getEau();
        int soleil_actuel=joueurs[joueur_actuel].getSoleil();
        int eau_adversaire=joueurs[joueur_adverse].getEau();
        int soleil_adversaire=joueurs[joueur_adverse].getSoleil();

        int eau_case=plateau.getCase(i).get_qe(indice); 
        int soleil_case=plateau.getCase(i).get_qs(indice); 

        switch(eau_case){
            case 0:
                questions=10;
                break;
            case 1:
                questions=7;
                break;

            case 2:
                questions=8;
                break;

            case 3:
                questions=9;
                break; 

            case -1:
                questions=11;
                break; 

            case -2:
                questions=12;
                break; 

            case -3:
                questions=13;
                break;                          
        }

    
            
        joueurs[joueur_actuel].setEau(eau_actuel+eau_case);
        joueurs[joueur_adverse].setEau(eau_adversaire-eau_case);
        joueurs[joueur_actuel].setSoleil(soleil_actuel+soleil_case);
        joueurs[joueur_adverse].setSoleil(soleil_adversaire-soleil_case);
       

    }

    if (i==5 || i==9 || i==14){  // s'il est sur une case ressources
        int nb_eau = plateau.getCase(i).get_eau();
        int nb_soleil = plateau.getCase(i).get_soleil();
        if (nb_eau < 0){
            questions=5;
        } else questions=6;
        joueurs[joueur_actuel].setEau(eau_actuel + nb_eau);
        joueurs[joueur_actuel].setSoleil(soleil_actuel + nb_soleil);
    }

    if (i==2 || i==3 || i==4 || i==6 || i==7 || i==11 ||i==12|| i==13|| i==17|| i==18 ) { // s'il est sur une case Propriete
        int proprio_case=plateau.getCase(i).get_proprio();
        cout<<"proprio case "<< proprio_case<<endl;
        int loyer_case=plateau.getCase(i).get_loyer();
        if(proprio_case == joueur_adverse && argent_actuel>=loyer_case){ // si le proprio est le joueur adverse
            joueurs[joueur_actuel].setArgent(argent_actuel - loyer_case);
            joueurs[joueur_adverse].setArgent(argent_actuel_adverse + loyer_case);
            cout<<"Il paye une taxe de "<<loyer_case<<endl;
            questions=17;
            cout<<"lindice de la question est "<<questions<<endl;
        }
        if(proprio_case == joueur_adverse && argent_actuel<loyer_case){ //si proprio joueur adv et pas assez d'argent
            questions=24;
        }    
        
        
        if(proprio_case == joueur_actuel) {

        // cout<<"on est ds la boucle"<<endl;

            int nb_arbre_case = plateau.getCase(i).get_nb_arbre();

            int nb_arbre_joueur = joueurs[joueur_actuel].get_nbarbre();

            int nb_jardin_case = plateau.getCase(i).get_nb_jardin();

            int nb_jardin_joueur = joueurs[joueur_actuel].get_nbjardin();

            if(nb_arbre_case<3 && argent_actuel>=100){ //si le nombre d'abre de la case est inferieur à 5 et s'il a l'argent necessaire pour l'acheter

                questions=1;

                if(propriete_achetee==true){ //s'il a dit oui

                    cout<<"le nb d arbre avant l achat"<<nb_arbre_case<<endl;

                    plateau.getCase(i).set_nb_arbre(nb_arbre_case + 1);
                    cout<<"le nb d arbre de la case apres achat d arbre"<<nb_arbre_case<<endl;

                    joueurs[joueur_actuel].set_nbarbre(nb_arbre_joueur+1);

                    joueurs[joueur_actuel].setArgent(argent_actuel - 100);

                    int nv_loyer=plateau.getCase(i).calculer_loyer();
                    plateau.getCase(i).set_loyer(nv_loyer);
                    cout<<"Le nouveau loyer "<<plateau.getCase(i).get_loyer()<<endl;

                    propriete_achetee=false;

                    questions=15;

                }

                if(non_achetee==true){
                    non_achetee=false;
                    questions=19;
                    
                }   

            } 
            else if(nb_arbre_case<3 && argent_actuel<100){
                propriete_achetee=false;
                questions=22;   
            }  
            else if(nb_arbre_case==3 && argent_actuel>=200){
                questions=2;
                if(propriete_achetee==true){
                    plateau.getCase(i).set_nb_jardin(nb_jardin_case + 1);

                    joueurs[joueur_actuel].set_nbjardin(nb_jardin_joueur + 1);

                    joueurs[joueur_actuel].setArgent(argent_actuel - 200);

                    joueurs[joueur_actuel].set_nbarbre(nb_arbre_joueur - 3);

                    plateau.getCase(i).set_nb_arbre(0);

                    int nv_loyer=plateau.getCase(i).calculer_loyer();
                    plateau.getCase(i).set_loyer(nv_loyer);
                    cout<<"Le nouveau loyer avec jardin "<<plateau.getCase(i).get_loyer()<<endl;

                    propriete_achetee=false;

                    questions=16;

                }
                if(non_achetee==true){
                    non_achetee=false;
                    questions=20;
                    
                }      
            }
            else if(nb_arbre_case==3 && argent_actuel<200){ //s'il a 3 arbres mais pas l'argent suffisant
                propriete_achetee=false;
                questions=23;
            }   

        }



        if(proprio_case == 2) {
            questions=0;
            cout<<"la question de l'achat terrain"<<endl;
            if(propriete_achetee==true){
                int prix_terrain=plateau.getCase(i).get_prix();
                if(argent_actuel>prix_terrain){
                    plateau.getCase(i).set_proprio(joueur_actuel);
                    cout<<"le proprietaire maintenant est :"<<plateau.getCase(i).get_proprio()<<endl;
                    joueurs[joueur_actuel].setArgent(argent_actuel - prix_terrain);
                    propriete_achetee=false;
                    questions=14;
                }  
                if(argent_actuel<prix_terrain){
                    propriete_achetee=false;
                    questions=21;
                }      
            }
            if(non_achetee==true){
                non_achetee=false;
                questions=18;
                cout<<"non pour l'achat du terrain"<<endl;
                
            }
        }
    }
    return questions;

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

Plateau Jeu::getPlateau() const{
    return plateau;
}