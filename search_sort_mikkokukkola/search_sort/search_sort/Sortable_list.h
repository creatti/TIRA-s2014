#pragma once
#include"Key.h" 
#include"List.h" 
typedef Key Record;
template<class Record>
class Sortable_list :public List<Record>
{
public:
	void insertion_sort();
	void selection_sort();
	int max_key(int low, int high);
	void swap(int low, int high);
	void shell_sort();
	void Sort_interval(int start, int increment);
	void quick_sort();
	void recursive_quick_sort(int low, int high);
	int partition(int low, int high);
	void build_heap();
	void Insert_heap(const Record *t, int low, int high);
	void heap_sort();
	void merge_sort();
	void recursive_merge_sort(Record a[], int n);// 
	void merge(Record *des, Record *p, Record *q, int pcount, int qcount);
};
template <class Record>
void Sortable_list<Record>::merge(Record *des, Record *p, Record *q, int pcount, int qcount)
{
	int i = 0;
	int j = 0;
	for (int k = 0; k < pcount + qcount; ++k)
	{
		if (i < pcount&&j < qcount&&p[i] <= q[j])
		{
			des[k] = p[i];
			i++;
		}
		else if (i < pcount&&j<qcount&&p[i]>q[j])
		{
			des[k] = q[j];
			j++;
		}
		else if (i >= pcount)
		{
			des[k] = q[j];
			j++;
		}
		else if (j >= qcount)
		{
			des[k] = p[i];
			i++;
		}
	}
}
template <class Record>
void Sortable_list<Record>::recursive_merge_sort(Record a[], int n)
{
	if (n > 1)
	{
		Record *p = new Record[n / 2];
		Record *q = new Record[n - n / 2];
		for (int i = 0; i < n / 2; ++i)
		{
			p[i] = a[i];
		}
		for (int j = n / 2; j < n; ++j)
		{
			q[j - n / 2] = a[j];
		}
		recursive_merge_sort(p, n / 2);
		recursive_merge_sort(q, n - n / 2);
		merge(a, p, q, n / 2, n - n / 2);
	}
}
template <class Record>
void Sortable_list<Record>::merge_sort()
{
	recursive_merge_sort(entry, count);
}
template<class Record>
void Sortable_list<Record>::insertion_sort(){
	int first_unsorted;
	int position;
	Record current;
	for (first_unsorted = 1; first_unsorted<count; first_unsorted++)
	if (entry[first_unsorted]<entry[first_unsorted - 1])
	{
		
		position = first_unsorted;
		current = entry[first_unsorted];
		do
		{
			
			entry[position] = entry[position - 1];
			position--;
		} while (position>0 && entry[position - 1]>current);
		entry[position] = current;
	}
}
template <class Record>
void Sortable_list<Record>::selection_sort()
{
	for (int position = count - 1; position > 0; position--)
	{
		int max = max_key(0, position);
		swap(max, position);
	}
}
template <class Record>
int Sortable_list<Record>::max_key(int low, int high)
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
	if (entry[largest] < entry[current])
		largest = current;
	return largest;
}
template <class Record>
void Sortable_list<Record>::swap(int low, int high)
{
	Record temp;
	temp = entry[low];
	entry[low] = entry[high];
	entry[high] = temp;
}
template <class Record>
void Sortable_list<Record>::Sort_interval(int start, int increment)
{
	int first_unsorted;
	int position;
	Record current;
	for (first_unsorted = start + increment; first_unsorted<count; first_unsorted = first_unsorted + increment)
	if (entry[first_unsorted]<entry[first_unsorted - increment])
	{
		position = first_unsorted;
		current = entry[first_unsorted];
		do
		{
			entry[position] = entry[position - increment];
			position -= increment;
		} while (position>start&&entry[position - increment]>current);
		entry[position] = current;
	}
}
template <class Record>
void Sortable_list<Record>::shell_sort()
{
	int increment, start;
	increment = count;
	do
	{
		increment = increment / 3 + 1;
		for (start = 0; start<increment; start++)
			Sort_interval(start, increment);
	} while (increment>1);
}
template <class Record>
void Sortable_list<Record>::quick_sort()
{
	recursive_quick_sort(0, count - 1);
}
template <class Record>
void Sortable_list<Record>::recursive_quick_sort(int low, int high)
{
	int pivot_position;
	if (low < high)
	{
		pivot_position = partition(low, high);
		recursive_quick_sort(low, pivot_position - 1);
		recursive_quick_sort(pivot_position + 1, high);
	}
}
template <class Record>
int Sortable_list<Record>::partition(int low, int high)
{
	Record pivot;
	int i, last_small;
	swap(low, (low + high) / 2);
	pivot = entry[low];
	last_small = low;
	for (i = low + 1; i <= high; i++)
	if (entry[i] < pivot)
	{
		last_small = last_small + 1;
		swap(last_small, i);
	}
	swap(low, last_small);
	return last_small;
}
template <class Record>
void Sortable_list<Record>::heap_sort()
{
	Record current;
	int last_unsorted;
	build_heap();
	for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--)
	{
		current = entry[last_unsorted];
		entry[last_unsorted] = entry[0];
		Insert_heap(current, 0, last_unsorted - 1);
	}
}
template <class Record>
void Sortable_list<Record>::Insert_heap(const Record *t, int low, int high)
{
	int large;
	large = 2 * low + 1;
	while (large <= high)
	{
		if (large < high && entry[large] < entry[large + 1])
			large++;
		if (current>entry[large])
			break;
		else
		{
			entry[low] = entry[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	entry[low] = current;
}
template <class Record>
void Sortable_list<Record>::build_heap()
{
	int low;
	for (low = count / 2 - 1; low >= 0; low--)
	{
		Record current = entry[low];
		Insert_heap(current, low, count - 1);
	}
}