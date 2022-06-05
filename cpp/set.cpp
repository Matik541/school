#include <iostream>
#include <set>
#include <iterator>
#include <string>
using namespace std;

int main()
{
  set<string> s1 = {"Ala", "ma", "kota"};
  set<string>::iterator it;
  for (it = s1.begin(); it != s1.end(); it++)
    cout << *it << " ";
  return 0;
}