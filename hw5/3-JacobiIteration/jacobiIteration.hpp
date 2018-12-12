#ifndef JACOBI_ITERATION_HPP
#define JACOBI_ITERATION_HPP

#include "../../hw1/1-maceps/maceps.hpp"
#include "../../utils/matrixUtils.hpp"
#include <iostream>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
std::vector<T> jacobi_iteration(Matrix<T> A,
                                std::vector<T> const& b,
                                unsigned int const& MAX_ITERATIONS = 1000u)
{
  std::vector<T> zeros(b.size(), 0);
  std::vector<T> x(b.size(), 0);
  static const T macepsT = std::get<1>(maceps<T>());

  for (auto n = 0u; n < MAX_ITERATIONS; ++n)
  {
    auto x_n = zeros;

    for (auto i = 0u; i < A.size(); ++i)
    {
      T sum = 0.0;
      for (auto j = 0u; j < A.size(); ++j)
      {
        if (j == i) continue;
        sum += A[i][j] * x[j];
      }
      x_n[i] = (b[i] - sum) / A[i][i];
    }

    if (allclose(x, x_n, macepsT))
    {
      return x_n;
    }

    x = x_n;
  }

  return x;
}

#endif
