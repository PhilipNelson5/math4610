#include "../5-matrixOperations/matrixOperations.hpp"
#include "kroneckerProduct.hpp"
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::vector<double>> m1 = {{1, 2}, {3, 4}, {1, 0}},
                                   m2 = {{0, 5, 2}, {6, 7, 3}};
  std::cout << m1 << '\n' << m2 << '\n';

  std::cout << kronecker_product(m1, m2) << '\n';
}
