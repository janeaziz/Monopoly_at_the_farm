#include"Couleur.h"
#ifndef _CASERESSOURCES_H
#define  _CASERESSOURCES_H


    class CaseRessources {
        private:

        int q_eau;
        int q_soleil;
        Couleur c;

        public:
        

        /**
         * @brief Construct a new Case Ressources object
         * 
         * @param e 
         * @param s 
         */
        CaseRessources(int e, int s);


        /**
         * @brief Set the couleur caser object
         * 
         * @param col 
         */
        void set_couleur_caser(Couleur col);

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


