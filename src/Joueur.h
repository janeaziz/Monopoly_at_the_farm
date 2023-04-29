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
    unsigned int position;
    public:

    Joueur();
    /**
     * @brief Construit un nouveau Joueur
     * 
     * @param id 
     */
    Joueur(int id); //SDL_Renderer *renderer, TTF_Font *font);

    /**
    * @brief Destructeur de Joueur
    * 
    */
    ~Joueur();

    /**
     * @brief Get the id object
     * 
     * @return unsigned int 
     */
    unsigned int getid () const;

    /**
     * @brief 
     * 
     * @param id 
     */
    void setid (int id); 

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
     * @brief Get the nb arbre object
     * 
     * @return int 
     */
    int get_nbarbre () const;


    void set_nbarbre(int i);

    void set_nbjardin(int i);
    /**
     * @brief Get the nb jardin object
     * 
     * @return int 
     */
    int get_nbjardin () const;
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

    
    


    void testRegressionJoueur();


   
};
#endif


