---
title: Matrix Frobenius Norm
layout: default
math: true
---
{% include mathjax.html %}
<a href="https://philipnelson5.github.io/math4610/SoftwareManual"> Table of Contents </a>
# Matrix Frobenius Norm Software Manual

**Routine Name:** frobenius_norm

**Author:** Philip Nelson

**Language:** C++. The code can be compiled using the GNU C++ compiler (gcc). A make file is included to compile an example program

For example,

```
make
```

will produce an executable **./matrixNorms.out** that can be executed.

**Description/Purpose:** This is a template function that can be used to calculate the \\(|| M ||_F\\) of any matrix s.t. \\(|| M ||_F = \sqrt{\sum_{i=1}^m \sum_{j=1}^n |a_{ij}|^2}\\).

**Input:** The routine takes one argument, the matrix

```
@tparam The type of the elements in the matrix
@param  The matrix to take the norm of
```

**Output:** The function returns the Frobenius norm of the matrix

**Usage/Example:**

``` cpp
int main()
{
  std::vector<std::vector<int>> m = { {-3, 5, 7}, {2, 6, 4}, {0, 2, 8} };
  std::cout << m << std::endl;
  std::cout << "Frobenius norm: " << frobenius_norm(m) << std::endl;
}
```

**Output** from the lines above
```
|         -3         5         7 |
|          2         6         4 |
|          0         2         8 |

Frobenius norm: 14.4
```

_explanation of output_:

The first lines are the matrix

The second line is the Frobenius norm of that matrix

**Implementation/Code:** The following is the code for frobenius_norm

``` cpp
template <typename T>
double frobenius_norm(Matrix<T> m)
{
  double elems_squared = 0;

  std::for_each(begin(m), end(m), [&elems_squared](auto const& row) {
    std::for_each(begin(row), end(row), [&elems_squared](auto const& elem) {
      elems_squared += elem * elem;
    });
  });

  return std::sqrt(elems_squared);
}
```

**Last Modified:** October 2018