//
// Created by Alexe Andra on 12.04.2023.
//

#ifndef LAB_7_8_SERVICE_H
#define LAB_7_8_SERVICE_H
#include "repository.h"
class Service{
private:
    Repository repository;
public:
    Service();
    Service(Repository& r);
    ~Service();
    int size();
    Tranzactie getByPosition(int poz);
    void addTranzactie(int zi, int suma, char* tip, char* descriere);
    void updateTranzactie(int ziVeche, int ziNoua, int sumaVeche, int sumaNoua, char* tipVechi, char* tipNou, char* descriereVeche, char* descriereNoua);
    void remove(int zi, int suma, char* tip, char* descriere);
    int search(int zi, int suma, char* tip, char* descriere);
    Tranzactie* getAllTransactions();
};
#endif //LAB_7_8_SERVICE_H
