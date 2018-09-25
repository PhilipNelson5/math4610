#ifndef VECTOR_OPERATIONS_HPP
#define VECTOR_OPERATIONS_HPP

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

#define vector_add_subtract(op)                                                \
  template <typename T, typename U, typename R = decltype(T() op U())>         \
  std::vector<R> operator op(std::vector<T> const& a, std::vector<U> const& b) \
  {                                                                            \
    if (a.size() != b.size())                                                  \
    {                                                                          \
      std::cerr << "ERROR: bad size in vector addition\n";                     \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
                                                                               \
    std::vector<R> result(a.size());                                           \
    for (auto i = 0u; i < a.size(); ++i)                                       \
    {                                                                          \
      result[i] = a[i] op b[i];                                                \
    }                                                                          \
    return result;                                                             \
  }

vector_add_subtract(+) vector_add_subtract(-)

  template <typename T, typename U, typename R = decltype(T() * U())>
  std::vector<R> operator*(U const s, std::vector<T> const& a)
{
  std::vector<R> result(a.size());
  std::transform(
    std::begin(a), std::end(a), std::begin(result), [s](T e) { return e * s; });
  return result;
}

template <typename T, typename U, typename R = decltype(T() * U())>
R inner_product(std::vector<T> const& a, std::vector<U> const& b)
{
  if (a.size() != b.size())
  {
    std::cerr << "ERROR: bad size in vector inner product\n";
    exit(EXIT_FAILURE);
  }

  R product = 0.0;
  for (auto i = 0u; i < a.size(); ++i)
  {
    product += a[i] * b[i];
  }
  return product;
}

template <typename T, typename U, typename R = decltype(T() * U())>

std::vector<R> cross_product(std::vector<T> const& a, std::vector<U> const& b)
{
  if (a.size() != 3 || b.size() != 3)
  {
    std::cerr << "ERROR: bad size in vector cross product\n";
    exit(EXIT_FAILURE);
  }

  return {a[1] * b[2] - a[2] * b[1],
          a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}

template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> const& a)
{
  o << "[ ";
  std::for_each(begin(a), end(a), [&o](T e) {
    o << std::setw(10) << std::setprecision(3) << std::setfill(' ') << e;
  });
  o << " ]" << std::endl;

  return o;
}

#endif
