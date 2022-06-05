#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> tab;
  for(auto i: tab)
    printf("%d", tab[i])

  return 0;
}