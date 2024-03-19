#include "../Repository/Undorepo.h"
#include "../Repository/Repo.h"
#pragma once
class Service {
private:
    RepoVector repo;
    Undorepo undo;
public:
    Service();
    Service(RepoVector& repoVector, Undorepo& undo);
    void addCheltuiala(int nrAp, int sum, char* type);
    void updateCheltuiala(int nrAp, int sum, char* type, int nrAp1, int sum1, char* type1);
    vector<Cheltuiala> getCheltuieliAp(int nrAp);
    vector<Cheltuiala> getCheltuialaSuma(int sum);
    void stergeCheltuialaNrAp(int nrAp);
    void stergeCheltuialaIntervalAp(int nrAp1, int nrAp2);
    void stergeCheltuialaTip(char* type);
    void Undo();
    int sumType(char* type);
    Cheltuiala getCheltuialaMax(int nrAp);
    vector<Cheltuiala> sorteazaCheltuieliTip(char* type);
    vector<Cheltuiala> filterByType(char* type);
    vector<Cheltuiala> filterBySum(int sum);
    int size();
    vector<Cheltuiala> getAll();
    ~Service();
};

