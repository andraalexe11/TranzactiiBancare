//
// Created by Alexe Andra on 11.04.2023.
//

#ifndef LAB_7_8_TRANZACTIE_H
#define LAB_7_8_TRANZACTIE_H

class Tranzactie{
private:
    int zi;
    int suma;
    char* tip;
    char* descriere;
public:
    Tranzactie();
    Tranzactie(int zi, int suma,  char* tip,  char* descriere);
    Tranzactie(const Tranzactie& t);
    ~Tranzactie();
    Tranzactie& operator=(Tranzactie& t);
    bool operator==(Tranzactie& t);
    void setZi(int zi);
    void setSuma(int suma);
    void setTip( char* tip);
    void setDescriere( char* descriere);
    int getSuma();
    int getZi();
    char* getTip();
    char* getDescriere();
};

#endif //LAB_7_8_TRANZACTIE_H
