#include "Repo.h"
#include "../Domain/Cheltuiala.h"
#include <algorithm>

void RepoVector::addCheltuiala(Cheltuiala& cheltuiala) {
    this->cheltuieli.push_back(cheltuiala);
}

Cheltuiala RepoVector::getCheltuialaAtPosition(int pos) {
    return this->cheltuieli.at(pos);
}

vector<Cheltuiala> RepoVector::getAll() {
    return this->cheltuieli;
}

int RepoVector::size() {
    return this->cheltuieli.size();
}

void RepoVector::stergeCheltuialaNrAp(int nrAp) {
    vector<Cheltuiala>::iterator it;
    it = cheltuieli.begin();
    while(it != cheltuieli.end()){
        if(it->getNrAp() == nrAp)
            cheltuieli.erase(it);
        else
            it++;
    }
}

void RepoVector::stergeCheltuialaIntervalAp(int nrAp1, int nrAp2) {
    vector<Cheltuiala>::iterator it;
    if(nrAp2 < nrAp1){
        swap(nrAp1, nrAp2);
    }
    it = cheltuieli.begin();
    while(it != cheltuieli.end()){
        if(it->getNrAp() >= nrAp1 && it->getNrAp() <= nrAp2)
            cheltuieli.erase(it);
        else
            it++;
    }
}

void RepoVector::stergeCheltuialaTip(char *type) {
    vector<Cheltuiala>::iterator it;
    it = cheltuieli.begin();
    while(it != cheltuieli.end()){
        if(strcmp(it->getType(), type) == 0)
            cheltuieli.erase(it);
        else
            it++;
    }
}

int RepoVector::find(Cheltuiala &c) {
    vector<Cheltuiala>::iterator it;
    it = std::find(cheltuieli.begin(), cheltuieli.end(), c);
    if (it != cheltuieli.end())
        return (it - cheltuieli.begin());
}

void RepoVector::updateCheltuiala(Cheltuiala &c1, Cheltuiala &c2) {
    int pozitie = find(c1);
    if(pozitie >= 0)
        cheltuieli[pozitie] = c2;
}

RepoVector::RepoVector(vector<Cheltuiala> list) {
    this->cheltuieli = list;
}
