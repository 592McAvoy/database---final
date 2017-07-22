/*
database.h
提供数据库的接口
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
	
	void generate(string name,int num);	//生成关于num条数据的数据文件及索引文件

	void open(string db_name);			//读取索引文件，建立红黑树，初始化数据库
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

