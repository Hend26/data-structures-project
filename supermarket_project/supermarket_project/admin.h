#pragma once
#include<string>
#include<map>
#include"seller.h"
#include<windows.h>

using namespace std;

class admin : public seller
{
public:
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    struct usernam {

        usernam() :
            password(),username(), address(),  phone_number(), user_id(){}
        usernam(string password,string username, string address,  string phonenumber,int user_id) :
            password(password),username(username), address(address), phone_number(phonenumber),user_id(user_id) {}

        string username, password, phone_number, address;
        int user_id;

    };

public:
    map<string, usernam >users;
    string username, email, password, phone_number, address;
    int  user_id;
public:
    admin();
    void file_fetch();
    void welcomeAdmin();
    //void add_user();
    void delete_user();
    void modify_user();
    void display_users();
    bool search_user(string email);
    void update_user();
    void add_product();
    void modify_product();
    void delete_product();
    void display_products();
    bool searchAllproducts(string seller_name, string name);
    ~admin();
};