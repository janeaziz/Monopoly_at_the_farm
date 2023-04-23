#include "Couleur.h"
#include "Case.h"
#include "Joueur.h"
#include<iostream>


using namespace std;
#ifndef _CASEPROPRIETE_H
#define _CASEPROPRIETE_H


class CasePropriete : public Case{

    private:

        Couleur c;
        int prix; // prix du terrain
        int proprio;
        int loyer; // loyer  que l'adversaire paye s'il arrive sur cette case
        int nb_arbre;
        int nb_arbre_max;
        bool nb_jardin;


    public:

    /**
     * 
    */
    CasePropriete();

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
        CasePropriete(Couleur c, int prix_achat, int pos, std::string type, int l, int proprietaire, int arb, int jard, int nba_max); 
        

        ~CasePropriete();
        
        /**
         * @brief Get the prix object
         * 
         * @return int 
         */
        int get_prix()const;

        /**
         * @brief Set the prix object
         * 
         * @param x 
         */
        void set_prix(unsigned int x);

        /**
         * @brief Get the loyer object
         * 
         * @return int 
         */

        int get_loyer()const;
    

        /**
         * @brief Set the loyer object, donne le nouveau montant du loyer 
         * en fonction du nb d'arbres, jardin
         * 
         * @param nouveau_montant 
         */

        void set_loyer(int nouveau_montant); //prend la fonction calculer loyer en parametre

        
        /**
         * @brief calcule le nouveau loyer en fonction du nombre d'abre et de jardins
         * 
         * @return int 
         */
        int calculer_loyer();

        /**
         * @brief Get the proprio object
         * 
         * @return int 
         */
         virtual int get_proprio() const;

       
        /**
         * @brief Set the proprio object
         * 
         * @param j 
         */
        virtual void set_proprio(int i);


        virtual void set_nb_arbre(int i);

        virtual int get_nb_arbre()const;

        virtual void set_nb_jardin(int i);
        
        virtual int get_nb_jardin()const;


};

#endif