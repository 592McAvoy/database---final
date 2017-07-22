#include "data.h"

void Data::open(string db_name)
{
	filename = db_name + ".dat";
	ff.open(filename, ios::in | ios::out | ios::binary);
}

void Data::close()
{
	ff.close();
}

int Data::get_data(int pos)
{
	ff.seekg(pos);
	ff.read((char*)&result, sizeof result);
	return result;
}


int Data::get_end_pos()
{
	ff.seekp(0, ios_base::end);	
	return ff.tellp();
}

void Data::update_dat(Buffer& buffer)
{
	while (!buffer.dat_buf.empty())
	{
		write(buffer.dat_buf.front());
		buffer.dat_buf.pop();
	}
	buffer.clear();
}

void Data::write(dataNode& dat)
{
	ff.seekp(dat.pos);
	ff.write((char*)&dat.data, sizeof dat.data);
}

bool Buffer::store(int value, int pos)
{
	dat_buf.push(dataNode(value, pos));
	size++;
	if (size == MAXsize)
		return false;
	return true;
	
}

bool Buffer::empty()
{
	return size == 0;
}


