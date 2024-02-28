//
// Created by Alexe Andra on 19.04.2023.
//

#ifndef LAB_7_8_UI_H
#define LAB_7_8_UI_H
#include "service.h"
class UI{
private:
    Service service;
    void add();
    void getAll();
    void findSumOver();
    void findSumEqualTo();
    void getSoldByDay();
    void getTotalSumByType();
    void findBiggestTranByDay();
    void filterByType();
    void filterByTypeMaxAmount();
    void removeFromDayToDay();
    void removeByDay();
    void removeByType();

public:
    UI();
    UI(Service& s);
    ~UI();
    void printMenu();


};
#endif //LAB_7_8_UI_H
