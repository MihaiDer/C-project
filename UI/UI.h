#include "../Service/Service.h"

class UI {
private:
    Service service;
    void printListCheltuieli();
    void printMenu();
    void printDelete();
    void listCheltuieli();
    void addCheltuiala();
    void deleteCheltuialaNrAp();
    void deleteCheltuialaIntervalAp();
    void deleteCheltuialaType();
    void printCheltuieliNrAp();
    void printCheltuieliSum();
    void modifyCheltuiala();
    void printCheltuieli();
    void printGetSumType();
    void printCheltuialaMax();
    void printSortCheltuieli();
    void filterByType();
    void filterBySum();
    void Undo();
public:
    UI();
    UI(Service& s);
    void run();
};

