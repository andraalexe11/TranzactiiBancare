
#include "tranzactie.h"
#include <cstring>
#include <string.h>

Tranzactie::Tranzactie() {
    this -> suma = 0;
    this -> zi = 1;
    this -> tip = new char[5]();
    this -> descriere = new char [20]();
}

Tranzactie::Tranzactie(int zi, int suma, char* tip,  char *descriere) {
    this -> suma = suma;
    this -> zi = zi;
    this -> tip = new char [strlen(tip) + 1];
    strcpy(this -> tip, tip);
    this -> descriere = new char [strlen(descriere) + 1];
    strcpy(this -> descriere, descriere);
}

Tranzactie::Tranzactie(const Tranzactie &t) {
    this -> suma = t.suma;
    this -> zi = t.zi;
    this -> tip = new char [strlen(t.tip) + 1];
    strcpy(this -> tip, t.tip);
    this -> descriere = new char [strlen(t.descriere) + 1];
    strcpy(this -> descriere, t.descriere);
}

Tranzactie::~Tranzactie() {

}

Tranzactie &Tranzactie::operator=( Tranzactie &t) {
    this->suma = t.suma;
    this->zi = t.zi;
    delete[] this->tip;
    this->tip = new char[5];
    strcpy(this->tip, t.tip);
    delete[] this->descriere;
    this->descriere = new char[20];
    strcpy(this->descriere, t.descriere);
    return *this;
}

bool Tranzactie::operator==(Tranzactie &t) {
    if(this -> zi == t.zi && this -> suma == t.suma && strcmp(this -> tip, t.tip) == 0 && strcmp(this -> descriere, t.descriere)==0)
        return true;
    return false;
}

void Tranzactie::setZi(int zi) {
    this -> zi = zi;
}

void Tranzactie::setSuma(int suma) {
    this -> suma = suma;
}

void Tranzactie::setTip( char* tip) {
    this -> tip = new char [strlen(tip) + 1];
    strcpy(this -> tip, tip);
}

void Tranzactie::setDescriere(char *descriere) {
    this -> descriere = new char [strlen(descriere) + 1];
    strcpy(this -> descriere, descriere);
}

int Tranzactie::getSuma() {
    return this -> suma;
}

int Tranzactie::getZi() {
    return this -> zi;
}

char* Tranzactie::getTip() {
    return this -> tip;
}
char *Tranzactie::getDescriere() {
    return this -> descriere;
}
