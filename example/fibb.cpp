#include <iostream>
#include <valgrind/bitflips.h>

int main() {
  long long a = 0, b = 1, temp;
  int n = 50;

  VALGRIND_BITFLIPS_MEM_ON(&a, 1, 1, BITFLIPS_LONG, BITFLIPS_ROW_MAJOR);
  VALGRIND_BITFLIPS_MEM_ON(&b, 1, 1, BITFLIPS_LONG, BITFLIPS_ROW_MAJOR);

  for (int i = 0; i < n; i++) {
    temp = a + b;
    a = b;
    b = temp;
  }

  std::cout << a << "\n";

  VALGRIND_BITFLIPS_MEM_OFF(&a);
  VALGRIND_BITFLIPS_MEM_OFF(&b);
}
