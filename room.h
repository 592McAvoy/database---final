/*
room.h
ʵ�ֶ����ݵĴ洢�ռ�Ĺ���
*/
#pragma once
#include<queue>

using namespace std;

const int datasize = 4;
const int idxsize = 12;

class Room
{
public:
	Room() {};

	void setEnd(int pos1);//�������ݿ�ʱ��������ļ���ĩβλ��

	int getDataPos();//���ؿ���λ��
	void addDataPos(int pos);//��¼����λ��
private:
	int dat_end;
	queue<int> dat_pos;
};