/*
RBNode.h
������ڵ�
*/

#include<string>
#include<sstream>
#include"index.h"
#include<iostream>

using namespace std;

//�쳣��
struct Error {
	string err;
	Error(string mes) :err(mes) {};
	void show() { cout << endl << err << endl<<"------------------------------------------\n"; }
};

//�ڵ���ɫ
enum myColor { BLACK, RED };

class myRBNode {
public:
	myRBNode(myColor cc, int key = -1, myRBNode* l = NULL, myRBNode* r = NULL)
		:color(cc), mes(key), left(l), right(r) {};

	
	idxNode getNode() { return index; }			//��øú�����ڵ��д洢�������ڵ�
	void setNode(idxNode idx) { index = idx; }	//���������ڵ�

	friend class RBTree;
private:
	int mes;		//������ڵ��ֵ�����������ڵ��keyֵ��
	idxNode index;	//�����ڵ�
	myRBNode* left;
	myRBNode* right;
	myColor color;
};
