/*
RBTree.h
�����
�������ݽṹ
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

	void insert(idxNode idx);//����������

	myRBNode* insert(int key);	//����ڵ�
	idxNode remove(int key);	//ɾ���ڵ�
	idxNode fetch(int key);		//��ѯ�ڵ�

	void save();	//�����ڵ��е������ڵ����ݴ��������ļ�

	int size = 0;	//���еĽڵ���Ŀ

private:	
	myRBNode* root;
	myRBNode* nullNode;	//�սڵ�
	myRBNode* fakeRoot;	//���ļٸ�
	
	//���ڶ����ĸ������
	myRBNode* current;
	myRBNode* parent;
	myRBNode* grand;
	myRBNode* great;
	myRBNode* brother;

	idxNode empty;	//��ʾ�յ������ڵ�
	
	//����ɾ��
	int ini_key;
	bool del;
	idxNode result;	//����ɾ������ʱ�ݴ�Ҫ��ɾ���������ڵ�

	void make_empty(myRBNode*& node);	//��������ͷ��ڴ�

	//�����Ĳ���
	myRBNode* my_find(const int &key);
	myRBNode* my_insert(const int &key);
	bool my_remove(int &key);

	//����ʵ�ַ���
	void handleReorient(const int &key);
	void left_rot(myRBNode*& center, myRBNode*& center_f);
	void right_rot(myRBNode*& center, myRBNode*& center_f);	
	void basic_move(const int &key);
	void transfer_A();
	void transfer_B();
	int find_key();
	myRBNode* find_prev(myRBNode*& node);
	myRBNode* find_succ(myRBNode*& node);

	//���ڴ洢������������
	fstream ff;
	void saveNode(idxNode idx);
};

