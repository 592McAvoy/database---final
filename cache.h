/*
cache.h
���ݶ�����
*/


#include<map>
#include<list>
#include<set>

using namespace std;

class Cache
{
public:
	Cache() {};
	void add(int key, int value);	//��������
	int get(int key);				//��ȡ�����е�����
	void remove(int key);			//ɾȥ�����е�����
	void change(int key, int value);//�ı仺�������ݵ�ֵ
	bool contains(int key);			//�ж�ĳһkey�Ƿ����
	void clear();					//��ջ���
	void pop();
private:
	map<int, int> map;	//��������Ҫ���ݽṹ
	set<int> keyset;	//�洢���е�keyֵ�����������жϻ������Ƿ����ĳһkey
	list<int> keys;
	const int MAXsize = 30000;
	int size;
};


