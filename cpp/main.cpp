#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main()
{
    int a;
    int b;
    do
    {
        cout << "Podaj a: ";
        cin >> a;
    }
    while(a<=0);
    do
    {
        cout << "Podaj b: ";
        cin >> b;
    }
    while(b<=0);
    cout << ((a==b)?"Pole kwadratu wynosi: ":"Pole prostokata wynosi: ") << a*b << "\n-------------------------------\n";

    string i;
    string n;
    cout << "Podaj swoje imie: ";
    cin >> i;
    cout << "Podaj swoje nazwisko: ";
    cin >> n;
    cout << "Witaj, " << i << " " << n << "!\n";
    cout << "Twoje inicjaly: " << i[0] << n[0];
    cout << "\nTwoje dane maja: " << (i+n).length() << " liter\n-------------------------------\n";


    int nap;
    float s = 0;
    cout << "Automat: \n 1 - mleko 1.50\n 2 - herbata 2.50\n 3 - kawa 3.50\n";
    do
    {
        cout << "Wybierz napoj: ";
        cin >> nap;
    }
    while(nap <= 0 || nap > 3);
    do
    {
        cout << "Cena do zaplacenia: " << nap-s << ".50\nMonety: 1, 2, 5\n";
        int c;
        cin >> c;
        if(c>0 && c!=3 && c!=4 && c<6)
        {
            s += c;
        }
    }
    while(s <= (nap+0.5));
    cout << "Wydano napoj!\n(dziekujemy za napiwek wysokosci: " << s - nap - 0.5 << ")\n-------------------------------\n";

    float x1;
    float y1;
    float x2;
    float y2;
    cout << "Podaj X pierwszego punktu: ";
    cin >> x1;
    cout << "Podaj Y pierwszego punktu: ";
    cin >> y1;
    cout << "Podaj X drugiego punktu: ";
    cin >> x2;
    cout << "Podaj Y drugiego punktu: ";
    cin >> y2;
    cout << "Wektor [" << x2 - x1 << ", " << y2 - y1 << "]\nDlugosc wektora: " << sqrt(pow(x2 - x1, 2)+pow(y2 - y1, 2)) ;

    return 0;
}
