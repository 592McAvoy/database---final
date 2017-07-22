#include"index.h"

int Index::get_end_pos()
{
	ff.seekp(0, ios_base::end);	
	return ff.tellp();
}

void Index::open(string db_name)
{
	filename = db_name + ".idx";
	ff.open(filename, ios::in | ios::out | ios::binary);
}

void Index::close()
{
	ff.close();
}

idxNode Index::getNode(int pos)
{
	if (pos >= get_end_pos())
		return empty;
	ff.seekg(pos);
	ff.read((char*)&idx, sizeof idx);
	return idx;
}

bool operator==(idxNode & a, idxNode & b)
{
	return a.key == b.key&&
		a.dataPos == b.dataPos&&
		a.idxPos == b.idxPos;
}
