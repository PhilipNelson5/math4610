#include "../../hw3/3-vectorOperations/vectorOperations.hpp"
#include "../../hw3/5-matrixOperations/matrixOperations.hpp"
#include "../../hw5/2-MatrixGenerator/matrixGenerator.hpp"
#include "powerIteration.hpp"
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

int main()
{
  auto A = generate_square_symmetric_diagonally_dominant_matrix(5u);

  auto eigval = power_iteration(A, 1000u);
  std::cout << "A\n" << A << std::endl;
  std::cout << "Largest Eigenvalue\n" << eigval << std::endl;
}
