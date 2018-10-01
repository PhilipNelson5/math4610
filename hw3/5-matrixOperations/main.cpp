#include "matrixOperations.hpp"
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::cout << m1 + m1 << std::endl;
  std::cout << m1 - m1 << std::endl;
}
