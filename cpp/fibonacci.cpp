#include <iostream>

using namespace std;

int main()
{
  int to;
  long double fib[98304] = {0,1};
  // float:
  // 188 - nan nan
  // 187 - inf nan
  // 186 - inf inf
  // 185 - DUŻO DUŻO

  // double:
  // 1478 - nan nan
  // 1477 - inf nan
  // 1476 - inf inf
  // 1475 - DUŻO DUŻO DUŻO DUŻO DUŻO DUŻO

  // long double: 
  // 98304 - odpali (czasem), nie wyświetli 
  // 98303 - maks: inf inf
  // 23603 -  inf inf
  // 23602 -  inf BARDZO DUŻO
  // 23601 - DUŻOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
  
  // Program wyznaczający wybrany przez użytkownika element ciągu Fibonacciego (np. dziesiąty), element go poprzedzający (np. dziewiąty) i ich iloraz (np. dziesiąty przez dziewiąty), czyli wartość zbliżoną do złotej liczby.

  // 0 1 1 2 3 5 8 13 21 34...
  cout << "fibonacci sequence number: ";
  cin >> to;
  to = abs(to);
  for (int i = 2; i <= to; i++)
  // for (int i = 0; i < to; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
    // a = a + b;
    // b = a - b;
  }
  cout << "fib[" << to << "] = " << fib[to] << endl;
  cout << "fib[" << to - 1 << "] = " << fib[to - 1] << endl;
  cout << "Golden ratio: " << (fib[to] / fib[to - 1]) << endl;
  // cout << a << " " << b << endl;
  // cout << "Golden ratio: " << (a/b) << endl;

  return 0;
}