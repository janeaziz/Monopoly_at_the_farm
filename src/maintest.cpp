#include "Plateau.h"
#include "vue.h"
//#include "controleur.h"
#include "Jeu.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    Jeu j;
    
    cout<<"ARBRES "<<j.getPlateau()->getCase(2).get_nb_arbre()<<endl;
    
    


}