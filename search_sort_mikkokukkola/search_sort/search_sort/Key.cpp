#include "Key.h"   
int Key::comparisons = 0;
Key::Key(int i)
{
	key = i;
}
void Key::set_key(int i)
{
	key = i;
}
int Key::the_Key()const
{
	return key;
}


bool operator==(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_Key() == y.the_Key();
}
bool operator>(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_Key() > y.the_Key();
}
bool operator<(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_Key() < y.the_Key();
}
bool operator>=(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_Key() >= y.the_Key();
}
bool operator<=(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_Key() <= y.the_Key();
}
bool operator!=(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_Key() != y.the_Key();
}