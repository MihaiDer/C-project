#include "Service.h"
#include <algorithm>

void Service::addCheltuiala(int nrAp, int sum, char *type) {
    this->undo.undo_add(repo.getAll());
    Cheltuiala cheltuiala(nrAp, sum, type);
    this->repo.addCheltuiala(cheltuiala);
}

vector<Cheltuiala> Service::getAll() {
    return repo.getAll();
}

Service::Service(RepoVector &repoVector, Undorepo & undo) {
    this->repo = repoVector;
    this->undo = undo;
}

int Service::size() {
    return this->repo.size();
}

void Service::stergeCheltuialaNrAp(int nrAp) {
    this->undo.undo_add(repo.getAll());
    this->repo.stergeCheltuialaNrAp(nrAp);
}

void Service::stergeCheltuialaIntervalAp(int nrAp1, int nrAp2) {
    this->undo.undo_add(repo.getAll());
    this->repo.stergeCheltuialaIntervalAp(nrAp1, nrAp2);
}

void Service::stergeCheltuialaTip(char *type) {
    this->undo.undo_add(repo.getAll());

    this->repo.stergeCheltuialaTip(type);
}

vector<Cheltuiala> Service::getCheltuieliAp(int nrAp) {
    vector<Cheltuiala> toateCheltuielile = repo.getAll();
    vector<Cheltuiala> cheltuieliNrAp;
    for(int i = 0; i < repo.size(); i++){
        if(toateCheltuielile[i].getNrAp() == nrAp)
            cheltuieliNrAp.push_back(toateCheltuielile[i]);
    }
    return cheltuieliNrAp;
}

vector<Cheltuiala> Service::getCheltuialaSuma(int sum) {
    vector<Cheltuiala> toateCheltuielile = repo.getAll();
    vector<Cheltuiala> cheltuieliSum;
    for(int i = 0; i < repo.size(); i++){
        if(toateCheltuielile[i].getSuma() == sum)
            cheltuieliSum.push_back(toateCheltuielile[i]);
    }
    return cheltuieliSum;
}

int Service::sumType(char* type) {
    int sum = 0;
    vector<Cheltuiala> cheltuieli = repo.getAll();
    vector<Cheltuiala> cheltuieliType;
    for(int i = 0; i < cheltuieli.size(); i++){
        if(strcmp(cheltuieli[i].getType(), type) == 0)
            cheltuieliType.push_back(cheltuieli[i]);
    }
    for(int i = 0; i < cheltuieliType.size(); i++)
        sum += cheltuieliType[i].getSuma();
    return sum;
}

Cheltuiala Service::getCheltuialaMax(int nrAp) {
    Cheltuiala cheltuialaMax;
    int max = -100000;
    vector<Cheltuiala>cheltuieli = repo.getAll();
    vector<Cheltuiala>cheltNrAp;
    for(int i = 0; i < cheltuieli.size(); i++){
        if(cheltuieli[i].getNrAp() == nrAp)
            cheltNrAp.push_back(cheltuieli[i]);
    }
    for(int i = 0; i < cheltNrAp.size(); i++){
        if(cheltNrAp[i].getSuma() > max){
            max = cheltNrAp[i].getSuma();
            cheltuialaMax = cheltNrAp[i];
        }
    }
    return cheltuialaMax;
}

bool comp(Cheltuiala& c1, Cheltuiala& c2){
    return c1.getSuma() > c2.getSuma();
}

vector<Cheltuiala> Service::sorteazaCheltuieliTip(char *type) {
    vector<Cheltuiala> cheltuieliType = filterByType(type);
    std::sort(cheltuieliType.begin(), cheltuieliType.end(), comp);
    return cheltuieliType;
}

vector<Cheltuiala> Service::filterByType(char *type) {
    vector<Cheltuiala> cheltuieli = repo.getAll();
    vector<Cheltuiala> cheltuieliType;
    for(int i = 0; i < cheltuieli.size(); i++){
        if(strcmp(cheltuieli[i].getType(), type) == 0)
            cheltuieliType.push_back(cheltuieli[i]);
    }
    return cheltuieliType;
}

vector<Cheltuiala> Service::filterBySum(int sum) {
    vector<Cheltuiala> cheltuieli = repo.getAll();
    vector<Cheltuiala> cheltuieliSum;
    for(int i = 0; i < cheltuieli.size(); i++){
        if(cheltuieli[i].getSuma() < sum)
            cheltuieliSum.push_back(cheltuieli[i]);
    }
    return cheltuieliSum;
}

void Service::updateCheltuiala(int nrAp, int sum, char *type, int nrAp1, int sum1, char *type1) {
    this->undo.undo_add(repo.getAll());
    Cheltuiala c1(nrAp, sum, type);
    Cheltuiala c2(nrAp1, sum1, type1);
    this->repo.updateCheltuiala(c1, c2);
}

void Service::Undo() {
    this->repo = undo.last_elem();
    undo.undo_delete();
}

Service::~Service() = default;

Service::Service() = default;


