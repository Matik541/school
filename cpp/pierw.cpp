#include <iostream>

using namespace std;

float pierw(float x) {
  // 1) weź a > 0
  // 2) Dopóki |a - x/a| > 0,001 powtarzaj:
  // 2a) a <- (a + x/a)/2
  // 2b) oblicz różnicę a - x/a 
  x = abs(x);
  float a = 1;
  while (abs(a - (x/a)) > 0.001){
    a = (a + x/a)/2;
  }
  return a; 
}