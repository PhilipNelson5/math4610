#ifndef BISECTION_HPP
#define BISECTION_HPP

#include <cmath>
#include <iostream>
#include <optional>

/**
 * Implementation of the bisection method for root finding
 * on a function f on the interval [a, b]
 *
 * @tparam T  Type of a and b, determines the return type
 * @tparam F  A function of type T(T)
 * @param f   The function to find roots of
 * @param a   The beginning of the interval
 * @param b   The end of the interval
 * @param tol The tolerance
 */
template <typename T, typename F>
std::optional<T> root_finder_bisection(F f, T a, T b, T tol)
{
  if (a > b || f(a) * f(b) >= 0 || tol <= 0)
  {
    return {};
  }

  T p;
  auto n = std::ceil(log2((b - a) / (2 * tol)));

  for (auto i = 0.0; i <= n; ++i)
  {
    p = (a + b) / 2;

    if (f(a) * f(p) < 0) // root on interval [a, p]
    {
      b = p;
    }
    else // root in interval [p, b]
    {
      a = p;
    }
  }

  return (a + b) / 2;
}

#endif