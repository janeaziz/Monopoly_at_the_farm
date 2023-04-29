#include"CaseEnigme.h"

CaseEnigme::CaseEnigme(){
    int n=-3;
    for (int i =0;i < 7 ;i++){
        qe[i]=n;
        qs[i]=n;
        n++;
    }
}


int CaseEnigme::get_qe(int i ) const{
    return qe[i];
}

int CaseEnigme::get_qs(int i) const{
    return qs[i];
}