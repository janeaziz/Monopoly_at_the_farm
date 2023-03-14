#include"CasePropriete.h"
#include"Joueur.h"
#include"Couleur.h"

CasePropriete::CasePropriete(Couleur cl, int pr,int l, Joueur j, int nba, int nbj, int nba_max )
{
    c.setRouge(cl.getRouge());
    c.setVert(cl.getVert());
    c.setBleu(cl.getBleu());
    prix=pr;
    loyer=l;
    nb_arbre=nba;
    nb_arbre_max=nba_max;
    nb_jardin=nbj;
    set_proprio(j);
}

CasePropriete::~CasePropriete(){
    c.setRouge(0);
    c.setVert(0);
    c.setBleu(0);
    
    prix=NULL;
    loyer=NULL;
    nb_arbre=NULL;
    nb_arbre_max=NULL;
    nb_jardin=NULL;
    proprio.~Joueur();



}

int CasePropriete::get_loyer()const{
    return loyer;
}

void CasePropriete::set_loyer(int nv_loyer){
    loyer=nv_loyer;

}

int CasePropriete::calculer_loyer(){
    int nv_loyer;
    for(int i=0;i<6;i++){
        if (nb_arbre==i){
            nv_loyer=nv_loyer+i*40;
        }
    }
    if(nb_jardin==1){
        nv_loyer=nv_loyer+400;
    }
    return nv_loyer;
}

int CasePropriete::get_prix()const{
    return prix;   
}

void CasePropriete::set_prix(unsigned int x){
    prix=x;   
}

const Joueur& CasePropriete::get_proprio()const{
    return proprio;
}

void CasePropriete::set_proprio(Joueur j){
    proprio = j;
}

