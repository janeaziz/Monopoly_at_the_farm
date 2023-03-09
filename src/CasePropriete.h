#include "Couleur.h"
#include "Case.h"
#include"Joueur.h"
#ifndef _CASEPROPRIETE_H
#define _CASEPROPRIETE_H

class CasePropriete: public Case{

    private:

        Couleur c;
        int prix; // prix du terrain
        Joueur proprio;
        int loyer; // loyer  que l'adversaire paye s'il arrive sur cette case
        int nb_arbre;
        int nb_arbre_max;
        bool nb_jardin;


    public:

        /**
         * @brief Construct a new Case Propriete object
         * on initialise la couleur 
         * le prix du terrain qui change pas 
         * le loyer qui commence a une valeur et qui augmente en fonction de nb arbre et jardin 
         * nb arbre/ jardin sur le terrain  
         * nb arbre max sur chaque terrain 
         * 
         * @param c 
         * @param p 
         * @param l 
         * @param j 
         * @param arb 
         * @param jard 
         */
        CasePropriete(Couleur c, int p, int l, Joueur j, int arb, int jard); 
        

        /**
         * @brief Get the prix object
         * 
         * @return int 
         */
        int get_prix();

        /**
         * @brief Get the loyer object
         * 
         * @return int 
         */

        int get_loyer();


        /**
         * @brief Set the loyer object, donne le nouveau montant du loyer 
         * en fonction du nb d'arbres, jardin
         * 
         * @param nouveau_montant 
         */

        void set_loyer(int nouveau_montant); //prend la fonction calculer loyer en parametre

        void afficher();

        int calculer_loyer();

        void set_proprio(Joueur proprietaire);



};

#endif