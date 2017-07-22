#include "database.h"

void DataBase::generate(string name,int num)
{
	std::srand(std::time(0)); // use current time as seed for random generator
	ofstream index(name+".idx", ios::out | ios::binary);
	ofstream datas(name+".dat", ios::out | ios::binary);

	int key = 1;
	idxNode idx;
	while (key <= num) {
		int data = std::rand();//*std::rand();
		idx.idxPos = (key - 1)*idxsize;
		idx.dataPos = (key - 1)*datasize;
		idx.key = key++;
		index.write((char*)&idx, sizeof idx);
		datas.write((char*)&data, sizeof data);
	}
	index.close();
	datas.close();
}

void DataBase::open(string db_name)
{
	name = db_name;
	index.open(name);
	data.open(name);
	buildTree();
	room.setEnd(data.get_end_pos());
	index.close();
}

void DataBase::insert(int key, int value)
{
	if (cache.contains(key))
	{
		//cout << "INSERT ERROR : Existed Key " << key << endl;
		return;
	}
	myRBNode* node = tree.insert(key);
	if (node == NULL)
	{
		//cout << "INSERT ERROR : Existed Key " << key << endl;
		return;
	}
	cache.add(key, value);
	int dat_pos = room.getDataPos();
	idxNode idx(key,dat_pos);

	node->setNode(idx);
	buffer.store(value, dat_pos);

	//cout << "INSERT - key: " << key <<
		//" value: " << value << endl;
}


void DataBase::remove(int key)
{
	if (cache.contains(key))
		cache.remove(key);

	idxNode empty;
	idxNode idx = tree.remove(key);

	if (idx == empty) {
		//cout << "REMOVE ERROR: Nonexisted Key " << key << endl;
		return;
	}
	room.addDataPos(idx.dataPos);

	if (buffer.store(-1, idx.dataPos));
	else
		data.update_dat(buffer);
	
	//cout << "REMOVE - key: " << key << endl;
}

void DataBase::find(int key)
{
	int result;
	if (cache.contains(key))
	{
		result = cache.get(key);
	}
	else
	{
		idxNode empty;
		idxNode idx = tree.fetch(key);
		if(idx==empty)
		{
			//cout << "FETCH ERROR: Nonexisted Key " << key << endl;
			return;
		}
		if (!buffer.empty())
			data.update_dat(buffer);
		result = data.get_data(idx.dataPos);
		cache.add(key, result);
	
	}

	//cout << "FIND - key: " << key
		//<< " value: " << result << endl;
}

void DataBase::change(int key, int value)
{
	idxNode empty;
	idxNode idx = tree.fetch(key);
	if (idx == empty)
	{
		//cout << "FETCH ERROR: Nonexisted Key " << key << endl;
		return;
	}

	if (cache.contains(key))
		cache.change(key, value);
	else
		cache.add(key, value);

	if (buffer.store(value, idx.dataPos));
	else
		data.update_dat(buffer);

	//cout << "CHANGE - key: " << key
		//<< " value: " << value << endl;
}

void DataBase::close()
{
	data.close();
	cache.clear();
	tree.save();
	data.update_dat(buffer);
}

bool DataBase::empty()
{
	return tree.size == 0;
}

void DataBase::buildTree()
{
	int pos = 0;
	while (pos < index.get_end_pos()) {
		tree.insert(index.getNode(pos));
		pos += idxsize;
	}
}

