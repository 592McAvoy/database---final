/*
index.h
ʵ�ֶ������ļ��Ĳ���
�Ͷ������ڵ�ķ�װ
*/

#ifndef index_h
#define index_h


#include<fstream>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

//�����ڵ�
struct idxNode {
public:
	int idxPos; 
	int key;	
	int dataPos;

	idxNode() :idxPos(0), key(0), dataPos(0) {};
	idxNode(int mes, int pos2) :key(mes), dataPos(pos2) {};

	idxNode(const idxNode& node){
		idxPos = node.idxPos;
		key = node.key;
		dataPos = node.dataPos;
	}
};

bool operator==(idxNode &a, idxNode &b);


class Index
{
public:
	Index() {};

	void open(string db_name);
	void close();
	idxNode getNode(int pos);
	int get_end_pos();

private:
	string filename;
	fstream ff;
	idxNode idx;
	idxNode empty;
};



#endif

