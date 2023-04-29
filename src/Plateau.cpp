
#include "Plateau.h"
//#include "CasePropriete.h"
//#include "Couleur.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>

#include <iostream>
using namespace std;



Plateau::Plateau() {
    // Création des cases du plateau
    //cases = new Case[20];
    
    for ( int i = 0; i < 20; i++) {

        int proprietaire_terrain=2;
        Couleur rouge;
        rouge= Couleur(255,255,255);
        /*rouge.setRouge(255);
        rouge.setVert(0);
        rouge.setBleu(0); */
       
        
        if (i == 0) {
            cases[i] =  new Case(i, "Case départ");
            //cases[i]->set_type();
        } else if (i==2 || i==3 || i==4 || i==6 || i==7 || i==11 ||i==12|| i==13|| i==17|| i==18 ) {
            cases[i] =  new CasePropriete(rouge, 200,i, "Case propriete", 50, proprietaire_terrain, 0, 0, 3 );
            CasePropriete* CaseProp= dynamic_cast<CasePropriete*>(cases[i]);
             //cout<<"ca marche"<<endl;
           // cout<<"le prix est "<<cases[i]->get_prix()<<endl;
           
        }
        else if (i==8 || i==15){
            cases[i] = new CaseEnigme();
            CaseEnigme* caseEnigme2= dynamic_cast<CaseEnigme*>(cases[i]);
            //cout<<"il gagne ou per "<<cases[i]->get_qe()<<cases[i]->get_qs()<<endl;
            //cases[i]->set_type("Case enigme");
        }
        else if (i==1 || i==10 || i==16 || i==19)
        {
            //cases[i] = new Case(i, "Case argent");
            if (i==1 || i==10){
                cases[i]= new CaseArgent(200,i,"Case Argent");
                CaseArgent* caseArg= dynamic_cast<CaseArgent*>(cases[i]);
              //  cout<< "Il a gagne "<<caseArg->get_montant()<<" euros"<<endl;
            }
            else{
                cases[i]= new CaseArgent(-200,i,"Case Argent");
                CaseArgent* caseArg2= dynamic_cast<CaseArgent*>(cases[i]);
               
               // cout<< "Il a perdu "<<caseArg2->get_montant()<<" euros"<<endl;
            }    
        }
        else{
            cases[i] = new CaseRessources(2, 2, i, "Case Ressources");
            CaseRessources* caseRes= dynamic_cast<CaseRessources*>(cases[i]);
            //cout<< "Il a gagne "<<caseRes->get_eau()<<" unites d'eau et "<<cases[i]->get_soleil()<<" de soleil"<<endl;
        }


    }
}

 Plateau::~Plateau() {
    // Suppression des cases du plateau
  /* if (cases != nullptr) {
        delete [] cases;
        cases = nullptr;
    }  */

    for (int i=0;i<20;i++){
        if(cases[i] != nullptr){
            delete cases[i];
            cases[i]=nullptr;
        }    
    } //delete [] cases;
}




Case& Plateau::getCase(unsigned int x) const {
    return *cases[x];
}

void Plateau::testRegressionPlateau(){

    //on teste en meme temps le constructeur de Plateau, getCase et les fonctions des differentes cases

    //fonctions de CasePropriete
    getCase(2).set_loyer(60);
    assert(getCase(2).get_loyer()==60); //test get_loyer et set_loyer

    getCase(2).set_prix(250);
    assert(getCase(2).get_prix()==250); //test get_prix et set_prix 

    getCase(2).set_proprio(1);
    assert(getCase(2).get_proprio()==1); //test get_proprio et set_proprio

    getCase(2).set_nb_arbre(2);
    assert(getCase(2).get_nb_arbre()==2); //test get et set_nb_arbre

    getCase(2).set_nb_jardin(1);
    assert(getCase(2).get_nb_jardin()==1); //test get et set_nb_jardin

    assert(getCase(2).calculer_loyer()==350); //test fonction calculer_loyer


    //test fonctions Case Enigme
    assert(getCase(8).get_qe(0)==-3); //test get_qe
    assert(getCase(8).get_qs(1)==-2); //test get_qs

    //test fonctions Case Argent
    getCase(1).set_montant(150);                                  
    assert(getCase(1).get_montant()==150);//on teste si la case Argent a bien ete cree

    //test fonctions de Case Ressources
    assert(getCase(5).get_eau()==2);
    assert(getCase(5).get_soleil()==2);
    
    //test pour la fonction de Case
    assert(getCase(6).get_pos()==6);

}