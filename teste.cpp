//
// Created by Alexe Andra on 11.04.2023.
//
#include<string.h>
#include "teste.h"
#include "repository.h"
#include "tranzactie.h"
#include "assert.h"
#include <iostream>
using namespace std;
void testRepo(){
    Repository r1;
    assert(r1.getSize() == 0);
    Tranzactie t;
}
void testTranzactie(){
    Tranzactie t;
    assert(t.getSuma() == 0);
    assert(t.getDescriere() == nullptr);
    char *m = nullptr;
    m = new char[10];
    strcpy(m,"Plata");
    t.setDescriere(m);
    assert(strcmp(t.getDescriere(), m) == 0);

}