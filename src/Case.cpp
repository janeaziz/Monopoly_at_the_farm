#include"Case.h"
//#include <string>
#include<iostream>
using namespace std;


Case::Case(){
    pos=-1;
    type="NULL";
}
Case::Case(int indice, std::string t){
    pos=indice;
    type=t;

}

Case::~Case(){
    pos=-1;
    type="NULL";
}
/*Case::Case(int indice){
    type="null";
    pos=indice;
} */
void Case::set_type(std::string t){
    type=t;
}

int Case::get_pos()const{
    return pos;
}

//fonction CasePropriete
int Case::get_prix()const{
    return 0;
}

 int Case::get_proprio()const{
    return 0 ;
}

int Case::get_loyer()const{
    return 0;
}

void Case::set_proprio(int i){

}


//fonction CaseArgent
int Case::get_montant()const{
    return 0;
   }
//fonctions CaseRessources
int Case::get_eau() const{
    return 0;
}

int Case::get_soleil() const{
    return 0 ;
}

int Case::get_qs(int indice ) const{
    return 0;
}

int Case::get_qe(int indice ) const{
    return 0;
}

