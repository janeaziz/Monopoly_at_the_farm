
#include <SDL.h>
#include <SDL_ttf.h>
#include "CasePropriete.h"
#include "Case.h"


#ifndef _JOUEUR_H
#define _JOUEUR_H

class Joueur {
    private:

    unsigned int id;
    unsigned int argent;
    int quantite_eau;
    int quantite_soleil;
    int nb_arbre;
    int nb_jardin;
    CasePropriete tab_propriete;
    unsigned int position; //indice de la case
    SDL_Rect image; // Image du joueur pour SDL2
    TTF_Font *font; // Police pour afficher le nom du joueur
    SDL_Renderer *renderer; // Renderer pour SDL2

    public:

    /**
    * @brief Construit un nouveau Joueur
    * 
    * @param renderer Renderer pour SDL2
    * @param font Police pour afficher le nom du joueur
    * 
    */
    Joueur(SDL_Renderer *renderer, TTF_Font *font);

    /**
    * @brief Destructeur de Joueur
    * 
    */
    ~Joueur();

    /**
     * @brief Accesseur pour avoir la valeur de quantite_eau
     * 
     * @return int& 
     */
    int & getEau () const;

    /**
     * @brief Accesseur pour avoir la valeur de quantite_soleil
     * 
     * @return int& 
     */
    int & getSoleil () const;

    /**
     * @brief Accesseur pour avoir la valeur de argent
     * 
     * @return unsigned int& 
     */
    unsigned int & getArgent () const;

    /**
     * @brief Accesseur pour avoir la valeur de quantite_eau
     * 
     * @return int& 
     */
    int & getEau () const;

    /**
     * @brief Accesseur pour avoir la valeur de position
     * 
     * @return int& 
     */
    int & getPosition () const;

    /**
     * @brief Accesseur pour l'image du joueur
     * 
     * @return SDL_Rect& 
     */
    SDL_Rect & getImage() const;

    /**
     * @brief Mutateur pour l'image du joueur
     * 
     * @param rect Nouvelle image
     */
    void setImage(SDL_Rect rect);


    /**
    * @brief Mutateur de la donnée membre eau
    * 
    * @param x 
    */
    void setEau (int x);
   
    /**
    * @brief Mutateur de la donnée membre soleil
    * 
    * @param x 
    */
    void setSoleil (int x);

    /**
    * @brief Mutateur de la donnée membre argent
    * 
    * @param x 
    */
    void setArgent (unsigned int x);

    /**
    * @brief Mutateur de la donnée membre position
    * 
    * @param x 
    */
    void setPosition (unsigned int x);

    /**
    * @brief Additionne x (ou la soustrait si elle est negative) a la valeur de quantite_eau
    * 
    * @param x 
    */
    void modifierEau (int x);

    /**
    * @brief Additionne x (ou la soustrait si elle est negative) a la valeur de quantite_soleil
    * 
    * @param x 
    */
    void modifierSoleil (int x);

    /**
    * @brief Additionne x (ou la soustrait si elle est negative) a la valeur de argent
    * 
    * @param x 
    */
    void modifierArgent (int x);

    void payer_loyer(const CasePropriete* p);

    /**
     * @brief cette fonction va gerer tous les changements a chaque tour:
     * si c'est une case de gain d'argent, on augmente l'argent de la valeur voulue
     * si c'est un terrain, soit il l'achete si elle est libre soit doit payer a l'adversaire
     * si elle appartient a ce dernier
     * 
     */
    void tour_de_jeu(const Case* case_actuel);

    /**
     * @brief cette fonction permet d'incrementer nb_arbre de Joueur et
     * diminue ainsi l'argent de "argent" du Joueur
     * 
     */
    void acheter_arbre();

    /**
     * @brief cette fonction permet d'incrementer nb_jardin de Joueur et
     * diminue ainsi l'argent de "argent" du Joueur
     * 
     */
    void acheter_jardin();

    /**
     * @brief cette fonction permet de rajouter un arbre dans le tableau de proprietes de Joueur et
     * diminue ainsi l'argent de "argent" du Joueur
     * 
     */
    void acheter_propriete(const CasePropriete* p);


};
#endif