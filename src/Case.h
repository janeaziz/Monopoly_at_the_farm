#include <string>
#ifndef CASE_H
#define CASE_H



using namespace std;

class Case{
    protected:

    int pos;
    std::string type;
     

    public:

    /**
     * @brief Construct a new Case object
     * 
     */
    Case();
    /**
     * @brief Construct a new Case object
     * 
     * @param i 
     */
  //  Case(int i);
    Case(int indice, std::string t);

    virtual ~Case();


/**
 * @brief Set the type object
 * 
 * @param letype 
 */

    void set_type(std::string letype);

    /**
     * @brief Get the pos object
     * 
     * @return int 
     */
    int get_pos()const;

//fonctions CasePropriete
    virtual void set_prix(unsigned int i);

    virtual int get_prix()const;

    virtual  int get_proprio() const;

    virtual int get_loyer()const;

    virtual void set_proprio(int i);

    virtual int get_nb_arbre()const;

    virtual int get_nb_jardin()const;

    virtual void set_nb_jardin(int i);

    virtual void set_nb_arbre(int i);

    virtual int calculer_loyer();

    virtual void set_loyer(int nouveau_montant);
//fonction CaseArgent
    virtual int get_montant()const;
    virtual void set_montant(int montant);

//fonctions CaseRessources
    virtual int get_eau() const;   
    
    virtual int get_soleil() const; 
//fonctions CaseEnigme
    virtual int get_qe(int i) const;

    virtual int get_qs(int i) const;

   

};



#endif