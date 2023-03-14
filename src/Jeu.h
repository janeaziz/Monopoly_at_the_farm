#include "Joueur.h"
#include "Plateau.h"

#ifndef _JEU_H
#define _JEU_H

class Jeu{

    private:
    Plateau plateau;
    Joueur * joueurs;
    unsigned int joueur_actuel;
    unsigned int  gagnant;

    public:

    /**
     * @brief retourne un entier aleatoire entre 1 et 6
     * 
     * @return unsigned int 
     */
    unsigned int jete_de();

    /**
     * @brief bouge le joueur de x cases
     * 
     * @param x 
     */
    void bouge(int x);

    /**
     * @brief Ajoute deux joueurs au jeur en les initialisant
     * 
     */
    void ajouter_joueur(SDL_Renderer *renderer,TTF_Font *font);

    /**
     * @brief alterne vers le Joueur suivant lorsque le joueur courant fini son tour
     * 
     */
    void tour_suivant();

    /**
     * @brief effectue tous les changements sur le Joueur lors du tour (achat, perte 
     * d'argent, de ressources, etc.) 
     * 
     */
    void joue_tour();

    /**
     * @brief retourne vrai si un des Joueurs perd ton son argent
     * 
     * @return true 
     * @return false 
     */
    bool partie_terminee();

    /**
     * @brief accesseur sur le gagnant
     * 
     * @return Joueur 
     */
    Joueur getGagnant();

    /**
     * @brief accesseur sur le joueur_actuel
     * 
     * @return Joueur 
     */
    Joueur getJoueurActuel();


};

#endif

//achat propriete , payer loyer, modofier eau , modifier soleil, modifier argent , achat arbre, achat jardin, 
//doivent etre dans la classe jeu pas joueur. 