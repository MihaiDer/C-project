#include <vector>
#include "../Domain/Cheltuiala.h"
#pragma once

using namespace std;
class RepoVector {
private:
    vector<Cheltuiala> cheltuieli;

public:
    RepoVector() = default;
    RepoVector(vector<Cheltuiala> list);
    ~RepoVector() = default;
    void addCheltuiala(Cheltuiala& c);
    void stergeCheltuialaNrAp(int nrAp);
    void stergeCheltuialaIntervalAp(int nrAp1, int nrAp2);
    void stergeCheltuialaTip(char* type);
    void updateCheltuiala(Cheltuiala& c1, Cheltuiala& c2);
    int find(Cheltuiala& c);
    Cheltuiala getCheltuialaAtPosition(int pos);
    vector<Cheltuiala> getAll();
    int size();
};
