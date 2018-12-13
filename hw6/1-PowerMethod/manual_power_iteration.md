---
title: Power Iteration
layout: default
math: true
---
{% include mathjax.html %}
<a href="https://philipnelson5.github.io/math4610/SoftwareManual"> Table of Contents </a>
# Power Iteration Software Manual

**Routine Name:** power-iteration

**Author:** Philip Nelson

**Language:** C++. The code can be compiled using the GNU C++ compiler (gcc). A make file is included to compile an example program

For example,

```
make
```

will produce an executable **./powerIteration.out** that can be executed.

**Description/Purpose:** This code calculates the largest Eigenvalue of a `N`x`N` matrix by using the power method.

**Input:** The code takes an NxN matrix, A, and the number of iterations to run the method for.

**Output:** The larges eigenvalue of A. 

**Usage/Example:**

``` cpp
int main()
{
  auto A = generate_square_symmetric_diagonally_dominant_matrix(5u);

  auto eigval = power_iteration(A, 1000u);
  std::cout << "A\n" << A << std::endl;
  std::cout << "Largest Eigenvalue\n" << eigval << std::endl;
}
```

**Output** from the lines above
```
A
|      -13.6      -4.6     -5.85      4.77     -3.93 |
|       -4.6     -7.73     -7.01    -0.677       2.8 |
|      -5.85     -7.01      7.82     -3.39      7.74 |
|       4.77    -0.677     -3.39      8.94      6.12 |
|      -3.93       2.8      7.74      6.12      10.1 |

Largest Eigenvalue
918
```

_explanation of output_:

First the matrix A is displayed, then the larges eigenvalue found by the power method.

**Implementation/Code:** The following is the code for power_method

``` cpp
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
```

**Last Modified:** December 2018
