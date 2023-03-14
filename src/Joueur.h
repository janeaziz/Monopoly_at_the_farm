#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
//#include "CasePropriete.h"
#include "Case.h"

class CasePropriete;
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
    CasePropriete * tab_propriete [10];
    unsigned int position; //indice de la case
    SDL_Texture *image; // Image du joueur pour SDL2
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
    Joueur(int id, SDL_Renderer *renderer, TTF_Font *font);

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
    int  getEau () const;

    /**
     * @brief Accesseur pour avoir la valeur de quantite_soleil
     * 
     * @return int& 
     */
    int getSoleil () const;

    /**
     * @brief Accesseur pour avoir la valeur de argent
     * 
     * @return unsigned int& 
     */
    unsigned int getArgent () const;

    
    /**
     * @brief Accesseur pour avoir la valeur de position
     * 
     * @return int& 
     */
    unsigned int getPosition () const;

    /**
     * @brief Accesseur pour l'image du joueur
     * 
     * @return SDL_Rect& 
     */
    SDL_Texture* getImage() const;

    /**
     * @brief Mutateur pour l'image du joueur
     * 
     * @param rect Nouvelle image
     */
    void setImage(SDL_Texture* im);


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





   
};
#endif


