#include <cassert>
#include "../Domain/Cheltuiala.h"
#include "../Repository/Repo.h"
#include "../Service/Service.h"
#include "Tests.h"
#include "../Repository/Undorepo.h"

using namespace std;

void Tests::testAll() {
    testCheltuiala();
    testCheltuialaRepo();
    testCheltuialaService();
    testListCheltuieliNrApAndSumService();
    testCheltuialaMax();
    testSorteazaDupaTip();
    testFilterByType();
    testServiceModify();
    testServiceUndo();
}

void Tests::testCheltuiala() {
    Cheltuiala c1;
    Cheltuiala c2(10, 25, "apa");
    Cheltuiala c3 = c2;
    c3.setSuma(19);
    c3.setNrAp(15);
    assert(strcmp(c3.getType(), "apa") == 0);
    assert(c3.getSuma() == 19);
    assert(c3.getNrAp() == 15);
    Cheltuiala c4(19, 15, "gaz");
    assert(c3 != c4);
}

void Tests::testCheltuialaRepo() {
    testCheltuialaRepoAdd();
    testCheltuialaRepoDeleteAp();
    testCheltuialaRepoDeleteIntervalAp();
    testCheltuialaRepoDeleteType();
    testCheltuialaRepoModify();
    testTypeSum();
}


void Tests::testCheltuialaService() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 25, "apa");
    service.addCheltuiala(15, 32, "gaz");
    service.addCheltuiala(8, 19, "electricitate");
    service.addCheltuiala(8, 19, "electricitate");
    assert(service.size() == 4);
    service.stergeCheltuialaNrAp(8);
    assert(service.size() == 2);
    service.addCheltuiala(13, 125, "curent");
    service.stergeCheltuialaIntervalAp(10, 15);
    assert(service.size() == 0);
    service.addCheltuiala(10, 25, "apa");
    service.addCheltuiala(15, 32, "gaz");
    service.addCheltuiala(8, 19, "electricitate");
    service.addCheltuiala(8, 19, "electricitate");
    service.stergeCheltuialaTip("electricitate");
    assert(service.size() == 2);
}


void Tests::testCheltuialaRepoAdd() {
    RepoVector repo;
    Cheltuiala c1(10, 25, "apa");
    Cheltuiala c2(15, 32, "gaz");
    Cheltuiala c3(13, 19, "electricitate");
    Cheltuiala c4(12, 19, "electricitate");
    Cheltuiala c5(12, 123, "gaz");
    Cheltuiala c6(16, 19, "electricitate");
    repo.addCheltuiala(c1);
    repo.addCheltuiala(c2);
    repo.addCheltuiala(c3);
    repo.addCheltuiala(c4);
    repo.addCheltuiala(c5);
    repo.addCheltuiala(c6);
    assert(repo.size() == 6);
    assert(repo.find(c5) == 4);
    assert(repo.find(c6) == 5);
    repo.updateCheltuiala(c1, c4);
    assert(repo.getCheltuialaAtPosition(0).getNrAp() == 12);
    assert(repo.getCheltuialaAtPosition(0).getSuma() == 19);
}

void Tests::testCheltuialaRepoDeleteAp() {
    RepoVector repo;
    Cheltuiala c1(10, 25, "apa");
    Cheltuiala c2(15, 32, "gaz");
    Cheltuiala c3(13, 19, "electricitate");
    Cheltuiala c4(12, 19, "electricitate");
    Cheltuiala c5(12, 123, "gaz");
    Cheltuiala c6(12, 123, "gaz");
    Cheltuiala c7(16, 19, "electricitate");
    repo.addCheltuiala(c1);
    repo.addCheltuiala(c2);
    repo.addCheltuiala(c3);
    repo.addCheltuiala(c4);
    repo.addCheltuiala(c5);
    repo.addCheltuiala(c6);
    repo.addCheltuiala(c7);
    repo.stergeCheltuialaNrAp(12);
    assert(repo.size() == 4);
}

void Tests::testCheltuialaRepoDeleteIntervalAp() {
    RepoVector repo;
    Cheltuiala c1(10, 25, "apa");
    Cheltuiala c2(15, 32, "gaz");
    Cheltuiala c3(13, 19, "electricitate");
    Cheltuiala c4(9, 12, "curent");
    repo.addCheltuiala(c1);
    repo.addCheltuiala(c2);
    repo.addCheltuiala(c3);
    repo.addCheltuiala(c4);
    repo.stergeCheltuialaIntervalAp(10, 15);
    assert(repo.size() == 1);
}

void Tests::testCheltuialaRepoDeleteType() {
    RepoVector repo;
    Cheltuiala c1(10, 25, "apa");
    Cheltuiala c2(15, 32, "gaz");
    Cheltuiala c3(13, 19, "electricitate");
    Cheltuiala c4(12, 19, "electricitate");
    Cheltuiala c5(12, 123, "gaz");
    Cheltuiala c6(12, 123, "gaz");
    Cheltuiala c7(16, 19, "electricitate");
    repo.addCheltuiala(c1);
    repo.addCheltuiala(c2);
    repo.addCheltuiala(c3);
    repo.addCheltuiala(c4);
    repo.addCheltuiala(c5);
    repo.addCheltuiala(c6);
    repo.addCheltuiala(c7);
    repo.stergeCheltuialaTip("electricitate");
    assert(repo.size() == 4);
}

void Tests::testCheltuialaRepoModify() {
    RepoVector repo;
    Cheltuiala c1(10, 25, "apa");
    Cheltuiala c2(10, 32, "gaz");
    Cheltuiala c3(13, 19, "electricitate");
    Cheltuiala c4(15, 235, "curent");
    repo.addCheltuiala(c1);
    repo.addCheltuiala(c2);
    repo.addCheltuiala(c3);
}

void Tests::testListCheltuieliNrApAndSumService() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 25, "apa");
    service.addCheltuiala(15, 32, "gaz");
    service.addCheltuiala(8, 19, "electricitate");
    service.addCheltuiala(8, 25, "altele");
    service.addCheltuiala(8, 300, "curent");
    vector<Cheltuiala>cheltuieliAp = service.getCheltuieliAp(8);
    assert(cheltuieliAp.size() == 3);
    vector<Cheltuiala>cheltSum = service.getCheltuialaSuma(25);
    assert(cheltSum.size() == 2);
}

void Tests::testTypeSum() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 20, "gaz");
    service.addCheltuiala(15, 30, "gaz");
    service.addCheltuiala(8, 19, "apa");
    service.addCheltuiala(8, 450, "gaz");
    service.addCheltuiala(8, 300, "curent");
    assert(service.sumType("gaz") == 500);
}

void Tests::testCheltuialaMax() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 20, "gaz");
    service.addCheltuiala(15, 30, "gaz");
    service.addCheltuiala(15, 900, "gaz");
    service.addCheltuiala(8, 19, "apa");
    service.addCheltuiala(8, 450, "gaz");
    service.addCheltuiala(8, 300, "curent");
    assert(service.getCheltuialaMax(8).getSuma() == 450);
}

void Tests::testSorteazaDupaTip() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 20, "gaz");
    service.addCheltuiala(15, 30, "gaz");
    service.addCheltuiala(15, 900, "gaz");
    service.addCheltuiala(8, 19, "apa");
    service.addCheltuiala(8, 450, "gaz");
    service.addCheltuiala(8, 300, "curent");
    vector<Cheltuiala> chelt = service.sorteazaCheltuieliTip("gaz");
    assert(chelt.size() == 4);
}

void Tests::testFilterByType() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 20, "gaz");
    service.addCheltuiala(15, 30, "gaz");
    service.addCheltuiala(15, 900, "gaz");
    service.addCheltuiala(8, 19, "apa");
    service.addCheltuiala(8, 450, "gaz");
    service.addCheltuiala(8, 300, "curent");
    vector<Cheltuiala> chelt = service.filterByType("gaz");
    assert(chelt.size() == 4);
}

void Tests::testServiceModify() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 20, "gaz");
    service.addCheltuiala(15, 30, "gaz");
    service.updateCheltuiala(10, 20, "gaz", 10, 500, "gaz");
    vector<Cheltuiala> chelt = service.getAll();
    assert(chelt.begin()->getSuma() == 500);
}

void Tests::testServiceUndo() {
    RepoVector repo;
    Undorepo undo;
    Service service(repo, undo);
    service.addCheltuiala(10, 20, "gaz");
    service.addCheltuiala(15, 30, "gaz");
    service.Undo();
    assert(service.size() == 1);
    service.updateCheltuiala(10, 20, "gaz", 10, 500, "gaz");
}

