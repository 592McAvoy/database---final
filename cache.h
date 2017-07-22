/*
cache.h
数据读缓存
*/


#include<map>
#include<list>
#include<set>

using namespace std;

class Cache
{
public:
	Cache() {};
	void add(int key, int value);	//缓存数据
	int get(int key);				//读取缓存中的数据
	void remove(int key);			//删去缓存中的数据
	void change(int key, int value);//改变缓存中数据的值
	bool contains(int key);			//判断某一key是否存在
	void clear();					//清空缓存
	void pop();
private:
	map<int, int> map;	//读缓存主要数据结构
	set<int> keyset;	//存储已有的key值，用来快速判断缓存中是否存在某一key
	list<int> keys;
	const int MAXsize = 30000;
	int size;
};


