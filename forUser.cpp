#include<iostream>
#include"database.h"

using namespace std;

struct Quit{};

char manu1();
void deal1(DataBase& db);

char manu2();
void deal2(DataBase &db);

int main()
{
	DataBase db;
	try 
	{
		deal1(db);
		deal2(db);
	}
	catch (Quit q) {
		cout << "Saving...\n";
		db.close();
		return 0;
	}


}

char manu1()
{
	cout << "What do you want to do?\n";
	cout << "1. Open a database.\n";
	cout << "2. Bulid a database.\n";

	char ch;
	cin.get(ch);
	cin.get();

	return ch;
}

void deal1(DataBase& db) {
	char ch = manu1();

	string name;	
	switch (ch)
	{
	case'1': 
	{
		cout << "\nEnter the name: ";
		getline(cin, name);
		cout << "Opening...\n";
		db.open(name);
		break;
	}
	case'2':
	{
		cout << "\nEnter the name: ";
		getline(cin, name);
		int amount;
		cout << "Enter the amount of data: ";
		cin >> amount;
		cin.get();
		db.generate(name, amount);
		cout << "Opening...\n";
		db.open(name);
		break;
	}
	default:throw Quit();
	}
	return;
}

char manu2()
{
	cout << "\n1. Search\n";
	cout << "2. Insert\n";
	cout << "3. Remove\n";
	cout << "4. Modify\n";
	cout << "5. Quit\n";
	cout << "\nPlease enter your choice: ";

	char ch;
	cin.get(ch);
	cin.get();

	return ch;
}

void deal2(DataBase & db)
{
	while (true)
	{

		char ch = manu2();
		switch (ch) {
		case'1': {
			int key;
			cout << "\nEnter the key(int): ";
			cin >> key;
			cin.get();

			db.find(key);
			break;
		}
		case'2': {
			int key;
			cout << "\nEnter the key(int): ";
			cin >> key;
			cin.get();

			int value;
			cout << "Enter the value(int): ";
			cin >> value;
			cin.get();

			db.insert(key, value);
			break;
		}
		case'3': {
			int key;
			cout << "\nEnter the key(int): ";
			cin >> key;
			cin.get();

			db.remove(key);
			break;
		}
		case'4': {
			int key;
			cout << "\nEnter the key(int): ";
			cin >> key;
			cin.get();

			int value;
			cout << "Enter the value(int): ";
			cin >> value;
			cin.get();

			db.change(key, value);
			break;
		}
		case'5': throw(Quit());
		default: throw(Error("Bad input"));
		}

	}
}
