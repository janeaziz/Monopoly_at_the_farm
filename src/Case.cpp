#include"Case.h"

#include<iostream>
using namespace std;

Case::Case(int indice, std::string t){
    pos=indice;
    type=t;

}

Case::Case(int indice){
    type="null";
    pos=indice;
}
void Case::set_type(std::string t){
    type=t;
}