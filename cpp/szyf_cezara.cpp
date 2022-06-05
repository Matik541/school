#include <iostream>
#include <string>

using namespace std;

string text;
int moveText = 1;

int main() {
  cout << "Podaj slowo do zaszyfrowania (male litery, bez cyfr): ";
  cin >> text;
  cout << "Podaj o ile liter ma sie przesunac szyfr: ";
  cin >> moveText;
  moveText = abs(moveText);
  for(auto letter : text)
    cout << char(((letter) + moveText - 97)%26 + 97);
  return 0;
}