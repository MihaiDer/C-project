#include "UI.h"

UI::UI() = default;

UI::UI(Service& s) {
    this->service = s;
}

void UI::printMenu() {
    cout<<"1.Adauga cheltuiala"<<"\n";
    cout<<"2.Sterge sau modifica cheltuiala"<<"\n";
    cout<<"3.Afiseaza cheltuieli"<<"\n";
    cout<<"4.Afiseaza suma totala a cheltuielilor dupa tip"<<"\n";
    cout<<"5.Afiseaza cheltuiala maxima pentru un apartament"<<"\n";
    cout<<"6.Sorteaza cheltuieli in ordine descrescatoare dupa tip"<<"\n";
    cout<<"7.Filtreaza cheltuieli dupa tip"<<"\n";
    cout<<"8.Filtreaza cheltuieli dupa o anumita suma"<<"\n";
    cout<<"9.Undo"<<"\n";
    cout<<"10.Exit"<<"\n";
}

void UI::listCheltuieli() {
    cout<<"1.Afiseaza toate cheltuielile"<<"\n";
    cout<<"2.Afiseaza cheltuielile unui apartament"<<"\n";
    cout<<"3.Afiseaza cheltuielile dupa o suma"<<"\n";
    cout<<"Alegeti modul in care doriti sa afisati cheltuielile:";
}

void UI::printListCheltuieli() {
    listCheltuieli();
    int opt;
    cin>>opt;
    if(opt == 1)
        printCheltuieli();
    if(opt == 2)
        printCheltuieliNrAp();
    if(opt == 3)
        printCheltuieliSum();
}

void UI::printDelete() {
    int opt = 0;
    cout<<"1)Stergeti toate cheltuielile unui apartament"<<"\n";
    cout<<"2)Stergeti toate cheltuielile apartamentelor"<<"\n";
    cout<<"3)Stergeti toate cheltuielile dupa tip"<<"\n";
    cout<<"4)Modifica o cheltuiala dupa numarul apartamentului"<<"\n";
    cout<<"Alegeti modul in care doriti sa stergeti/modificati:";
    cin>>opt;
    if(opt == 1){
        deleteCheltuialaNrAp();
    }
    if(opt == 2){
        deleteCheltuialaIntervalAp();
    }
    if(opt == 3){
        deleteCheltuialaType();
    }
    if(opt == 4){
        modifyCheltuiala();
    }
}

void UI::addCheltuiala() {
    int nrAp, sum;
    char type[50];
    cout<<"Dati numarul apartamentului:";
    cin>>nrAp;
    cout<<"Dati suma:";
    cin>>sum;
    cout<<"Dati tipul:";
    cin>>type;
    this->service.addCheltuiala(nrAp, sum, type);
}

void UI::deleteCheltuialaNrAp() {
    int nrAp;
    cout<<"Dati numarul apartamentului pe care doriti sa-l stergeti:";
    cin>>nrAp;
    service.stergeCheltuialaNrAp(nrAp);
}

void UI::printCheltuieli() {
    vector <Cheltuiala> cheltuieli = this->service.getAll();
    for(auto & i : cheltuieli){
        cout<<i;
    }
}

void UI::deleteCheltuialaIntervalAp() {
    int nrAp1, nrAp2;
    cout<<"Dati numarul apartamentului:";
    cin>>nrAp1;
    cout<<"Dati numarul apartamentului:";
    cin>>nrAp2;
    service.stergeCheltuialaIntervalAp(nrAp1, nrAp2);
}

void UI::deleteCheltuialaType() {
    char type[20];
    cout<<"Dati tipul:";
    cin>>type;
    service.stergeCheltuialaTip(type);
}

void UI::printCheltuieliNrAp() {
    int nrAp;
    cout<<"Dati numarul apartamentului:";
    cin>>nrAp;
    vector<Cheltuiala> cheltuieli = service.getCheltuieliAp(nrAp);
    for(const auto & i : cheltuieli){
        cout<<i;
    }
}

void UI::printCheltuieliSum() {
    int sum;
    cout<<"Dati suma dupa care doriti sa afisati:";
    cin>>sum;
    vector<Cheltuiala> chelt = service.getCheltuialaSuma(sum);
    for(int i = 0; i < chelt.size(); i++)
        cout<<i;
}

void UI::printGetSumType() {
    char type[20];
    cout<<"Dati tipul dupa care doriti sa calculati suma:";
    cin>>type;
    int rez;
    rez = service.sumType(type);
    cout<<"Suma cheltuielilor este:"<<rez<<"\n";
}

void UI::printCheltuialaMax() {
    int nrAp;
    cout<<"Dati numarul apartamentului pentru care doriti sa afisati cheltuiala maxima:";
    cin>>nrAp;
    Cheltuiala cheltMax = this->service.getCheltuialaMax(nrAp);
    cout<<cheltMax;
}

void UI::printSortCheltuieli() {
    char type[20];
    cout<<"Dati tipul dupa care doriti sa sortati:";
    cin>>type;
    vector<Cheltuiala> chelt =service.sorteazaCheltuieliTip(type);
    vector<Cheltuiala>::iterator it;
    it = chelt.begin();
    while(it != chelt.end()){
        cout<<*it;
        it++;
    }
}

void UI::filterByType() {
    char type[20];
    cout<<"Dati tipul dupa care doriti sa filtrati:";
    cin>>type;
    vector<Cheltuiala> chelt =service.filterByType(type);
    vector<Cheltuiala>::iterator it;
    it = chelt.begin();
    while(it != chelt.end()){
        cout<<*it;
        it++;
    }
}

void UI::filterBySum() {
    int sum;
    cout<<"Dati suma dupa care doriti sa filtrati:";
    cin>>sum;
    vector<Cheltuiala> chelt =service.filterBySum(sum);
    vector<Cheltuiala>::iterator it;
    it = chelt.begin();
    while(it != chelt.end()){
        cout<<*it;
        it++;
    }
}

void UI::modifyCheltuiala() {
    int nrAp, suma;
    char type[20];
    int suma1;
    cout<<"Dati numarul apartamentului la  care doriti sa modificati cheltuiala:";
    cin>>nrAp;
    cout<<"Dati suma:";
    cin>>suma;
    cout<<"Dati tipul:";
    cin>>type;
    cout<<"Dati noua suma:";
    cin>>suma1;
    service.updateCheltuiala(nrAp, suma, type, nrAp, suma1, type);
}

void UI::run() {
    int optiune = -1;
    while(optiune != 10){
        printMenu();
        cout<<"Alegeti optiunea dorita:";
        cin>>optiune;
        if(optiune == 1){
            this->addCheltuiala();
        }
        if(optiune == 2){
            this->printDelete();
        }
        if(optiune == 3){
            this->printListCheltuieli();
        }
        if(optiune == 4)
            this->printGetSumType();
        if(optiune == 5)
            this->printCheltuialaMax();
        if(optiune == 6)
            this->printSortCheltuieli();
        if(optiune == 7)
            this->filterByType();
        if(optiune == 8)
            this->filterBySum();
        if(optiune == 9)
            this->Undo();
    }
}

void UI::Undo() {
    service.Undo();
}
