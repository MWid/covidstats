#include "mylib.h"
#include <iostream>

using namespace std;

int main() {
  auto x = 5;
  cout << x << "! = " << mylib::factorial(x) << endl;
}
