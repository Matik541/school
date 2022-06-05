#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int times = 10;
int sum = 0;

int main() {
  srand(time(NULL));
  vector<int> numbers = {1};

  for (int i = 0; i < times; i++)
  {
    int a = rand() % 10;
    cout << a << " ";
    numbers.push_back(a);
  }
  for(int number : numbers)
  {
    cout << number << " ";
    sum += number;
  }
  cout << sum << endl;

  return 0;
}