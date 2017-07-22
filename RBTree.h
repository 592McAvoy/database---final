/*
RBTree.h
红黑树
核心数据结构
*/

#include"RBNode.h"
#include<string>
#include<iostream>
#include<stack>

using namespace std;


class RBTree {

public:
	RBTree();
	~RBTree();

	void insert(idxNode idx);//用于生成树

	myRBNode* insert(int key);	//插入节点
	idxNode remove(int key);	//删除节点
	idxNode fetch(int key);		//查询节点

	void save();	//将树节点中的索引节点数据存入索引文件

	int size = 0;	//树中的节点数目

private:	
	myRBNode* root;
	myRBNode* nullNode;	//空节点
	myRBNode* fakeRoot;	//树的假根
	
	//用于对树的各项操作
	myRBNode* current;
	myRBNode* parent;
	myRBNode* grand;
	myRBNode* great;
	myRBNode* brother;

	idxNode empty;	//表示空的索引节点
	
	//用于删除
	int ini_key;
	bool del;
	idxNode result;	//用以删除操作时暂存要被删除的索引节点

	void make_empty(myRBNode*& node);	//清空树，释放内存

	//对树的操作
	myRBNode* my_find(const int &key);
	myRBNode* my_insert(const int &key);
	bool my_remove(int &key);

	//具体实现方法
	void handleReorient(const int &key);
	void left_rot(myRBNode*& center, myRBNode*& center_f);
	void right_rot(myRBNode*& center, myRBNode*& center_f);	
	void basic_move(const int &key);
	void transfer_A();
	void transfer_B();
	int find_key();
	myRBNode* find_prev(myRBNode*& node);
	myRBNode* find_succ(myRBNode*& node);

	//用于存储树中索引数据
	fstream ff;
	void saveNode(idxNode idx);
};

