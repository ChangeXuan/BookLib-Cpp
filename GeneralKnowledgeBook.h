//
// Created by Day on 2017/4/25.
//

#ifndef BOOKLIB_GENERALKNOWLEDGEBOOK_H
#define BOOKLIB_GENERALKNOWLEDGEBOOK_H

#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

class GeneralKnowledgeBooks: public Book {
private:
    string typeName;
public:

    GeneralKnowledgeBooks();
    ~GeneralKnowledgeBooks();
    enum bookType {NOVEL,MAGAZINE,THOUGHT};
    void setBookType(const int type);
    string &getBookType();
    void showGeneralKnowledgeBooks();
};

GeneralKnowledgeBooks::GeneralKnowledgeBooks() {

}

GeneralKnowledgeBooks::~GeneralKnowledgeBooks() {

}

void GeneralKnowledgeBooks::setBookType(const int type) {
    switch (type) {
        case 0:
            typeName = "Novel";
            break;
        case 1:
            typeName = "Magazine";
            break;
        case 2:
            typeName = "Thought";
            break;
    }
}

string &GeneralKnowledgeBooks::getBookType() {
    return typeName;
}

void GeneralKnowledgeBooks::showGeneralKnowledgeBooks() {

    string name = getName();
    int pages = getPages();
    float price = getPrice();

    cout << "type:" << typeName << endl;
    cout << "name:" << name << endl;
    cout << "pages:" << pages << endl;
    cout << "price:" << price << endl;
}

#endif //BOOKLIB_GENERALKNOWLEDGEBOOK_H
