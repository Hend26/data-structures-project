#pragma once
#include<string>
#include<map>
#include<queue>
#include<windows.h>
using namespace std;


class buyer
{
public:
	//seller name , product name ,category , ptoduct id, quantity, price 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	map< pair<string, pair<int, string>>, pair<double, pair<string, int> > >products; 
	pair<string, pair<int,string>>cartcomp;
	map< pair<string, pair<int, string>>, int>cartcheck;
	map< pair<string, pair<int, string>>, pair<double, pair<string, int> > > cart;
	map< pair<string, pair<int, string>>, pair<double, pair<string, int> > > temp;
	map<int, pair< int, int>> check;
	map<int, int> items_added;
	map<int, int> remove;
	queue<int> q;
	queue<string>s;
	map<string, int> saveword;
	string category;
	string seller_name;
	string name;
	string username;
	string logineduser;
	int id;
	int quantity;
	double price;
	double totalprice;
public:
	buyer(string);
	void clear();
	void productcheck();
	void file_edit();
	void cart_map();
	void cart_edit();
	void product_category();//Maram
	void display_search(); //Maram
	void file_fetch(); // Sara
	void buy_product();//Sara
	void pay();//Maram
	void add_to_cart();//Sara
	void remove_from_cart();//Sara
	void displaycart(); //Maram
	~buyer();
};