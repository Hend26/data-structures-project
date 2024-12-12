#include "buyer.h"
#include<string>
#include<fstream>
#include<map>
#include<iostream>
#include<windows.h>

using namespace std;

buyer::buyer(string name)
{
	logineduser = name;
	cart_map();
	file_fetch();
	productcheck();
}

void buyer::productcheck()
{
	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator prod = cart.begin();
	for (; prod != cart.end(); prod++)
	{
		cartcheck[{prod->first.first, { prod->first.second.first, prod->first.second.second }}] = prod->second.second.second;
		remove.insert({ prod->first.second.first , cartcheck[{prod->first.first, { prod->first.second.first, prod->first.second.second }}] });
	}
}

void buyer::file_fetch()
{
	//seller name ,id , product name ,category , ptoduct id, quantity, price 
	//fetch all saved data to map (products)
	ifstream thefile("products.txt");
	
	while (thefile >> seller_name >> name >> category >> id >> quantity >> price)
	{
	
		products.insert({ {seller_name , {id,name}  }  ,  { price  ,  { category , quantity }  } });
		//seller_name: first.first
		//id : first.second.first
		//name : first.second.second
		//price : second.first
		//category : second.second.first
		// quantity : second.second.second
	}
	thefile.close();
}

void buyer::file_edit()
{
	fstream product("products.txt", ios::out );
	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator prod = products.begin();
	for (; prod != products.end(); prod++)
	{
		//seller_name: first.first
		//id : first.second.first
		//name : first.second.second
		//price : second.first
		//category : second.second.first
		// quantity : second.second.second
		// 
		// 
		//seller name ,id , product name ,category ,  quantity, price 
		product << prod->first.first << " " << prod->first.second.second << " " << prod->second.second.first << " " << prod->first.second.first << " " << prod->second.second.second << " " << prod->second.first << endl;
	}
	product.close();
}

void buyer::cart_edit()
{
	fstream product("cart.txt", ios::out );
	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator prod = cart.begin();
	for (; prod != cart.end(); prod++)
	{
		product << prod->first.first << " " << prod->first.second.second << " " << prod->second.second.first << " " << prod->first.second.first << " " << cartcheck[{prod->first.first, { prod->first.second.first, prod->first.second.second }}] << " " << prod->second.first << endl;
	}
	product.close();
}

void buyer::cart_map()
{
	ifstream thefile("cart.txt");
	cart.clear();
	while (thefile >> seller_name >> name >> category >> id >> quantity >> price)
	{
		
		cart.insert({ {seller_name , {id,name}  }  ,  { price  ,  { category , quantity }  } });
		remove.insert({ id , quantity });
	}
	thefile.close();
}

void buyer::clear()
{
	fstream ofs;
	ofs.open("cart.txt", ios::out | ios::trunc);
	ofs << "";
	ofs.close();
}

void buyer::remove_from_cart()
{
	//input what product user want to remove from cart and remove it from file (cart)
	int i = 1;
	int ch;
	fstream cartt("cart.txt", ios::in | ios::app);

	while (!cartt.eof())
	{
		string line;
		getline(cartt, line);

		if (line == "")break;
		cout << i << ") " << line << endl;
		q.push(i);
		s.push(line);
		i++;
	}
	cartt.close();
	clear();
	if (cart.empty())
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\t\t your cart is empty " << endl;
		SetConsoleTextAttribute(h, 7);
	}
	else
	{
		ofstream file("cart.txt");
		SetConsoleTextAttribute(h, 2);
		cout << "Enter the number of product you want to remove : ";
		SetConsoleTextAttribute(h, 7);
		cin >> ch; cout << endl;
		cartt >> seller_name >> name >> category >> id >> quantity >> price;
		while (!q.empty())
		{
			if (ch != q.front())
			{
				file << s.front() << endl;
			}
			else
			{
			}
			q.pop();
			s.pop();
		}
		file.close();
		map<int, int > ::iterator it = remove.begin();
		map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator prod;
		for (; it != remove.end(); it++)
		{
			for (prod = products.begin(); prod != products.end(); prod++)
			{
				if (it->first == prod->first.second.first)
				{
					prod->second.second.second += it->second;
					break;
				}
			}
		}
		file_edit();
		cart_map();
		SetConsoleTextAttribute(h, 2);
		cout << "Product removed successfully" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

void buyer::buy_product()
{
	//display make buyer choose which product he want and quantity
m:
	file_fetch();
	int choice;
	int pn;
	int qu;
	cout << "\t_____________________________________________________________________\n";
	cout << "\t\t\t\t LIST OF PRODUCT : \n";
	cout << "\t______________________________________________________________________\n";
	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator it = products.begin();

	int i = 1;
	for (; it != products.end(); it++)
	{
		SetConsoleTextAttribute(h, 14);
		cout << "| " << i << ") " << " Name : ";
		SetConsoleTextAttribute(h, 7);
		cout << it->first.second.second;
		SetConsoleTextAttribute(h, 14);
		cout << " | " << "Price: ";
		SetConsoleTextAttribute(h, 7);
		cout << it->second.first;
		SetConsoleTextAttribute(h, 14);
		cout << " | " << "Quantity: ";
		SetConsoleTextAttribute(h, 7);
		cout << it->second.second.second;
		SetConsoleTextAttribute(h, 14);
		cout << " | " << "Category: ";
		SetConsoleTextAttribute(h, 7);
		cout << it->second.second.first;
		SetConsoleTextAttribute(h, 14);
		cout << " | " << "Product Id : ";
		SetConsoleTextAttribute(h, 7);
		cout<< it->first.second.first;
		cout << endl;
		//takes the number of product , id and quantity
		// the number of product -> i
		//id -> first.second.first
		//quantity ->second.second.second
		check.insert({ i,{ it->first.second.first,it->second.second.second } });
		i++;
	}
k:
	SetConsoleTextAttribute(h, 2);
	cout << "Product Number : ";
	SetConsoleTextAttribute(h, 7);
	cin >> pn;
	cout << endl;
	if (pn > i || pn == 0)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "Invalid choice " << endl;
		SetConsoleTextAttribute(h, 7);
		system("cls");
		goto m;
	}
	else
	{

		SetConsoleTextAttribute(h, 2);
		cout << "Product Quantity : ";
		SetConsoleTextAttribute(h, 7);
		cin >> qu;
		cout << endl;
		if (check[pn].second < qu)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "we don't have this quantity of this product please try again\n";
			SetConsoleTextAttribute(h, 7);
			goto k;
		}
		//takes the number of product and quantity
		items_added.insert({ pn,qu });
		SetConsoleTextAttribute(h, 14);
		cout << "press 1 to add another product \nany other key if u don't want to add  " << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice;
		cout << endl;

		add_to_cart();
		if (choice == 1)
		{
			system("cls");
			goto m;
		}
	}
	
}

void buyer::add_to_cart()
{
	//choose to add to cart
	fstream thisfile;
	thisfile.open("cart.txt",  ios::app );
	map<int, int>::iterator it = items_added.begin();	
	map<int, pair<int, int>> ::iterator it2 = check.begin();
	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator cartin = cart.begin();
	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator prod = products.begin();
	for (; it != items_added.end(); it++)
	{
		for (it2 = check.begin(); it2 != check.end(); it2++)
		{
			if (it->first == it2->first && it->second <= it2->second.second)
			{
				for (prod = products.begin(); prod != products.end(); prod++)
				{
					if (prod->first.second.first == it2->second.first)
					{
						//seller_name: first.first
						//id : first.second.first
						//name : first.second.second
						//price : second.first
						//category : second.second.first
						// quantity : second.second.second
						/*cartcomp = make_pair(prod->first.first, make_pair(prod->first.second.first, prod->first.second.second));
						cout << cartcomp.first <<" " cartcomp.second.first << cartcomp.second.second << endl;*/
						cartcheck[{prod->first.first, { prod->first.second.first, prod->first.second.second }}] += it->second;

						cart.insert({ {prod->first.first , { prod->first.second.first,prod->first.second.second }  }  ,  { prod->second.first  ,  { prod->second.second.first , it->second }  } });

						//thisfile << prod->first.first << " " << prod->first.second.second << " " << prod->second.second.first << " " << prod->first.second.first << " " << it->second << " " << prod->second.first << endl;
						prod->second.second.second = prod->second.second.second - it->second;
						//takes id and quantity of the selected product
						remove.insert({ prod->first.second.first , cartcheck[{prod->first.first, { prod->first.second.first, prod->first.second.second }}] });
						break;
					}
				}
			}
			
		}
	}
	items_added.clear();
	check.clear();
	file_edit();
	cart_edit();
	cart_map();

}

void buyer::displaycart()
{
	//display all products from file(cart)
	if (cart.empty())
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\t\t your cart is empty " << endl;
		SetConsoleTextAttribute(h, 7);
	
	}
	else
	{
		map< pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator disp = cart.begin();
		for (; disp != cart.end(); disp++)
		{
			cout << disp->first.first << " " << disp->first.second.first << " " << disp->first.second.second << " " << disp->second.first << " " << disp->second.second.first << " " << disp->second.second.second<<endl;
		}
	}
}

void buyer::display_search()
{

	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator it = products.begin();
	string N;
	bool  flag = 0;
	SetConsoleTextAttribute(h, 2);
	cout << "enter product name : " << endl;
	SetConsoleTextAttribute(h, 7);
	cin >> N;
	int i = 1;
	for (; it != products.end(); it++)
	{
		if (N == it->first.second.second)
		{
			flag = 1;
			cout << "| " << i << ") " << " Name : " << it->first.second.second
				<< " | " << "Price: " << it->second.first
				<< " | " << "Quantity: " << it->second.second.second
				<< " | " << "Category: " << it->second.second.first
				<< " | " << "Product Id : " << it->first.second.first;
			cout << endl;
			//takes the number of product , id and quantity
			// the number of product -> i
			//id -> first.second.first
			//quantity ->second.second.second
			check.insert({ i,{ it->first.second.first,it->second.second.second } });
			i++;
		}
	}

	if (!flag)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "NO DATA FOUND" << endl;
		SetConsoleTextAttribute(h, 7);
	}
	else
	{
		int pn;
		int qu;
		SetConsoleTextAttribute(h, 2);
		cout << "Product Number : ";
		SetConsoleTextAttribute(h, 7);
		cin >> pn;
		cout << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "Product Quantity : ";
		SetConsoleTextAttribute(h, 7);
		cin >> qu;
		cout << endl;
		//takes the number of product and quantity
		items_added.insert({ pn,qu });
		add_to_cart();
	}

}

void buyer::product_category()
{


	map<pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator it = products.begin();
	string C;
	bool  flag = 0;
	SetConsoleTextAttribute(h, 2);
	cout << "enter product category" << endl;
	SetConsoleTextAttribute(h, 7);
	cin >> C;
	int i = 1;
	for (; it != products.end(); it++)
	{
		if (C == it->second.second.first)
		{
			flag = 1;
			cout << "| " << i << ") " << " Name : " << it->first.second.second
				<< " | " << "Price: " << it->second.first
				<< " | " << "Quantity: " << it->second.second.second
				<< " | " << "Category: " << it->second.second.first
				<< " | " << "Product Id : " << it->first.second.first;
			cout << endl;
			//takes the number of product , id and quantity
			// the number of product -> i
			//id -> first.second.first
			//quantity ->second.second.second
			check.insert({ i,{ it->first.second.first,it->second.second.second } });
			i++;
		}
	}

	if (!flag)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "NO DATA FOUND" << endl;
		SetConsoleTextAttribute(h, 7);
	}
	else
	{
		int pn;
		int qu;
		SetConsoleTextAttribute(h, 2);
		cout << "Product Number : ";
		SetConsoleTextAttribute(h, 7);
		cin >> pn;
		cout << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "Product Quantity : ";
		SetConsoleTextAttribute(h, 7);
		cin >> qu;
		cout << endl;
		//takes the number of product and quantity
		items_added.insert({ pn,qu });
		add_to_cart();
	}

}

void buyer::pay()
{
	system("cls");
	//seller_name: first.first
						//id : first.second.first
						//name : first.second.second
						//price : second.first
						//category : second.second.first
						// quantity : second.second.second
	map< pair<string, pair<int, string>>, pair<double, pair<string, int> > > ::iterator it = cart.begin();
	double Amount = 0;
	double Total = 0;
	SetConsoleTextAttribute(h, 2);
	cout << "\n\t\t\t_______RECIEPT_______\n";
	SetConsoleTextAttribute(h, 7);
	for (; it != cart.end(); it++)
	{
		Amount = it->second.first * it->second.second.second;
		Total += Amount;
		SetConsoleTextAttribute(h, 14);
		cout << " Seller Name : ";
		SetConsoleTextAttribute(h, 7);
		cout << it->first.first << " ";
		SetConsoleTextAttribute(h, 14);
		cout << " id : ";
		SetConsoleTextAttribute(h, 7);
		cout << it->first.second.first << " ";
		SetConsoleTextAttribute(h, 14);
		cout << "Product Name: ";
		SetConsoleTextAttribute(h, 7);
		cout << it->first.second.second << " ";
		SetConsoleTextAttribute(h, 14);
		cout << "price: ";
		SetConsoleTextAttribute(h, 7);
		cout << it->second.first << " ";
		SetConsoleTextAttribute(h, 14);
		cout << "category: ";
		SetConsoleTextAttribute(h, 7);
		cout << it->second.second.first << " ";
		SetConsoleTextAttribute(h, 14);
		cout << "quantity: ";
		SetConsoleTextAttribute(h, 7);
		cout<< it->second.second.second << endl;
	}
	SetConsoleTextAttribute(h, 2);
	cout << "\n\n\t________________________" << endl;
	cout << "\n Total Amount : ";
	SetConsoleTextAttribute(h, 7);
	cout<< Total<<endl;
	clear();
	cart.clear();
}

buyer::~buyer()
{}