#include <iostream>
#include "cstring"
#pragma once
using namespace std;

class Cheltuiala {
private:
    int nrApartament;
    int suma;
    char* type;
public:
    Cheltuiala();
    Cheltuiala(int nrAp, int sum, char* tip);
    Cheltuiala(const Cheltuiala& c);
    ~Cheltuiala();
    int getNrAp() const;
    int getSuma() const;
    char* getType();
    void setNrAp(int nrAp);
    void setSuma(int sum);
    void setType(char* tip);
    Cheltuiala& operator=(const Cheltuiala& c);
    bool operator==(const Cheltuiala& c);
    bool operator!=(const Cheltuiala& c);
    friend ostream& operator<<(ostream& os, const Cheltuiala&c);
};
