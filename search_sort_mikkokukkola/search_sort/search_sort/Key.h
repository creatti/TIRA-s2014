#pragma once
class Key
{
	int key;
public:
	static int comparisons;
	Key(int x = 0);
	void set_key(int i);
	int the_Key()const;
};
bool operator==(const Key &x, const Key &y);
bool operator>(const Key &x, const Key &y);
bool operator<(const Key &x, const Key &y);
bool operator>=(const Key &x, const Key &y);
bool operator<=(const Key &x, const Key &y);
bool operator!=(const Key &x, const Key &y);