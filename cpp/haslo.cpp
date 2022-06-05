#include <iostream>
#include <climits>
#include <string>

using namespace std;

string name;
string password;

int i = 0;
int l = 0;

int main()
{
  cout << "Podaj imie: ";
  cin >> name;

  i = 0;
  while (name[i])
  {
    name[i] = tolower(name[i]);
    i++;
  }

  cout << "Twoj login: " << name << endl;

  bool lower = false;
  bool upper = false;
  bool digit = false;
  bool symbol = false;

  while (true) {
    cout << "Podaj haslo: ";
    cin >> password;

    string symbols = "!@#$%^&*?,.<>()[]{}|/\\";
    i = 0;
    while ( password[i] ){
      if(islower(password[i]))
        lower = true;
      if(isupper(password[i]))
        upper = true;
      if(isdigit(password[i]))
        digit = true;
      l = 0;
      while(symbols[l]){
      if(symbols[l] == password[i])
        symbol = true;
        l++;
      }
      i++;
    }
    if (i < 8)
      cout << "Haslo musi miec conajmniej 8 znakow\n";
    if (!lower)
      cout << "Haslo nie zawiera malej litery!\n";
    if (!upper)
      cout << "Haslo nie zawiera duzej litery!\n";
    if (!digit)
      cout << "Haslo nie zawiera cyfry!\n";
    if (!symbol)
      cout << "Haslo nie zawiera znaku specjalnego!\n";
    if(lower && upper && digit && symbol && i >= 8)
      break;
  }
  cout << "Poprawne haslo!";
  
  return 0;
}
