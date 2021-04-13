#include <stdint.h>
#include <iostream>
using namespace std;

int main()
{
  uint32_t num1 = UINT32_MAX;
  uint32_t num2 = 1;

  uint32_t total = num1 + num2;

  cout << " Num1: " << num1;
  cout << "\n Num2: " << num2;
  cout << "\nTotal: " << total;
  cout << "\n";
  
  return 0;
}
