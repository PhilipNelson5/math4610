#ifndef POWER_ITERATION_HPP
#define POWER_ITERATION_HPP

#include "../../hw3/1-vectorNorms/vectorNorms.hpp"
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
T power_iteration(Matrix<T> const& A, unsigned int const& MAX)
{
  std::vector<T> v_k(A.size());

  random_double_fill(std::begin(v_k), std::end(v_k), -100, 100);

  for (auto i = 0u; i < MAX; ++i)
  {
    auto Ab_k = A * v_k;
    auto norm = p_norm(Ab_k, 2);
    auto v_k1 = Ab_k / norm;
  }

  return p_norm(A * v_k, 2);
}

#endif
