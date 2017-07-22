/*
data.h
实现对数据文件的操作
*/
#ifndef Data_h
#define Data_h

#include<fstream>
#include<string>
#include<queue>

using namespace std;

//对data的位置和数值进行简单封装
struct dataNode
{
	dataNode(int value, int positon) :data(value), pos(positon) {};
	int data;
	int pos;
};


class Buffer
{
public:
	Buffer() {};
	
	bool store(int value, int pos);	//将数据存在缓存中
	bool empty();	//判断缓存是否为空
	void clear() { size = 0; }
	queue<dataNode> dat_buf;	//缓存结构
private:
	const int MAXsize = 10000;	//缓存中可存储的数据的最大值
	int size = 0;					//当前容量	
};


class Data {
public:
	Data() {};
	void open(string db_name);
	void close();
	int get_data(int pos);
	int get_end_pos();
	void update_dat(Buffer& buffer);		//刷新数据
private:
	string filename;
	fstream ff;
	int result;
	int empty = -1;
	void write(dataNode&);		//向文件中写入数据
};
#endif