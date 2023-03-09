#include"Couleur.h"
#include"Case.h"
#include <string>
#ifndef _CASEENIGME_H
#define  _CASEENIGME_H


class CaseEnigme:Case{

    private:
    std::string question;
    bool reponse;

    public:

    /**
     * @brief Elle pose la question a l'utilisateur grace a SDL2
     * 
     */
    void poser_question();

    /**
     * @brief Elle verifie la reponse de l'utilisateur grace a SDL2
     * 
     */
    void verifie_reponse();

    /**
     * @brief accesseur pour la donnee membre question
     * 
     * @return std::string& 
     */
    std::string & get_question() const;


    /**
     * @brief mutateur de couleur
     * 
     * @param c 
     */
    void set_couleur(Couleur c);

    /**
     * @brief accesseur pour la donnee membre reponse
     * 
     * @return true 
     * @return false 
     */
    bool & get_reponse() const;


};

#endif