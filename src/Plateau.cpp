
#include "Plateau.h"
//#include "CasePropriete.h"
//#include "Couleur.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;



Plateau::Plateau() {
    // Création des cases du plateau
    //cases = new Case[20];
    
    for ( int i = 0; i < 20; i++) {

        int proprietaire_terrain=-1;
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
             cout<<"ca marche"<<endl;
            cout<<"le prix est "<<cases[i]->get_prix()<<endl;
           
        }
        else if (i==8 || i==15){
            cases[i] =  new Case(i, "Case enigme");
            //cases[i]->set_type("Case enigme");
        }
        else if (i==1 || i==10 || i==16 || i==19)
        {
            //cases[i] = new Case(i, "Case argent");
            if (i==1 || i==10){
                cases[i]= new CaseArgent(200,i,"Case Argent");
                CaseArgent* caseArg= dynamic_cast<CaseArgent*>(cases[i]);
                cout<< "Il a gagne "<<caseArg->get_montant()<<" euros"<<endl;
            }
            else{
                cases[i]= new CaseArgent(-200,i,"Case Argent");
                CaseArgent* caseArg2= dynamic_cast<CaseArgent*>(cases[i]);
               
                cout<< "Il a perdu "<<caseArg2->get_montant()<<" euros"<<endl;
            }    
        }
        else{
            cases[i] = new CaseRessources(2, 2, i, "Case Ressources");
            CaseRessources* caseRes= dynamic_cast<CaseRessources*>(cases[i]);
            cout<< "Il a gagne "<<caseRes->get_eau()<<" unites d'eau et "<<cases[i]->get_soleil()<<" de soleil"<<endl;
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
