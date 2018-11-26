#ifndef MATRIX_UTILS_HPP
#define MATRIX_UTILS_HPP

#include "random.hpp"
#include <algorithm>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
Matrix<T> identity(unsigned int n)
{
  Matrix<T> I(n);
  for (auto i = 0u; i < n; ++i)
  {
    I[i].reserve(n);
    for (auto j = 0u; j < n; ++j)
    {
      I[i].push_back((i == j) ? 1 : 0);
    }
  }
  return I;
}

template <typename T>
Matrix<T> zeros(unsigned int n)
{
  Matrix<T> Z(n);
  for (auto i = 0u; i < n; ++i)
  {
    Z[i] = std::vector<T>(n, 0);
  }
  return Z;
}

Matrix<double> rand_double_NxM(unsigned int const& n,
                             unsigned int const& m,
                             double const& min,
                             double const& max)
{
  Matrix<double> A(n);
  for (auto i = 0u; i < A.size(); ++i)
  {
    for (auto j = 0u; j < m; ++j)
    {
      A[i].push_back(random_double(min, max));
    }
  }

  return A;
}

#endif
