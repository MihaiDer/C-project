#include <iostream>
#include "Cheltuiala.h"
#pragma once

using namespace std;

Cheltuiala::Cheltuiala() {
//    cout<<"Default constructor"<<"\n";
    nrApartament = 0;
    suma = 0;
    type = nullptr;
}

Cheltuiala::Cheltuiala(int nrAp, int sum, char *tip) {
//    cout<<"Parameters constructor"<<"\n";
    nrApartament = nrAp;
    suma = sum;
    type = new char[strlen(tip) + 1];
    strcpy(type, tip);
}

Cheltuiala::Cheltuiala(const Cheltuiala &c) {
//    cout<<"Copy constructor"<<"\n";
    nrApartament = c.nrApartament;
    suma = c.suma;
    type = new char[strlen(c.type) + 1];
    strcpy(type, c.type);
}

Cheltuiala::~Cheltuiala(){
    delete[] type;
}

int Cheltuiala::getNrAp() const {
    return nrApartament;
}

int Cheltuiala::getSuma() const {
    return suma;
}

char* Cheltuiala::getType() {
    return type;
}

void Cheltuiala::setNrAp(int nrAp) {
    nrApartament = nrAp;
}

void Cheltuiala::setSuma(int sum) {
    this->suma = sum;
}

void Cheltuiala::setType(char *tip) {
    if(type)
        delete[] type;
    this->type = new char [strlen(tip) + 1];
    strcpy(type, tip);
}

bool Cheltuiala::operator==(const Cheltuiala &c) {
//    cout<<"Operator =="<<"\n";
    return(this->nrApartament == c.nrApartament && this->suma == c.suma &&
            strcmp(this->type, c.type) == 0);
}

bool Cheltuiala::operator!=(const Cheltuiala &c) {
//    cout<<"Operator !="<<"\n";
    return(this->nrApartament != c.nrApartament && this->suma != c.suma &&
           strcmp(this->type, c.type) != 0);
}

Cheltuiala &Cheltuiala::operator=(const Cheltuiala &c) {
    if(this != &c){
        this->suma = c.suma;
        this->nrApartament = c.nrApartament;
        setType(c.type);
    }
    return *this;
}

ostream &operator<<(ostream &os, const Cheltuiala &c) {
    os<<"Cheltuiala este: numar apartament:"<<c.nrApartament<<" , suma:"<<c.suma<<" , tip:"<<c.type<<"\n";
    return os;
}
