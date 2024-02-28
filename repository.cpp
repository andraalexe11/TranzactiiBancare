//
// Created by Alexe Andra on 11.04.2023.
//
#include "repository.h"

Repository::Repository() {
    this -> size = 0;
}

int Repository::getSize() const{
    return this->size;
}

Tranzactie Repository::getTranzactie(int poz) {
    return this -> tranzactii[poz];
}

Repository::~Repository() {

}

void Repository::add(Tranzactie t) {
    this -> tranzactii[this -> size] = t;
    this -> size ++;
}

void Repository::update(Tranzactie tVeche, Tranzactie tNoua) {
    int i = search(tVeche);
    this -> tranzactii[i] = tNoua;
}

void Repository::remove(Tranzactie t) {
    int i = search(t);
    for(int j = i; j < this -> size - 1; j ++){
        this -> tranzactii [j] = this -> tranzactii [j + 1];
    }
    this -> size --;
}

int Repository::search(Tranzactie t) {
    for(int i = 0; i < size; i++){
        if(this -> tranzactii[i] == t) return i;
    }
    return -1;
}

Tranzactie *Repository::getAll() {
    return this -> tranzactii;
}
