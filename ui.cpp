//
// Created by Alexe Andra on 19.04.2023.
//
#include "ui.h"
#include <iostream>
#include <cstring>
using namespace std;


void UI::add() {
    int suma, zi;
    char* tip = new char[5];
    char* descriere = new char[15];
    cout << "Dati ziua: "; cin >> zi;
    cout << endl << "Dati suma: "; cin >> suma;
    cin.ignore();
    cout << endl << "Dati tipul tranzactiei: "; cin.getline(tip, 15);
    cout << endl << "Dati descrierea tranzactiei: "; cin.getline(descriere, 20);
    this -> service.addTranzactie(zi, suma, tip, descriere);
    cout << endl << "Tranzactie adaugata!" << endl;
    delete[] tip;
    delete[] descriere;
}

void UI::getAll() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    if(this -> service.size() == 0){
        cout << "Lista de tranzactii este goala" << endl;
    }else {
        for (int i = 0; i < this->service.size(); i++) {
            cout << "Tranzactia " << i + 1 << ": ";
            cout << "Zi: " << tranzactii[i].getZi() << ", Suma: " << tranzactii[i].getSuma() << ", Tip: "
                 << tranzactii[i].getTip();
            cout << ", Descriere: " << tranzactii[i].getDescriere() << endl;
        }
    }
    
}

void UI::findSumOver() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    int s;
    cout << "Introduceti suma minima: ";
    cin >> s;
    for(int i = 0; i < l; i++){
        if(tranzactii[i].getSuma() > s) {
            cout << "Zi: " << tranzactii[i].getZi() << ", Suma:" << tranzactii[i] .getSuma() << ", Tip: " << tranzactii[i].getTip();
            cout << ", Descriere:" << tranzactii[i].getDescriere() << endl;
        }
    }


}

void UI::findSumEqualTo() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    int s;
    cout << "Introduceti suma cautata: ";
    cin >> s;
    for(int i = 0; i < l; i++){
        if(tranzactii[i].getSuma() == s) {
            cout << "Zi: " << tranzactii[i].getZi() << ", Suma:" << tranzactii[i] .getSuma() << ", Tip: " << tranzactii[i].getTip();
            cout << ", Descriere:" << tranzactii[i].getDescriere() << endl;
        }
    }


}


void UI::getSoldByDay() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    int z;
    cout << "Introduceti ziua cautata: ";
    cin >> z;
    int s = 0;
    for(int i = 0; i < l; i++){
        if(tranzactii[i].getZi() == z) {
            if(strcmp(tranzactii[i].getTip(), "in")== 0){
                s += tranzactii[i].getSuma();
            }else{
                s -= tranzactii[i].getSuma();
            }
        }
    }
    cout << endl << " Soldul din ziua " << z << " este de " << s <<  endl;
}

void UI::getTotalSumByType() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    cout << "Ce tip de tranzactii doriti sa vedeti?";
    cout << endl <<"1. Tranzactii de tip intrare" << endl << "2. Tranzactii de tip iesire" << endl;
    int c;
    cout << "Raspuns: ";
    cin >> c;
    const char* tip = new const char [5]();
    switch (c) {
        case 1:
            tip = "in";
            break;
        case 2:
            tip = "out";
            break;
        default:
            cout << "Optiunea nu este valida!";
            break;

    }
    int s = 0;
    for(int i = 0; i < l; i++){
        if(strcmp(tranzactii[i].getTip(), tip) == 0){
            s += tranzactii[i].getSuma();
        }
    }
    cout << endl << "Totalul tranzactiilor de acest tip este " << s << endl;
}

void UI::findBiggestTranByDay() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    int z;
    cout << "Introduceti ziua cautata: ";
    cin >> z;
    int p;
    int maxim = 0;
    for(int i = 0; i < l; i++){
        if(tranzactii[i].getZi() == z) {
            if(maxim < tranzactii[i].getSuma()){
                maxim = tranzactii[i].getSuma();
                p = i;
            }
        }
    }
    cout << "Cea mai mare tranzactie din ziua " << z << " este:" << endl;
    cout << "Suma:" << tranzactii[p] .getSuma() << ", Tip: " << tranzactii[p].getTip();
    cout << ", Descriere:" << tranzactii[p].getDescriere() << endl;
}

void UI::filterByType() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    cout << "Ce tip de tranzactii doriti sa vedeti?";
    cout << endl << "1. Tranzactii de tip intrare" << endl << "2. Tranzactii de tip iesire" << endl;
    int c;
    cout << "Raspuns: ";
    const char* tip = new const char [5]();
    cin >> c;
    switch (c) {
        case 1:
            tip = "in";
            break;
        case 2:
            tip = "out";
            break;
        default:
            cout << "Optiunea nu este valida!";
            break;

    }
    for(int i = 0; i < l; i++){
        if(strcmp(tranzactii[i].getTip(), tip) == 0) {
            cout << "Zi: " << tranzactii[i].getZi();
            cout << ", Suma:" << tranzactii[i] .getSuma() << ", Tip: " << tranzactii[i].getTip();
            cout << ", Descriere:" << tranzactii[i].getDescriere() << endl;
        }
    }
}

void UI::filterByTypeMaxAmount() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    cout << "Ce tip de tranzactii doriti sa vedeti?";
    cout << endl << "1. Tranzactii de tip intrare" << endl << "2. Tranzactii de tip iesire" << endl;
    int c;
    cout << "Raspuns: ";
    const char* tip = new const char [5]();
    cin >> c;
    switch (c) {
        case 1:
            tip = "in";
            break;
        case 2:
            tip = "out";
            break;
        default:
            cout << "Optiunea nu este valida!";
            break;

    }
    int m;
    cout << "Introduceti limita maxima: ";
    cin >> m;

    for(int i = 0; i < l; i++){
        if(strcmp(tranzactii[i].getTip(), tip) == 0 && tranzactii[i].getSuma() < m) {
            cout << "Zi: " << tranzactii[i].getZi();
            cout << ", Suma:" << tranzactii[i] .getSuma() << ", Tip: " << tranzactii[i].getTip();
            cout << ", Descriere:" << tranzactii[i].getDescriere() << endl;
        }
    }
}

void UI::removeFromDayToDay() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    int zin, zsf;
    cout << " Introduceti perioada: " << endl;
    cout << "Ziua de inceput: "; cin >> zin;
    cout << endl << "Ziua de sfarsit: "; cin >> zsf;
    for(int i = 0; i < l; i++){
        if(tranzactii[i].getZi() > zin && tranzactii[i].getZi() < zsf){
            this -> service.remove(tranzactii[i].getZi(), tranzactii[i].getSuma(), tranzactii[i].getTip(), tranzactii[i].getDescriere());
        }
    }
    cout << "Tranzactiile din aceasta perioada au fost eliminate cu succes!" << endl;
}

void UI::removeByDay() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    int zi;
    cout << " Introduceti ziua: " ; cin >> zi;
    cout << endl;
    for(int i = 0; i < l; i++){
        if(tranzactii[i].getZi() == zi){
            this -> service.remove(tranzactii[i].getZi(), tranzactii[i].getSuma(), tranzactii[i].getTip(), tranzactii[i].getDescriere());
        }
    }
    cout << "Tranzactiile din aceasta zi au fost eliminate cu succes!" << endl;
}

void UI::removeByType() {
    Tranzactie* tranzactii = this -> service.getAllTransactions();
    int l = this -> service.size();
    cout << "Ce tip de tranzactii doriti sa vedeti?";
    cout << endl << "1. Tranzactii de tip intrare" << endl << "2. Tranzactii de tip iesire" << endl;
    int c;
    cout << "Raspuns: ";
    cin >> c;
    const char* tip = new const char [5]();
    switch (c) {
        case 1:
            tip = "in";
            break;
        case 2:
            tip = "out";
            break;
        default:
            cout << "Optiunea nu este valida!";
            break;

    }
    for(int i = 0; i < l; i++){
        if(strcmp(tranzactii[i].getTip(), tip) == 0){
            this -> service.remove(tranzactii[i].getZi(), tranzactii[i].getSuma(), tranzactii[i].getTip(), tranzactii[i].getDescriere());
        }
    }
    cout << "Tranzactiile de acest tip au fost eliminate cu succes!" << endl;
}

UI::UI() {

}

UI::UI(Service &s) {
    this -> service  = s;
}

UI::~UI() {

}

void UI::printMenu() {
    bool value = true;
    int optiune;
    while (value) {
        cout << "Alegeti o optiune: " << endl;
        cout << "1. Adaugare tranzactie" << endl;
        cout << "2. Afiseaza toate tranzactiile" << endl;
        cout << "3. Afiseaza tranzactiile de un anumit tip" << endl;
        cout << "4. Afiseaza tranzactiile cu suma mai mare decat o suma data " << endl;
        cout << "5. Afiseaza tranzactiile cu suma egala cu o suma data" << endl;
        cout << "6. Afiseaza soldul dintr-o anumita zi" << endl;
        cout << "7. Afiseaza suma totala a tranzactiilor de un anumit tip" << endl;
        cout << "8. Afiseaza cea mai mare tranzactie dintr-o anumita zi" << endl;
        cout << "9. Filtreaza tranzactiile in functie de tip si de o suma maxima" << endl;
        cout << "10. Elimina tranzactiile dintr-o anumita perioada" << endl;
        cout << "11. Elimina tranzactiile de un anumit tip" << endl;
        cout << "12. Elimina tranzactiile dintr-o anumita zi" << endl;
        cout << "Dati optiunea : ";
        cin >> optiune;
        cout << endl;
        switch (optiune) {
            case 1:
                add();
                break;
            case 2:
                getAll();
                break;
            case 3:
                filterByType();
                break;
            case 4:
                findSumOver();
                break;
            case 5:
                findSumEqualTo();
                break;
            case 6:
                getSoldByDay();
                break;
            case 7:
                getTotalSumByType();
                break;
            case 8:
                findBiggestTranByDay();
                break;
            case 9:
                filterByTypeMaxAmount();
                break;
            case 10:
                removeFromDayToDay();
                break;
            case 11:
                removeByType();
                break;
            case 12:
                removeByDay();
                break;
            default:
                cout << "Optiune invalida";
                break;

        }
    }
}

