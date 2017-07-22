/*
RBNode.h
红黑树节点
*/

#include<string>
#include<sstream>
#include"index.h"
#include<iostream>

using namespace std;

//异常类
struct Error {
	string err;
	Error(string mes) :err(mes) {};
	void show() { cout << endl << err << endl<<"------------------------------------------\n"; }
};

//节点颜色
enum myColor { BLACK, RED };

class myRBNode {
public:
	myRBNode(myColor cc, int key = -1, myRBNode* l = NULL, myRBNode* r = NULL)
		:color(cc), mes(key), left(l), right(r) {};

	
	idxNode getNode() { return index; }			//获得该红黑树节点中存储的索引节点
	void setNode(idxNode idx) { index = idx; }	//设置索引节点

	friend class RBTree;
private:
	int mes;		//红黑树节点的值（等于索引节点的key值）
	idxNode index;	//索引节点
	myRBNode* left;
	myRBNode* right;
	myColor color;
};
