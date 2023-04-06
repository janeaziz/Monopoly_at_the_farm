#include"Couleur.h"
#include"Case.h"
#include <string>
#ifndef _CASEENIGME_H
#define  _CASEENIGME_H

class CaseEnigme: public Case {
    private:
    int eau;
    int soleil;

    private:
    /**
     * @brief COnstructeur par defaut  de la classe CaseEnigme 
    */
    CaseEnigme();

    /**
     * @brief Constructeur de la classe 
     * @param que
     * @param qs
    */
    CaseEnigme(int qe, int qs);

};




















/*class CaseEnigme: public Case{

    private:
    std::string question;
    bool reponse;

    public:

    /
    void poser_question();

  
    void verifie_reponse();

    std::string & get_question() const;


    
    void set_couleur(Couleur c);

    
    bool & get_reponse() const;


};*/

#endif