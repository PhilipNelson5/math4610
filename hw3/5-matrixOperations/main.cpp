#include "matrixOperations.hpp"
#include <iostream>
#include <vector>

int main()
{
  Matrix<int> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Matrix<int> m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::cout << m1 << std::endl;
  std::cout << m1 + m1 << std::endl;
  std::cout << m1 - m1 << std::endl;
  std::cout << m2 << std::endl;
  std::cout << "m1\n";
  std::cout << m1 << std::endl;
  std::cout << "transpose m1\n";
  std::cout << transpose(m1) << std::endl;
  std::cout << "m2\n";
  std::cout << m2 << std::endl;
  std::cout << "transpose m2\n";
  std::cout << transpose(m2) << std::endl;
}
