#pragma once
#include "Utility.h" 
const int max_list = 20000;

template <class List_entry>
class List
{
public:
	List();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(List_entry&));
	Error_code retrieve(int position, List_entry& x)const;
	Error_code replace(int position, const List_entry& x);
	Error_code remove(int position, List_entry& x);
	Error_code insert(int position, const List_entry& x);
protected:
	int count;
	List_entry entry[max_list];
};
template <class List_entry>
int List<List_entry>::size() const
{
	return count;
}
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry& x)
{
	if (full())
		return overflow;
	if (position < 0 || position > count)
			return overflow;
	for (int i = count - 1; i >= position; i--)
		entry[i + 1] = entry[i];
	entry[position] = x;
	count++;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
	if (empty())
		return fail;
	if (position < 0 || position >= count)
		return overflow;
	x = entry[position];
	count--;
	while (position < count)
	{
		entry[position] = entry[position + 1];
		position++;
	}
	return success;
}
template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
	if (empty())
		return fail;
	if (position < 0 || position >= count)
		return overflow;
	x = entry[position];
	return success;
}
template<class List_entry>
void  List<List_entry>::traverse(void(*visit)(List_entry&))
{
	for (int i = 0; i<count; i++)
		(*visit)(entry[i]);
}
template<class List_entry>
bool List<List_entry>::full()const
{
	if (count>max_list)
		return true;
	else
		return false;
}
template<class List_entry>
bool List<List_entry>::empty()const
{
	if (count == 0)
		return true;
	else
		return false;
}
template<class List_entry>
void List<List_entry>::clear()
{
	count = 0;
}
template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
	if (empty())
		return fail;
	if (position<0 || position>count)
		return overflow;
	entry[position] = x;
	return success;
}
template<class List_entry>
List<List_entry>::List()
{
	count = 0;
}