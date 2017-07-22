#include"cache.h"

void Cache::add(int key, int value)
{
	if (size == MAXsize)
	{
		pop();
	}
	size++;
	map[key] = value;
	keyset.insert(key);
	keys.push_back(key);
}

int Cache::get(int key)
{
	return map[key];
}


void Cache::remove(int key)
{
	map.erase(key);
	keyset.erase(key);
	keys.remove(key);
	size--;
}

void Cache::change(int key, int value)
{
	map[key] = value;
}

bool Cache::contains(int key)
{
	return (keyset.find(key) != keyset.end());
}

void Cache::clear()
{
	map.clear();
	keyset.clear();
	size = 0;
}

void Cache::pop()
{
	int key = keys.front();
	keys.pop_front();
	map.erase(key);
	keyset.erase(key);
	size--;
}

