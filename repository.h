//
// Created by Alexe Andra on 11.04.2023.
//

#ifndef LAB_7_8_REPOSITORY_H
#define LAB_7_8_REPOSITORY_H
#include "tranzactie.h"
class Repository{
private:
    Tranzactie tranzactii[10];
    int size;
public:
    Repository();
    Repository(Tranzactie tran[], int s );
    ~Repository();
    int getSize() const;
    Tranzactie getTranzactie(int poz);
    void add(Tranzactie t);
    void update(Tranzactie tVeche, Tranzactie tNoua );
    void remove(Tranzactie t);
    int search(Tranzactie t);
    Tranzactie* getAll();


};
#endif //LAB_7_8_REPOSITORY_H
