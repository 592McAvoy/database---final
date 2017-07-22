/*
database.h
�ṩ���ݿ�Ľӿ�
*/

#include"Data.h"
#include"RBTree.h"
#include"cache.h"
#include"room.h"

#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

class DataBase {
public:
	DataBase() {};
	
	void generate(string name,int num);	//���ɹ���num�����ݵ������ļ��������ļ�

	void open(string db_name);			//��ȡ�����ļ����������������ʼ�����ݿ�
	void close();						

	void insert(int key,int value);
	void remove(int key);
	void find(int key);
	void change(int key, int value);

	
	bool empty();

private:
	string name;
	Data data;
	Index index;
	RBTree tree;
	Cache cache;
	Buffer buffer;
	Room room;

	void buildTree();
};

