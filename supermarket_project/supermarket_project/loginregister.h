#pragma once
#include<string>
#include<map>
#include<windows.h>
using namespace std;

class loginregister
{
public:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	map<string,pair<string,string>>file_data;
	map < string, bool>uniqueuser;
	map < string, bool>uniqueemail;

	string name;
	string useremail;
	string id;
	string address;
	string phone_number;
	string password;
public:
	loginregister();
	void choose_type();
	void file_fetch();
	string login();
	void loginadmin(string);
	void registery();
	~loginregister();
};

