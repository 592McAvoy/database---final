/*
data.h
ʵ�ֶ������ļ��Ĳ���
*/
#ifndef Data_h
#define Data_h

#include<fstream>
#include<string>
#include<queue>

using namespace std;

//��data��λ�ú���ֵ���м򵥷�װ
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
	
	bool store(int value, int pos);	//�����ݴ��ڻ�����
	bool empty();	//�жϻ����Ƿ�Ϊ��
	void clear() { size = 0; }
	queue<dataNode> dat_buf;	//����ṹ
private:
	const int MAXsize = 10000;	//�����пɴ洢�����ݵ����ֵ
	int size = 0;					//��ǰ����	
};


class Data {
public:
	Data() {};
	void open(string db_name);
	void close();
	int get_data(int pos);
	int get_end_pos();
	void update_dat(Buffer& buffer);		//ˢ������
private:
	string filename;
	fstream ff;
	int result;
	int empty = -1;
	void write(dataNode&);		//���ļ���д������
};
#endif