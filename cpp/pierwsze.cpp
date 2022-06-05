#include <iostream>
using namespace std;

void sito(bool *tab, unsigned int n)
{
  for (int i = 2; i * i <= n; i++)
    if (!tab[i])
      for (int j = i * i; j <= n; j += i)
        tab[j] = 1;
}

int main()
{
  int n;
  bool *tab;

  cout << "Podaj zakres do ktorego chcesz sprawdzac liczby pierwsze: ";
  cin >> n;

  tab = new bool[n + 1];

  for (int i = 2; i <= n; i++)
    tab[i] = 0;

  sito(tab, n); // przesianie liczb

  cout << "Kolejne liczby pierwsze z przedzialu <2;" << n << ">: ";

  for (int i = 2; i <= n; i++)
    if (!tab[i])
      cout << i << " ";

  delete[] tab;

  return 0;
}