//
// Created by Alexe Andra on 12.04.2023.
//
#include "service.h"

Service::Service() {
}

Service::Service(Repository &r) {
    this -> repository = r;
}

Service::~Service() {

}

int Service::size() {
    return this -> repository.getSize();
}

Tranzactie Service::getByPosition(int poz) {
    return this -> repository.getTranzactie(poz);
}

void Service::addTranzactie(int zi, int suma,char* tip, char *descriere) {
    Tranzactie t(zi, suma, tip, descriere);
    repository.add(t);
}

void Service::updateTranzactie(int ziVeche, int ziNoua, int sumaVeche, int sumaNoua, char* tipVechi, char* tipNou,
                                char *descriereVeche,  char *descriereNoua) {
    Tranzactie tVeche(ziVeche, sumaVeche, tipVechi, descriereVeche);
    Tranzactie tNoua(ziNoua, sumaNoua, tipNou, descriereNoua);
    this -> repository.update(tVeche, tNoua);

}

void Service::remove(int zi, int suma, char* tip, char *descriere) {
    Tranzactie t(zi, suma, tip, descriere);
    this -> repository.remove(t);
}

int Service::search(int zi, int suma, char* tip, char *descriere) {
    Tranzactie t(zi, suma, tip, descriere);
    return this -> repository.search(t);
}

Tranzactie *Service::getAllTransactions() {
    return this -> repository.getAll();
}
