//
// Created by Day on 2017/4/25.
//

#ifndef BOOKLIB_BOOK_H
#define BOOKLIB_BOOK_H
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    string name;
    float price;
    int pages;
public:
    Book();
    virtual ~Book();
    string getName();
    float getPrice();
    int getPages();
    void setName(const string &newName);
    void setPrice(const float &newPrice);
    void setPages(const int &newPages);
    void showBook();
};

Book::Book() {

}

Book::~Book() {

}

string Book::getName() {
    return name;
}

float Book::getPrice() {
    return price;
}

int Book::getPages() {
    return pages;
}

void Book::setName(const string &newName) {
    name = newName;
}

void Book::setPrice(const float &newPrice) {
    price = newPrice;
}

void Book::setPages(const int &newPages) {
    pages = newPages;
}

void Book::showBook() {
    cout << "name:" << name << endl;
    cout << "pages:" << pages << endl;
    cout << "price:" << price << endl;
}

#endif //BOOKLIB_BOOK_H
