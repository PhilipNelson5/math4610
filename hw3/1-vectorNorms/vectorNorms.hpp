#ifndef VECTOR_NORMS_HPP
#define VECTOR_NORMS_HPP

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

/* clang-format off */
template <typename T>
inline T l_pNorm(std::vector<T> const& a, unsigned int const& p)
{
  return std::pow(
      std::accumulate(
        begin(a), end(a), 0.0, [p](T acc, T const e) {
          return acc + std::pow(std::abs(e), p);
        }),
      1.0/p);
}

template <typename T>
inline T l_inf(std::vector<T> const& a)
{
  return std::abs(
      *std::max_element(
        begin(a), end(a), [](T const a, T const b) {
          return std::abs(a) < std::abs(b);
        })
      );
}
/* clang-format on */

#endif
