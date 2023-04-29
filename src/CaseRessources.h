
#include "Case.h"
#ifndef _CASERESSOURCES_H
#define  _CASERESSOURCES_H


    class CaseRessources: public Case {
        private:

        int q_eau;
        int q_soleil;
     //   Couleur c;

        public:
        

        /**
         * @brief Construct a new Case Ressources object
         * 
         * @param e 
         * @param s 
         */
        CaseRessources(int e, int s, int position, std::string letype);


        /**
         * @brief Destroy the Case Ressouces object
         * 
         */
        ~CaseRessources();


      
        

        /**
         * @brief Get the eau object
         * 
         * @return int 
         */

        int get_eau() const ;
        


        /**
         * @brief Get the soleil object
         * 
         * @return int 
         */
        int get_soleil() const;

        




    };
#endif


