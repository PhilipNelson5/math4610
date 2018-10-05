#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

/**
 * Addition and Subtraction for std::vector<std::vector<T>>
 * used to represent a mathematics vector
 *
 * @tparam T Type of the elements in the first matrix
 * @tparam U Type of the elements in the second matrix
 * @tparam R Type of the elements in the result matrix
 * @param a  The first matrix
 * @param b  The second matrix
 * @return   The result of the addition or subtraction
 */
#define matrix_add_subtract(op)                                                \
  template <typename T, typename U, typename R = decltype(T() + U())>          \
  Matrix<R> operator op(Matrix<T> const& a, Matrix<U> const& b)                \
  {                                                                            \
    if (a.size() != b.size() || a[1].size() != b[0].size())                    \
    {                                                                          \
      std::cerr << "ERROR: bad size in matrix_add_subtract\n";                 \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
                                                                               \
    Matrix<R> result(a.size());                                                \
    for (auto i = 0u; i < a.size(); ++i)                                       \
    {                                                                          \
      result[i].reserve(a[i].size());                                          \
      for (auto j = 0u; j < a[i].size(); ++j)                                  \
      {                                                                        \
        result[i].push_back(a[i][j] op b[i][j]);                               \
      }                                                                        \
    }                                                                          \
                                                                               \
    return result;                                                             \
  }

matrix_add_subtract(+) matrix_add_subtract(-)

  /**
   * A convenient way to print out the contents of a std::vector<std::vector<T>>
   *
   * @tparam T Type of the elements in the matrix
   * @param o  The ostream to put the matrix on
   * @param a  The matrix
   * @return   Return the stream so that the operator can be chained together
   */
  template <typename T>
  std::ostream& operator<<(std::ostream& o, Matrix<T> const& m)
{
  std::for_each(begin(m), end(m), [&o](std::vector<T> row) {
    o << "| ";
    std::for_each(begin(row), end(row), [&o](T e) {
      o << std::setw(10) << std::setprecision(3) << std::setfill(' ') << e;
    });
    o << " |\n";
  });

  return o;
}

#endif
