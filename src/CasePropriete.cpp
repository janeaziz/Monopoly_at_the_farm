#include"CasePropriete.h"
#include"Joueur.h"
#include"Couleur.h"


CasePropriete::CasePropriete() {

    c.setRouge(0);
    c.setVert(0);
    c.setBleu(0);
    prix=0;
    pos=0;
    type="Case Propriete";
    loyer=0;
    nb_arbre=0;
    nb_arbre_max=0;
    nb_jardin=0;
    proprio=1;
}

CasePropriete::CasePropriete(Couleur cl, int pr,int position, std::string type, int l, int propri, int nba, int nbj, int nba_max )
{
    c.setRouge(cl.getRouge());
    c.setVert(cl.getVert());
    c.setBleu(cl.getBleu());
    prix=pr;
    pos=position;
    type="Case Propriete";
    loyer=l;
    nb_arbre=nba;
    nb_arbre_max=nba_max;
    nb_jardin=nbj;
    proprio=propri;

    //set_proprio(j);
}

CasePropriete::~CasePropriete(){
    c.setRouge(0);
    c.setVert(0);
    c.setBleu(0);
    
    prix=0;
    loyer=0;
    nb_arbre=0;
    nb_arbre_max=0;
    nb_jardin=0;
    proprio=0;
    //proprio.~Joueur();



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

  void CasePropriete:: set_nb_arbre(int i){
    nb_arbre=i;
  }

  int CasePropriete:: get_nb_arbre()const{
    return nb_arbre;
  }

int CasePropriete::get_prix()const{
    return prix;   
}

void CasePropriete::set_prix(unsigned int x){
    prix=x;   
}

 int CasePropriete::get_proprio()const{
    return proprio;
}

void CasePropriete::set_proprio(int i){
    proprio = i;
}

