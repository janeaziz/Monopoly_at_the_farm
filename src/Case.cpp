#include"Case.h"
#include <string>
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
