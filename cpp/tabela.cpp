#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <time.h>

using namespace std;

clock_t start_r, start, stop;
float calc_time, calc_time_r;

int typ = 3;
int ilosc = 100000;

// by select
void by_select(int arr[], int size)
{
	int i, j, mini;

	for (i = 0; i < size - 1; i++)
	{
		mini = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[mini])
				mini = j;

		swap(arr[mini], arr[i]);
	}
}

// by insert
void by_insert(int arr[], int size)
{
	for (int i = 1; i <= size; i++)
	{
		int l = arr[i];
		int j = i - 1;
		while (j >= 0 && l <= arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = l;
	}
}

// quicksort
int position(int arr[], int first, int last)
{
	int pivot = arr[last];
	int i = (first - 1);

	for (int j = first; j <= last - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[last]);
	return (i + 1);
}

void quick_sort(int arr[], int first, int last)
{
	if (first < last)
	{
		int pos = position(arr, first, last);

		quick_sort(arr, first, pos - 1);
		quick_sort(arr, pos + 1, last);
	}
}

// b�belkowe
void babelkowe(int arr[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int random(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}

void set_random(int arr[], int size, int from, int to)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = random(from, to);
	}
}

void display(int arr[], int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1] << "\n";
}

void sort_array(int arr[], int size)
{
	int type = typ;
	// cout << "wybierz sortowanie: \n1. przez wybor\n2. przez wstawianie\n3. kubelkowe\n4. quicksort\n5. babelkowe\n";
	// cin >> type;
	switch (type)
	{
	case 1:
		by_select(arr, size);
		break;
	case 2:
		by_insert(arr, size);
		break;
	case 3:
		quick_sort(arr, 0, size);
		break;
	case 4:
		babelkowe(arr, size);
		break;
	}
}

int from = 0;
int to = 10;
int times = 0;
int main()
{
	srand(time(NULL));

	// cout << "Podaj zakres od: ";
	// cin >> from;
	// cout << "do: ";
	// cin >> to;

	// if (from > to)
	// {
	// 	swap(from, to);
	// }

	do
	{
		 cout << "Podaj ilosc elementow: ";
		 cin >> times;
	} while (times < 1);

	int * tabel = new int[times];

	set_random(tabel, times, from, to);
	// display(tabel, times);

	start = clock();
	sort_array(tabel, times);
	// display(tabel, times);
	stop = clock();

	delete [] tabel;

	calc_time = (float)(stop - start);
	cout << "Czas dla algorytmu: " << typ << " to: " << calc_time << endl;

}