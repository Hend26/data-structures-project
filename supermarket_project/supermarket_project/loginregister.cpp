#include "loginregister.h"
#include<string>
#include<map>
#include<fstream>
#include<iostream>
#include<windows.h>

using namespace std;


loginregister::loginregister()
{
    file_fetch();
}

void loginregister::file_fetch()
{
    string tmpa, tmpb, tmpc;
    ifstream file("user.txt");

    while (file >> useremail >> password >>name>>tmpa>>tmpb>>tmpc)
    {
        file_data[useremail].first= password;
        file_data[useremail].second = name;
        uniqueuser[name] = 1;
        uniqueemail[useremail] = 1;

    }
}

//void loginregister::choose_type()
//{
//    int choice;
//    cout << "1.Seller" << endl;
//    cout << "2.Buyer" << endl;
//    cin >> choice;
//    cout << endl;
//    switch (choice) {
//    case 1:
//        type = "Seller";
//        break;
//    case 2:
//            type = "Buyer";
//            break;
//        default:
//            system("cls");
//            choose_type();
//    }
//    //give type variable a value by making him choose (1 seller , 2 buyer)
//}


void loginregister::registery()
{

    string reguser, regpass, address, phoneno,userna,id_user;
    system("cls");
    cout << "\t\t\t---register of new user---" << endl;

    SetConsoleTextAttribute(h, 2);
    cout << "Enter the email :";
    SetConsoleTextAttribute(h, 7);

    cin >> reguser;
    while (uniqueuser[userna] != 0)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\nusername is already in use please Enter another username :\n";
        SetConsoleTextAttribute(h, 7);
        cin >> reguser;
    }
    SetConsoleTextAttribute(h, 2);
    cout << "\nEnter the username :";
    SetConsoleTextAttribute(h, 7);
    cin >> userna;
    while (uniqueuser[userna] != 0)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\nusername is already in use please Enter another username :\n";
        SetConsoleTextAttribute(h, 7);
        cin >> userna;
    }
    SetConsoleTextAttribute(h, 4);
    cout << "\nEnter the password :";
    SetConsoleTextAttribute(h, 7);

    while (true)
    {
        bool hasLetter = false;
        bool hasDigit = false;
        bool length=false;
        cin >> regpass;

        if (regpass.size() > 8)
        {
            length = true;
        }

        for (int i = 0; i < regpass.size(); i++) {
            if (isdigit(regpass.at(i))) { hasDigit = true; }
            if (isalpha(regpass.at(i))) { hasLetter = true; }
        }
        if (!(hasLetter && hasDigit && length))
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\npassword shold contain letters and numbers and not less than 8 figures please try again :\n";
            SetConsoleTextAttribute(h, 7);
            continue;
        }
        else break;
       
       
    }
    SetConsoleTextAttribute(h, 2);
    cout << "\nEnter your country :";
    SetConsoleTextAttribute(h, 7);
    cin >> address;
    SetConsoleTextAttribute(h, 2);
    cout << "\nEnter the phone number :";
    SetConsoleTextAttribute(h, 7);
    cin >> phoneno;
    SetConsoleTextAttribute(h, 2);
    cout << "\nEnter the id :";
    SetConsoleTextAttribute(h, 7);
    cin >> id_user;
   

    ofstream reg("user.txt", ios::app);
    reg << reguser << ' ' << regpass << ' ' << userna << ' ' << address << ' '<<phoneno<< ' '<< id_user << endl;

    SetConsoleTextAttribute(h, 14);
    cout << "\nRegistration Sucessful\n";
    SetConsoleTextAttribute(h, 7);
    Sleep(1000);

    file_fetch();
    system("cls");

    //input info and add to user.txt username and pasword and user type
}

string loginregister::login()
{
    string user, pass, u, p,returnuser;
    system("cls");
    cout << "please enter the following details" << endl;
    SetConsoleTextAttribute(h, 2);
    cout << "email :";
    SetConsoleTextAttribute(h, 7);
    cin >> user;
    SetConsoleTextAttribute(h, 2);
    cout << "PASSWORD :";
    SetConsoleTextAttribute(h, 7);
    cin >> pass;

    
    if (file_data[user].first == pass)
    {
        returnuser = file_data[user].second;
        cout << "\nHello ";
        SetConsoleTextAttribute(h, 2);
        cout << file_data[user].second;
        SetConsoleTextAttribute(h, 14);
        cout<< "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        SetConsoleTextAttribute(h, 7);
        Sleep(1000);
        system("cls");
        
    }
    else
    {
        system("cls");
        SetConsoleTextAttribute(h, 4);
        cout << "\nLOGIN ERROR\nPlease check your username and password\nyou will be redirected to login page again.....";
        SetConsoleTextAttribute(h, 7);
        Sleep(1000);
        login();
        //input email and password check from map if user name is  right or not 
    }

    return returnuser;
}
void loginregister::loginadmin(string admin)
{
    string user, pass;
    user = admin;
    system("cls");
    SetConsoleTextAttribute(h, 2);
    cout << "hello admin :" << endl;
    cout << "PASSWORD :";
    SetConsoleTextAttribute(h, 7);
    cin >> pass;


    if (file_data[user].first == pass)
    {
        cout << "\nHello ";
        SetConsoleTextAttribute(h, 2);
        cout<< file_data[user].second << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        SetConsoleTextAttribute(h, 7);
        Sleep(1000);
        system("cls");

    }
    else
    {
        system("cls");
        SetConsoleTextAttribute(h, 4);
        cout << "\nLOGIN ERROR\nPlease check your username and password\nyou will be redirected to login page again.....";
        SetConsoleTextAttribute(h, 7);
        Sleep(1000);
        loginadmin("admin@gmail.com");
        //input email and password check from map if user name is  right or not 
    }

}


    loginregister::~loginregister() {}