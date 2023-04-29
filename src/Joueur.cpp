#include "Joueur.h"
#include "CasePropriete.h"
#include "assert.h"

Joueur::Joueur (){
    id =0;
    argent=15000;
    quantite_eau=50;
    quantite_soleil=50;
    nb_arbre=0;
    nb_jardin=0;
    //tab_propriete = nullptr;
  
    position =0;
}
Joueur::Joueur(int idj){ //, SDL_Renderer *renderer, TTF_Font *font){
    
    id =idj;
    argent=15000;
    quantite_eau=50;
    quantite_soleil=50;
    nb_arbre=0;
    nb_jardin=0; 
/*  this->renderer=renderer;
    this->font=font;
   
    this->image = IMG_LoadTexture(renderer,"data/Joueur1.png");
*/
    //tab_propriete = new CasePropriete[10];

    
    
    position =0;

}

Joueur::~Joueur(){

       /* if(tab_propriete != nullptr){
            delete [] tab_propriete;
            tab_propriete= nullptr;
        }*/
    


    /*SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(image);
    TTF_CloseFont(font); */
}

unsigned int Joueur::getid () const{
    return id;    
} 

int Joueur::getEau()const{
    return quantite_eau;
}

int Joueur::get_nbarbre()const{
    return nb_arbre;
}

int Joueur::get_nbjardin()const{
    return nb_jardin;
}

void Joueur::set_nbjardin(int i){
    nb_jardin=i;
}

 void Joueur::set_nbarbre(int i){
    nb_arbre=i;
 }


int Joueur::getSoleil()const{
    return quantite_soleil;
}

unsigned int  Joueur::getArgent()const{
    return argent;
}

unsigned int Joueur::getPosition()const{
    return position;
}

/*CasePropriete Joueur:: get_tab_propriete(int indice) const{
    return tab_propriete[indice];
}


 void Joueur::set_tab_propriete(int indicetab, CasePropriete p){
    tab_propriete[indicetab]=p;
 } */
/*SDL_Texture* Joueur::getImage() const{
    return this->image;

} 


void Joueur::setImage(SDL_Texture* im){
    image=im;
}  */

void Joueur::setid (int idj){
    id=idj;
};

void Joueur::setEau (int x){
    quantite_eau=x;
}

void Joueur::setSoleil (int x){
    quantite_soleil=x;
}

void Joueur::setArgent (unsigned int x){
    argent=x;
}

void Joueur::setPosition (unsigned int x){
    position=x;
}

void Joueur::testRegressionJoueur(){
    //on teste que le constructeur marche
    //Joueur j;
    setid(1);
    assert(getid()==1); //test getid et setid

    set_nbarbre(2);
    assert(get_nbarbre()==2); //test get et set de nb_arbre

    set_nbjardin(3);
    assert(get_nbjardin()==3); //test get et set de nb_jardin

    setArgent(2500);
    assert(getArgent()==2500); // test get et set d'argent

    setEau(5);
    assert(getEau()==5);  //test get et set de quantite_eau

    setSoleil(6);
    assert(getSoleil()==6);  //test get et set de quantite_soleil

    setPosition(7);
    assert(getPosition()==7);  //test get et set de position

    
}