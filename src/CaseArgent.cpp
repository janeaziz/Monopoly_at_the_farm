#include <iostream>
#include "CaseArgent.h"

CaseArgent::CaseArgent(int argent,int position,std::string letype){
    montant=argent;
    pos=position;
    type=letype;
}

CaseArgent::~CaseArgent(){
    montant=0;
    pos=-1;
    type="NULL";
}

int CaseArgent::get_montant()const{
    return montant;
};

void CaseArgent::set_montant(int monnaie){
    montant=monnaie;
};
