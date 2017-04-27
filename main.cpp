#include <iostream>
#include <fstream>
#include "AllBooks.h"
using namespace std;

void addNewBook(string &content,Book &newbook);
void showAlertStr();

int main() {


    string fname = "myBooks.csv";   //书库的名字
    ofstream fout(fname.c_str(),ios::out | ios::app);//追加模式
    if(!fout.is_open()) {   //判断文件是否打开
        cout << "error file" << endl;
    }

    TechnicalBook tb;   //技术书籍的类
    GeneralKnowledgeBooks gb;   //通识书记的类
    operationBook ob(fname);    //查看书库的类
    char *formatS;  //格式化的字符串
    char key;   //操作件
    string content; //输入的内容
    showAlertStr();
    while (cin >> key && key != 'q' && key != 'Q') {
        getline(cin,content);   //消除第一次的空行
        switch (key) {
            case 'p':
            case 'P':
                cout << "book all price: " ;
                ob.sumPriceBook();  //显示书库的总价格
                cout << " $" << endl;
                break;
            case 'f':
            case 'F':
                cout << "input type name:" ;
                getline(cin,content);   //输入需要查找的类型
                ob.showTargerBook(content); //显示
                break;
            case 't':
            case 'T':
                cout << "input skill name:" ;
                getline(cin,content);
                tb.setSkillName(content);
                addNewBook(content,tb);
                sprintf(formatS,"%s,name:%s,pages:%d,price:%.2f",tb.getSkillName().c_str(),tb.getName().c_str(),tb.getPages(),tb.getPrice());
                fout << formatS << endl;
                break;
            case 'g':
            case 'G':
                cout << "input type (0:NOVEL,1:MAGAZINE,2:THOUGHT):" ;
                getline(cin,content);
                gb.setBookType(atoi(content.c_str()));
                addNewBook(content,gb);
                sprintf(formatS,"%s,name:%s,pages:%d,price:%.2f",gb.getBookType().c_str(),gb.getName().c_str(),gb.getPages(),gb.getPrice());
                fout << formatS << endl;
                break;
        }
        cout << "......wating..........ok........" << endl;
        showAlertStr();
    }
    fout.close();
    return 0;
}

void showAlertStr() {
    cout << "find book input 'f' or 'F'" << endl;
    cout << "add technicalBook input 't' or 'T'," << endl;
    cout << "add GeneralKnowledgeBook input 'g' or 'G'" << endl;
    cout << "quit input 'q' or 'Q'" << endl;
}

void addNewBook(string &content,Book &newBook) {
    cout << "input book name:";
    getline(cin,content);
    newBook.setName(content);
    cout << "input book pages:";
    getline(cin,content);
    newBook.setPages(atoi(content.c_str()));
    cout << "input book price:";
    getline(cin,content);
    newBook.setPrice(atof(content.c_str()));
    newBook.showBook();
}

