#pragma once
#include<string>
#include<map>
#include <fstream>
#include <utility>
#include<windows.h>

using namespace std;

struct productData {
    productData() :
        category(), id(0), qty(), price() {}//it's better to take data with constructor
    productData(string pcategory, int pid, int pqty, double pprice) :
        category(pcategory), id(pid), qty(pqty), price(pprice) {}
    string category;
    int id, qty;
    double price;
};
class seller
{
public:
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //buyer name , product name ,category pid quantity , price
    map<pair<string, string>, productData>file_data;// current seller products
    map<pair<string, string>, productData>all_data;// all products(for modify and delete functions)
    string seller_name;
    string name;
    string category;
    int pid;
    int quantity;
    double price;
public:
    seller(string sname);
    void file_fetch(string sname);
    void welcome();
    void addproduct();
    void removeproduct();
    void modifyproduct();
    void displayproduct();
    bool searchproduct(string n);
    void updateFile();
    void fileData();
    ~seller();
};