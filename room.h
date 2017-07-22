/*
room.h
实现对数据的存储空间的管理
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

	void setEnd(int pos1);//创建数据库时获得数据文件的末尾位置

	int getDataPos();//返回可用位置
	void addDataPos(int pos);//记录可用位置
private:
	int dat_end;
	queue<int> dat_pos;
};