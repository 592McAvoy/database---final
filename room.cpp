#include "room.h"

void Room::setEnd(int pos1)
{
	dat_end = pos1;
}

int Room::getDataPos()
{
	int pos;
	if (dat_pos.empty())
	{
		pos = dat_end;
		dat_end += datasize;
		return pos;
	}
	pos = dat_pos.front();
	dat_pos.pop();
	return pos;

}

void Room::addDataPos(int pos)
{
	dat_pos.push(pos);
}


