#include<iostream>
#include"loginregister.h"
#include"buyer.h"
#include"seller.h"
#include"admin.h"
#include<fstream>
#include<windows.h>


//global variable
int choice;
string user;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void startup(int i)
{
	if (i == 0)
	{
		
		loginregister l;
		cout << "\t\t\t---Hello to marketplace project---" << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "what services do you want?\n";
		SetConsoleTextAttribute(h, 7);
		cout << "1)login to your account\n";
		cout << "2)register\n";
		cout << "3)Admin\n";
		cin >> choice;
		if (choice == 1)
		{

			int choice;
			user = l.login();
			startup(1);
		}
		else if (choice == 2)
		{
			l.registery();
			startup(0);
		}
		else if (choice == 3)
		{
			l.loginadmin("admin@gmail.com");
			startup(4);
		}
		else
		{
			cout << "INVALID CHOICE" << endl;
			Sleep(1000);
			startup(0);
		}
	}
	else if (i == 1)
	{
		cout << "\t\t\t\t---welcome back: " << user <<" ---" << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "what services do you want?\n";
		SetConsoleTextAttribute(h, 7);
		cout << "1)buy product \n";
		cout << "2)sell product\n";
		cin >> choice;
		if (choice == 1)
		{
			startup(2);

		}
		else if (choice == 2)
		{
			startup(3);
		}
		else
		{
			SetConsoleTextAttribute(h, 4);
			cout << "INVALID CHOICE" << endl;
			SetConsoleTextAttribute(h, 7);
			Sleep(1000);
			startup(1);
		}
	}
	else if (i == 2)
	{
		int ch2;
	buyer b(user);
m:
	system("cls");
	cout << "\t\t\t --- logined user " << user << " ---"<<endl;
	SetConsoleTextAttribute(h, 2);
	cout << "MAIN MENU : " << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "1) buy product\n2) display cart\n3) remove from cart\n4)search by name\n5)search by category\n6)change user type\n7)log out\n8)pay" << endl;
	int ch;
	cin >> ch; cout << endl;
	if (ch == 1)
	{
		system("cls");
		b.buy_product();
		SetConsoleTextAttribute(h, 14);
		cout << "press 1 to return to main menu : "<<endl;
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch2; cout << endl;
		if (ch2 == 1)
		{
			goto m;
		}
		else return;
		
	}
	else if (ch == 2)
	{
		
			system("cls");
			b.displaycart();
			cout << "1) to return to main menu "<<endl;
			SetConsoleTextAttribute(h, 14);
			cout << "press any other number to exit program" << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> ch2; cout << endl;
			if (ch2 == 1)
				goto m;
			else return;
	
	}

	else if (ch == 3)
	{
		do
		{
			system("cls");
			b.remove_from_cart();
			cout << "1) to return to main menu \n2)Remove another product \n";
			SetConsoleTextAttribute(h, 14);
			cout << "press any other number to exit program" << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> ch2; cout << endl;
			if (ch2 == 1)
				goto m;
			else if (ch2 != 2)
				return;
		} while (ch2 == 2);
	}
	else if (ch == 4)
	{
		system("cls");
		b.display_search();
		cout << "press 1 to return to main menu : " << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch2; cout << endl;
		if (ch2 == 1)
			goto m;
		else
			return;
	
	}
	else if (ch == 5)
	{
		system("cls");
		b.product_category();
		cout << "press 1 to return to main menu : " << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch2; cout << endl;
		if (ch2 == 1)
			goto m;
		else
			return;
	}
	else if (ch == 6)
	{	
		system("cls");
		startup(1);
	}
	else if (ch == 7)
	{
		system("cls");
		startup(0);
	}
	else if (ch == 8)
	{
		system("cls");
		b.pay();
		cout << "press 1 to return to main menu : " << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch2; cout << endl;
		if (ch2 == 1)
			goto m;
		else
			return;
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "INVALID CHOICE" << endl;
		SetConsoleTextAttribute(h, 7);
		Sleep(1000);
		goto m;
	}
	}
	else if (i == 3)
	{
	seller s(user);
	int ch;
	system("cls");
	SetConsoleTextAttribute(h, 2);
	cout << "\t\t\t\t---welcome back: " << user << " ---" << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "what services do you want?\n";
	cout << "1)add a product\n";
	cout << "2)remove a product\n";
	cout << "3)modify a product\n";
	cout << "4)display all products\n";
	cout << "5)change user type\n";
	cout << "6)logout\n";
	cout << "7)exit\n";
	int choice; cin >> choice;
	if (choice == 1)
	{
		s.addproduct();
		cout << "press 1 to return to main menu";
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch; cout << endl;
		if (ch == 1)
			startup(3);
		else
			return;
	}
	else if (choice == 2)
	{
		s.removeproduct();
		cout << "press 1 to return to main menu" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch; cout << endl;
		if (ch == 1)
			startup(3);
		else
			return;
	}
	else if (choice == 3)
	{
		s.modifyproduct();
		cout << "press 1 to return to main menu" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch; cout << endl;
		if (ch == 1)
			startup(3);
		else return;
	}
	else if (choice == 4)
	{
		s.displayproduct();
		cout << "press 1 to return to main menu"<<endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> ch; cout << endl;
		if (ch == 1)
			startup(3);
		else return;
	}
	else if (choice == 5)
	{
		startup(1);
	}
	else if (choice == 6) {
		system("cls");
		startup(0);
	}
	else if (choice == 7) {
		system("cls");
		SetConsoleTextAttribute(h, 2);
		cout << "see you soon";
		SetConsoleTextAttribute(h, 7);
		Sleep(1000);
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "invalid choice\n";
		SetConsoleTextAttribute(h, 7);
		Sleep(1000);
		startup(3);
	}

	}
	else if (i == 4)
	{
	system("cls");

	admin admin;
	SetConsoleTextAttribute(h, 2);
	cout << "what services do you want?\n";
	SetConsoleTextAttribute(h, 2);
	cout << "1)add a product\n";
	cout << "2)remove a product\n";
	cout << "3)modify a product\n";
	cout << "4)display products\n";
	cout << "5)modify user\n";
	cout << "6)remove a user\n";
	cout << "7)display all users\n";
	cout << "8)logout\n";
	cout << "9)exit\n";
	int choice; cin >> choice;
	system("cls");

	switch (choice) {
	case 1: admin.add_product(); 
		cout << "press 1 to return to main menu"<<endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 2: admin.delete_product();
		cout << "press 1 to return to main menu"<<endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 3: admin.modify_product();
		cout << "press 1 to return to main menu";
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 4: admin.display_products();
		cout << "press 1 to return to main menu"<<endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 5: admin.modify_user(); 
		cout << "press 1 to return to main menu"<<endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 6: admin.delete_user();
		cout << "press 1 to return to main menu"<<endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program"<<endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 7: admin.display_users(); 
		cout << "press 1 to return to main menu" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "press any other number to exit program" << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> choice; cout << endl;
		if (choice == 1)
			startup(4);
		else return;
		break;
	case 8:
		startup(0);
		break;
	case 9:
		system("cls");
		SetConsoleTextAttribute(h, 4); 
		cout << "see you soon";
		SetConsoleTextAttribute(h, 7);
		Sleep(1000);
		exit(0);
		break;
	default:
	{
		SetConsoleTextAttribute(h, 4);
		cout << "invalid choice\n";
		SetConsoleTextAttribute(h, 7);
		break;
	}
	}
	startup(4);

    }
}


int main()
{
	startup(0);	
}