//
// Created by Day on 2017/4/25.
//

#ifndef BOOKLIB_TECHNICALBOOK_H
#define BOOKLIB_TECHNICALBOOK_H

#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

class TechnicalBook: public Book {
private:
    string skillName;
public:
    TechnicalBook();
    ~TechnicalBook();
    void setSkillName(const string &newName);
    string &getSkillName();
    void showTechnicalBook();

};

TechnicalBook::TechnicalBook() {

}

TechnicalBook::~TechnicalBook() {

}

void TechnicalBook::setSkillName(const string &newName) {
    skillName = newName;
}

string& TechnicalBook::getSkillName() {
    return skillName;
}

void TechnicalBook::showTechnicalBook() {
    string name = getName();
    int pages = getPages();
    float price = getPrice();

    cout << "skill:" << skillName << endl;
    cout << "name:" << name << endl;
    cout << "pages:" << pages << endl;
    cout << "price:" << price << endl;
}

#endif //BOOKLIB_TECHNICALBOOK_H
