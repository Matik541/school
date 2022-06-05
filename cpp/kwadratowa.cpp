#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int a, b, c, d, x0, x1, x2, p, q;
  cout << "Podaj a b c wedlug: ax^2 + bx + c\n";
  cin >> a;
  cin >> b;
  cin >> c;
  if (a == 0)
  {
    cout << "wspolczynnik a nie moze byc 0 >:(";
    return 0;
  }
  d = (double)(b * b - 4 * a * c);
  cout << "Delta wynosi: " << d << "\n(pierwiastek z delty: " << sqrt(d) << ")\n";
  if (d > 0)
  {
    x1 = (double)((-b - sqrt(d)) / (2 * a));
    x2 = (double)((-b + sqrt(d)) / (2 * a));
    cout << "Miejsca zerowe: " << x1 << ", " << x2 << endl;
  }
  else if (d == 0)
  {
    x0 = (double)((-b) / a);
    cout << "Miejsce zerowe: " << x0 << endl;
  }
  else
  {
    cout << "Brak miejsc zerowych" << endl;
  }

  p = (double)(-b / (2 * a));
  q = (double)(-d / (4 * a));
  cout << "Wierzcholek: (" << p << ";" << q << ")\n";

  cout << "Zbior wartosc: ";
  if (a > 0)
    cout << "<" << q << ";+inf)\n";
  else
    cout << "(-inf;" << q << ">\n";

  cout << "Wartosci dodatnie w zakresie: x nalezy do (-inf;" << x1 << ") U (" << x2 << ";+inf)\nWartosci ujemne w zakresie: x nalezy do (" << x1 << ";" << x2 << ")\n";

  cout << "Punkt przeciecia z osia Y: (0," << c << ")";

  return 0;
}