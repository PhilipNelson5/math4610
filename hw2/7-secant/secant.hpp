#ifndef SECANT_HPP
#define SECANT_HPP

#include <cmath>

/**
 * Implementation of the secant method for root finding
 * on a function f with initial guesses x0 and x1
 *
 * @tparam T       The type of x0 and tolerance
 * @tparam F       A function of type T(T)
 * @param x0       The first initial guess
 * @param x1       The second initial guess
 * @param tol      The Tolerance
 * @param MAX_ITER The maximum iterations
 */
template <typename T, typename F>
T root_finder_secant(F f, T x0, T x1, T tol, const int MAX_ITER = 100)
{
  T x2, fx1;
  for (auto i = 0; i < MAX_ITER; ++i)
  {
    fx1 = f(x1);
    x2 = x1 - fx1 * (x1 - x0) / (fx1 - f(x0));
    if (std::abs(x1 - x0) < tol * std::abs(x1))
    {
      return x2;
    }
    x0 = x1;
    x1 = x2;
  }
  return x1;
}

#endif
