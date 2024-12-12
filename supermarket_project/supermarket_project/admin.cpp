#include "admin.h"
#include "seller.h"
#include<iostream>
#include <string>
#include<fstream>
#include<map> 
using namespace std;
/*done*/admin::admin() : seller("admin")
{
	file_fetch();
}

/*done*/void admin::file_fetch()
{
	//fetch all saved data to map (products/users)
	fstream user_file;
	user_file.open("user.txt", ios::in);
	while (user_file >> email>> password >> username >> address>> phone_number>>user_id )
	{
		users[email] = usernam(password,username, address,  phone_number,user_id);
	}
}

void admin::welcomeAdmin()
{
	//	cout << "\t\t\t\twelcome hend!" << "\n";
	SetConsoleTextAttribute(h, 2);
	cout << "what services do you want?\n";
	SetConsoleTextAttribute(h, 7);
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
	switch (choice) {
	case 1: add_product(); break;
	case 2: delete_product(); break;
	case 3: modify_product(); break;
	case 4: display_products(); break;
	case 5: modify_user(); break;
	case 6: delete_user(); break;
	case 7: display_users(); break;
	case 8:
		cout << ""; //logout function
		break;
	case 9:
		SetConsoleTextAttribute(h, 2);
		cout << "see you soon";
		SetConsoleTextAttribute(h, 7);
		exit(0);
		break;

	default: 	SetConsoleTextAttribute(h, 4); cout << "invalid choice\n";	SetConsoleTextAttribute(h, 7); break;

	}
	welcomeAdmin();
}

/*done*/void admin::add_product()
{
	addproduct();
}

/*done*/void admin::delete_product()
{
	cout << "1) delete from your products.\n2) delete from all products.\n";
	int choice; cin >> choice;
	string sl;
	switch (choice) {
	case 1: removeproduct(); break;
	case 2:
		SetConsoleTextAttribute(h, 2);
		cout << "choose the name of seller and its product ";
		SetConsoleTextAttribute(h, 7);

		cin >> sl >> name;
		if (searchAllproducts(sl, name)) {
			cout << name;
			SetConsoleTextAttribute(h, 4);
			cout<< " doesn't exist\n";
			SetConsoleTextAttribute(h, 7);
			delete_product(); //needs handling
		}
		else
		{
			file_data.erase(make_pair(sl, name));
			all_data.erase(make_pair(sl, name));
			updateFile();
		}
		break;
	default:	SetConsoleTextAttribute(h, 4); cout << "wrong choice\n";	SetConsoleTextAttribute(h, 7); break;
	}
}

/*done*/void admin::delete_user()
{
	//delete userinformation from file (user) 
	display_users();
	SetConsoleTextAttribute(h, 2);
	cout << "enter the email of the user that you want to delete" << endl;
	SetConsoleTextAttribute(h, 7);
	cin >> email;
	if (users[email].username == "admin")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "you can't delete yourself as an  admin\n";
		SetConsoleTextAttribute(h, 7);
	}
	else {
		if (search_user(email))
		{
			SetConsoleTextAttribute(h, 4);
			cout << "user doesn't exist\n";
			SetConsoleTextAttribute(h, 7);
		}
		else {
			users.erase(email);
			update_user();
			SetConsoleTextAttribute(h, 2);
			cout << "user deleted successfuly\n";
			SetConsoleTextAttribute(h, 7);
		}
	}

}

/*done*/void admin::display_users()
{
	//display all users in file(user)
	cout << "user id\t username \t email \t phone number \t address \t " << endl;
	for (auto p : users) {
		if (p.second.username == "admin")
			continue;
		cout << p.first << "\t" << p.second.username << "\t" << p.second.address<< "\t" << p.second.phone_number <<"\t"<<p.second.user_id<< "\n";
	}
}

/*done*/bool admin::search_user(string email)
{
	map<string, usernam>::iterator it;
	it = users.find(email);
	if (it == users.end())//if it doesn't find the user
		return true;
	else
		return false; //user exists 
}

void admin::update_user()
{
	ofstream user_file("user.txt", ios::out | ios::trunc);
	for (auto p : users) {
		user_file << p.first << " " << p.second.password <<" " << p.second.username <<" " << p.second.address << " " << " " << p.second.phone_number <<" "<<user_id << "\n";
	}
}

/*done*/void admin::display_products()
{
	cout << "1) display your products.\n2) display all products.\n";
	int choice; cin >> choice;
	switch (choice) {
	case 1: displayproduct(); break;
	case 2:
		cout << "\t\tseller name\tname category\tid\tquantity\tprice\n";
		for (auto p : all_data) {
			cout << "\t\t" << p.first.first << "\t" << p.first.second << "\t" << p.second.category << "\t" << p.second.id << "\t" << p.second.qty << "\t" << p.second.price << "\n";
		}
		break;
	default:
		SetConsoleTextAttribute(h, 4);
		cout << "wrong choice\n";
		SetConsoleTextAttribute(h, 7);
		break;
	}


}
bool admin::searchAllproducts(string seller_name, string name)
{
	map<pair<string, string>, productData>::iterator i;
	i = all_data.find({ seller_name,name });
	if (i == all_data.end())//if it doesn't find the name
		return true;
	else
		return false; //product is there 

}
/*done*/void admin::modify_product()
{
	modifyproduct();
}
/*done*/void admin::modify_user()
{
	SetConsoleTextAttribute(h, 2);
	cout << "enter the id of the user you want to modify: ";
	SetConsoleTextAttribute(h, 7);
	cin >> email;
	if (search_user(email)) {
		SetConsoleTextAttribute(h, 4);
		cout << "user doesn't exist\n";
		SetConsoleTextAttribute(h, 7);
	}
	else
	{
		SetConsoleTextAttribute(h, 2);
		cout << "what do you want to modify?\n";
		SetConsoleTextAttribute(h, 7);
		cout << "1)username\n2)password\n3)phone number\n4)address\n";
		int nid = users[email].user_id;
		int choice; cin >> choice;
		switch (choice) {
		case 1:
			SetConsoleTextAttribute(h, 2);
			cout << "enter the new username" << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> username;
			users[email].username = username;
			break;
		case 2:
			SetConsoleTextAttribute(h, 2);
			cout << "enter the new password" << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> password;
			users[email].password = password;
			break;
		case 3:
			SetConsoleTextAttribute(h, 2);
			cout << "enter the new phone_number" << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> phone_number;
			users[email].phone_number = phone_number;
			break;
		case 4:
			SetConsoleTextAttribute(h, 2);
			cout << "enter the new address" << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> address;
			users[email].address = address;
			break;
		default: 	SetConsoleTextAttribute(h, 4);
					cout << "wrong choice\n";
					SetConsoleTextAttribute(h, 7);
					break;

		}
		update_user();

	}

}

admin::~admin()
{}