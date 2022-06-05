#include <iostream>
#include "pierw.cpp" // funkcja jako biblioteka

using namespace std;

float polet(float a, float b, float c)
{
  float p = (a + b + c) / 2;
  return pierw(p * (p - a) * (p - b) * (p - c));
}
int main()
{
  float a, b, c;
  cout << "Podaj boki trojkat (3): \n";
  cin >> a;
  cin >> b;
  cin >> c;
  if ((a + b) > c && (b + c) > a && (a + c) > b)
  {
    cout << "Mozna zbudowac taki trojkat\nObwod: " << (a + b + c) << "\nPole: " << polet(a, b, c);
  }
  else
  {
    cout << "Nie mozna zbudowac takiego trojkata";
  }
  return 0;
}