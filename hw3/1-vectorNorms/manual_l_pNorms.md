---
title: l_pNorms
layout: default
math: true
---
{% include mathjax.html %}
<a href="https://philipnelson5.github.io/math4610/SoftwareManual"> Table of Contents </a>
# l_pNorms Software Manual

**Routine Name:** l_pNorm

**Author:** Philip Nelson

**Language:** C++. The code can be compiled using the GNU C++ compiler (gcc). A make file is included to compile an example program

For example,

```
make
```

will produce an executable **./norm.out** that can be executed.

**Description/Purpose:** This is a template function that can be used to calculate the \\(l_n\\) norm of any vector where \\(n \in \mathbb{R}\\) s.t. \\(\|\| v \|\|_p = (\|x_1\|^p + \|x_2\|^p + \cdots + \|x_n\|^p)^\frac{1}{p}\\)

**Input:** The function takes two arguments, a vector and the value of p

**Output:** The function returns the specified \\(l_p\\) norm

```
@tparam T The type of the elements in `a`
@tparam P The type of `p`
@param a  The vector
@param p  The `p` of the l_pNorm
```

**Usage/Example:**

``` c++
int main()
{
  std::vector<double> v{3, 4, 1};
  std::cout << "v : " << v << '\n';
  std::cout << "l_1 norm :   " <<  l_pNorm(v, 1.0) << '\n';
  std::cout << "l_2 norm :   " << l_pNorm(v, 2.0) << '\n';
}
```

**Output** from the lines above
```
v : [          3         4         1 ]

l_1 norm :   8
l_2 norm :   5.1
```

_explanation of output_:

The first line is the vector

The second line is the \\(l_1\\) norm of \\(v\\)

The third line is the \\(l_2\\) norm of  \\(v\\)

**Implementation/Code:** The following is the code for `l_pNorm`

``` c++
template <typename T>
inline T l_pNorm(std::vector<T> const& a, P const p)
{
  return std::pow(
      std::accumulate(
        begin(a), end(a), 0.0, [p](T acc, T const e) {
          return acc + std::pow(std::abs(e), p);
        }),
      1.0/p);
}
```

**Last Modified:** September 2018
