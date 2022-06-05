#include <array>
#include <ctime>
#include <iostream>
#include <time.h>

using namespace std;

clock_t t;
int from = 0, to = 100;
int times = 1000;

void display(int *arr, int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1] << "\n";
}

int random(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}
int *set_random(int *arr, int size, int from, int to)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = random(from, to);
	}
	return arr;
}

int *by_select(int *arr, int size)
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
	return arr;
}
int *by_insert(int *arr, int size)
{
	for (int i = 1; i <= size; i++)
	{
		int l = arr[i];
		int j = i - 1;
		while (j >= 0 && l <= arr[j])
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = l;
	}
	return arr;
}
int *babelkowe(int *arr, int size)
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
	return arr;
}
int *bucket_sort(int *arr, int size, int from, int to)
{
	int lw[to - from + 1], i, j;

	for (int i = from; i <= to; i++)
	{
		lw[i - from] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		lw[arr[i] - from]++;
	}

	j = 0;
	for (int i = from; i <= to; i++)
	{
		while (lw[i - from]--)
		{
			arr[j++] = i;
		}
	}
	return arr;
}

int main()
{
	do
	{
		cout << "Podaj ilosc elementow tabeli: ";
		cin >> times;
	} while (times <= 0);
	cout << "Sprawdzanie dla: " << times << " elementow\nPodaj zakres \nod: ";
	cin >> from;
	cout << "do: ";
	cin >> to;
	if (to < from)
	{
		to += from;
		from = to - from;
		to -= from;
	}

	int *tab = new int[times];
	// int *arr = new int[times];
	tab = set_random(tab, times, from, to);

	int sort = 0;
	bool disp = 0;

	cout << "1 - przez wstawianie\n2 - przez wybor\n3 - babelkowe\n4 - kubelkowe\nWybierz sortowanie:";
	cin >> sort;
	t = clock();
	switch (sort)
	{
	case 1:
		by_insert(tab, times);
		cout << "Przez wstawianie: " << (clock() - t) << endl;
		break;
	case 2:
		by_select(tab, times);
		cout << "Przez wybor: " << (clock() - t) << endl;
		break;
	case 3:
		babelkowe(tab, times);
		cout << "Babelkowe: " << (clock() - t) << endl;
		break;
	case 4:
		bucket_sort(tab, times, from, to);
		cout << "Kubelkowe: " << (clock() - t) << endl;
		break;
	default:
		cout << "Miales opcje od 1 do 4, czego nie rozumiesz?";
		break;
	}
	cout << "\n\n(0 - nie, 1 - tak)\nWypisac: ";
	cin >> disp;
	if (disp)
		display(tab, times);

	delete[] tab;

	return 0;
}