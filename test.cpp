#include<iostream>
#include"database.h"
#include<time.h>

using namespace std;

void test1(DataBase& db);
void test2(DataBase& db);
void test3(DataBase& db);
void test4(DataBase& db);

const int amount = 1000000;

struct bb{};

int main()
{
	clock_t start, finish;
	std::srand((unsigned)std::time(0));
	DataBase db;

	start = clock();
	db.generate("db",0);
	db.open("db");
	finish = clock();
	cout << "GENERATE - time: " << finish - start << endl;
	
	
	start = clock();
	test2(db);
	finish = clock();
	cout << "INSERT - time: " << finish - start << endl;

	start = clock();
	test1(db);	
	finish = clock();
	cout << "READ - time: " << finish - start << endl;

	start = clock();
	test3(db);
	finish = clock();
	cout << "Cycle - time: " << finish - start << endl;

	//start = clock();
	//test4(db);
	//finish = clock();
	//cout << "Remove&Find - time: " << finish - start << endl;

	start = clock();
	db.close();
	finish = clock();
	cout << "SAVE TREE - time: " << finish - start << endl;

	cin.get();
}

void test1(DataBase& db)
{
	int n = 0;
	while (n < amount)
	{
		int key = rand()*rand();
		db.find(key);

		n++;
	}
}

void test2(DataBase& db)
{
	int n = 0;
	while (n < amount)
	{
		int key = rand()*rand();
		int value = rand();
		db.insert(key, value);

		n++;
	}
}

void test3(DataBase& db)
{	
	
	int n = 0;
	
	while (n < 5 * amount) {
		int num = n % amount;
		//cout << "find: " << num << endl;
		db.find(num);
		if (n % 37 == 0) {
			num = int(rand() * 20 % amount);
			//cout << "remove: " << num << endl;
			db.remove(num);
		}
		if (n % 11 == 0)
		{
			num = int(rand() * 20 % amount);
			int rr = rand();
			//cout << "insert: " << num << " " << rr << endl;
			db.insert(num, rr);
			db.find(num);

		}
		if (n % 17 == 0) {
			num = int(rand() * 20 % amount);
			int rr = rand();
			//cout << "change: " << num << " " << rr << endl;
			db.change(num, rr);
		}
		n++;
	}
}

void test4(DataBase& db)
{
	int n = 1;
	while (!db.empty())
	{
		db.remove(n);
		int i = 0;
		while (i < 10)
		{
			int key = i*n*i;
			db.find(key);
			i++;
		}
		n++;
	}
}