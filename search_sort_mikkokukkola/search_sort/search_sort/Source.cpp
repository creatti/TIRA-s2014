#include <iostream>
#include <cstdlib>
#include "Sortable_list.h"
#include <ctime>
#include <string>
#include <vector>

using namespace std;


void print(string algo, double elapsed, Error_code status, int comparisons, int searches)
{
	for (unsigned i = 0; i < algo.length() + 1; ++i)
		cout << "-";
	if (status == success)
		cout << "\nStatus: Successful" << endl;
	else
		cout << "\nStatus: Unsuccessful" << endl;
	cout << "Elapsed per search: " << elapsed / searches << endl;
	cout << "Comparisons per search: " << comparisons / searches << endl;
	cout << "Searches: " << searches << endl << endl;
}

Error_code sequential_search(const List<int> &the_list, const int &target, int &position, int &compa)
{
	int s = the_list.size();
	for (position = 0; position < s; position++) {
		++compa;
		int data;
		the_list.retrieve(position, data);
		if (data == target) return success;
	}
	return not_present;
}
Error_code binary_search_2(const List<int> &the_list,
	const int &target, int &position, int &compa)
{
	int data;
	int bottom = 0, top = the_list.size() - 1;
	while (bottom <= top) {
		++compa;
		position = (bottom + top) / 2;
		the_list.retrieve(position, data);
		if (data == target) return success;
		if (data < target) bottom = position + 1;
		else top = position - 1;
	}
	return not_present;
}

void tehtava1();
void tehtava2();
void tehtava3_4(bool);


int main()
{
	Sortable_list<int> succ_arr;
	time_t begin = clock();
	srand(static_cast<unsigned int>(begin));
	// srand(begin);

	int tehtava = 1;
	while (tehtava > 0)
	{
		cout << "Valitse teht\x84v\x84: (1-4): ";
		cin >> tehtava;

		switch (tehtava)
		{
			case 1:
				tehtava1();
				break;
			case 2:
				tehtava2();
				break;
			case 3:
				tehtava3_4(true);
				break;
			case 4:
				tehtava3_4(false);
				break;
			default:
				cout << "Shutting down.." << endl;
				return 0;
		}
	}

	
	system("pause");
	return 0;
}

void tehtava1()
{
	Sortable_list<int> arr;
	int kerroin = 0;
	cout << "Anna kerroin: ";
	cin >> kerroin;
	cout << "Testimateriaali: " << endl << "[ ";
	for (int i = 0; i < kerroin; ++i)
	{
		cout << i * 2 + 1;
		if (i < kerroin - 1)
			cout << ", ";
		arr.insert(i, i * 2 + 1);
	}
	cout << " ]" << endl << endl;
	int etsi = 0;
	int pos = -1;
	int compa = 0;
	while (etsi > -1)
	{
		cout << "\nMita etsitaan (paluu -1)? ";
		cin >> etsi;
		if (sequential_search(arr, etsi, pos, compa) == success)
			cout << etsi << " l\x94ytyi positiosta " << pos << endl;
		else if (etsi < 0)
			cout << "Palataan valikkoon..." << endl;
		else
			cout << "Ei l\x94ytynyt" << endl;
	}

}


void tehtava2()
{
	Sortable_list<int> arr;
	int kerroin = 10000;
	cout << "Testimateriaalin kerroin: " << kerroin << endl;
	cout << "Testimateriaali: " << endl << "[ ";
	for (int i = 0; i < kerroin; ++i)
	{
		if (i < 200)
		{
			cout << i * 2 + 1;
			if (i < kerroin - 1)
				cout << ", ";
		}
		arr.insert(i, i * 2 + 1);
	}
	cout << " ]" << endl << endl;
	int etsi = 0;
	int searches = 100;
	Error_code tulos;
	int pos = -1;
	int compa = 0;
	cout << "\nArvotaan luvut." << endl;
	clock_t begin = clock();
	srand(begin);
	for (int i = 0; i < searches; ++i)
	{
		etsi = 0;
		while (etsi % 2 == 0)
			etsi = rand() % 10000 + 1;
		tulos = sequential_search(arr, etsi, pos, compa);
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin);
	cout << "sequential_search:" << endl;
	print("sequential_search", elapsed_secs, tulos, compa, searches);
	begin = clock();
	for (int i = 0; i < searches; ++i)
	{
		etsi = 1;
		while (etsi % 2 != 0)
			etsi = rand() % 10000 + 1;
		tulos = sequential_search(arr, etsi, pos, compa);
	}
	end = clock();
	elapsed_secs = double(end - begin);
	print("sequential_search", elapsed_secs, tulos, compa, searches);
	cout << "\n\nbinary_search_2:" << endl;
	begin = clock();
	for (int i = 0; i < searches; ++i)
	{
		etsi = 0;
		while (etsi % 2 == 0)
			etsi = rand() % 10000 + 1;
		tulos = binary_search_2(arr, etsi, pos, compa);
	}
	end = clock();
	elapsed_secs = double(end - begin);
	print("binary_search_2", elapsed_secs, tulos, compa, searches);
	begin = clock();
	for (int i = 0; i < searches; ++i)
	{
		etsi = 1;
		while (etsi % 2 != 0)
			etsi = rand() % 10000 + 1;
		tulos = binary_search_2(arr, etsi, pos, compa);
	}
	end = clock();
	elapsed_secs = double(end - begin);
	print("binary_search_2", elapsed_secs, tulos, compa, searches);
}


void tehtava3_4(bool treeorfour)
{
	Sortable_list<int> arr;
	time_t begin = clock();
	srand(static_cast<unsigned int>(begin));
	// srand(begin);
	int kerroin = 10000;
	int alkiot = 50;
	cout << "Anna aineiston koko ( < 20k ): ";
	cin >> kerroin;
	cout << "Montako alkiota naytetaan? ";
	cin >> alkiot;
	cout << "Naytetaan ensimmaiset " << alkiot << " alkiota" << endl;
	cout << "[ ";
	for (int i = 0; i < kerroin; ++i)
	{
		int tmp = rand() % 9999 + 1;
		if (i < alkiot)
		{
			cout << tmp;
			if (i < kerroin - 1)
				cout << ", ";
		}
		arr.insert(i, tmp);
	}
	cout << "... ]" << endl << endl;
	if (treeorfour)
	{
		arr.insertion_sort();
		cout << "insertion_sort" << endl;
		
	}
	else
	{
		arr.quick_sort();
		cout << "quick_sort" << endl;
	}
	
	cout << "Naytetaan jarjestelyn jalkeen ensimmaiset " << alkiot << " alkiota" << endl << "[ ";
	for (int i = 0; i < alkiot; ++i)
	{
		int tmp;
		arr.retrieve(i, tmp);
		if (i < alkiot)
		{
			cout << tmp;
			if (i < alkiot - 1)
				cout << ", ";
		}
	}
	cout << "]" << endl;

}