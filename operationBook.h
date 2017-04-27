//
// Created by Day on 2017/4/26.
//

#ifndef BOOKLIB_OPERATIONBOOK_H
#define BOOKLIB_OPERATIONBOOK_H
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class operationBook {
private:
    ifstream fin;
    string libName;
    void returnTitle() {
        fin.clear();
        fin.seekg(0);
    }
public:
    operationBook(const string &name);
    ~operationBook();
    void showTargerBook(const string &bookType);
    void sumPriceBook();


};

operationBook::operationBook(const string &name):libName(name) {
    fin.open(libName);
}

operationBook::~operationBook() {
    fin.close();
}

void operationBook::showTargerBook(const string &bookType) {
    if (fin.is_open()) {
        returnTitle();
        char ch;
        int flag = 0;
        string temp = "";
        int isEmpey = true;
        int keyLen = bookType.size();
        while(fin.get(ch)) {
            if (flag == keyLen) {
                if (temp == bookType && ch == ',') {
                    temp = "";
                    while(fin.get(ch) && ch != '\n') {
                        temp += ch;
                    }
                    isEmpey = false;
                    cout << temp << endl;
                }else {
                    while(fin.get(ch) && ch != '\n') {}
                }
                flag = 0;
                temp = "";
                fin.get(ch);
            }
            temp += ch;
            flag ++;
        }
        if (isEmpey) {
            cout << "No Need Books" << endl;
        }
    }
}

void operationBook::sumPriceBook() {
    if (fin.is_open()) {
        returnTitle();
        char ch;
        string listBook = "";
        float sum = 0.0;
        while (fin.get(ch)) {
            if (ch == '\n') {
                int len = listBook.size();
                string temp = "";
                for (int i = len - 1; i >= 0; i--) {
                    char item = listBook[i];
                    if (item == ':') {
                        break;
                    }
                    temp = listBook[i] + temp;
                }
                sum += atof(temp.c_str());
                listBook = "";
            } else {
                listBook += ch;
            }
        }
        cout << sum;
    }
}

#endif //BOOKLIB_OPERATIONBOOK_H
