
#include"Case.h"
#include <string>
#ifndef _CASEENIGME_H
#define  _CASEENIGME_H



class CaseEnigme: public Case{
    private:

    int qe[7];
    int qs[7];

    public:
     /**
      * @brief Constructeur par defaut de la classe caseenigme
      * 
      */
    CaseEnigme();

   

    int get_qe(int i) const;

    int get_qs(int i) const;
};

#endif





























