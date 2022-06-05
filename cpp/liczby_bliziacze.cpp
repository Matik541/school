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

  cout << "Podaj zakres do ktorego chcesz sprawdzac liczby pierwsze: ";
  cin >> n;

  bool *tab = new bool[n + 1];

  for (int i = 2; i <= n; i++)
    tab[i] = 0;

  sito(tab, n);

  cout << "Kolejne liczby blizniacze z przedzialu <2;" << n << ">: ";

  int x = 3;

  for (int i = 2; i < n / 2; i++)
  {
    if (tab[x] == 0 && tab[x + 2] == 0)
    {
      cout << "(" << x << " " << x + 2 << "), ";
    }
    x += 2;
  }

  delete[] tab;

  return 0;
}