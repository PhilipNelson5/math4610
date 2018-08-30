---
title: Machine Epsilon
layout: default
---
<a href="https://philipnelson5.github.io/math4610/SoftwareManual"> Table of Contents </a>
# Math 4610 Fundamentals of Computational Mathematics Maceps Software Manual
This is a template file for 'maceps'

**Routine Name:** 'maceps'

**Author:** Philip Nelson

**Language:** C++. The code can be compiled using the GNU C++ compiler (gcc). A make file is included to compile an example program

For example,

    make

will produce an executable **./maceps.out** that can be executed.

**Description/Purpose:** This routine will compute the precision value for the machine epsilon or the number of digits
in the representation of real numbers for any numeric type. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** The function requires one template parameter, the numeric type you are testing ex. int, long, float, double, long double.

**Output:** This routine returns a tuple containing the precision value for the number of decimal digits that can be represented on the computer being queried and the machine epsilon of the type.

**Usage/Example:**

'''c++
int main()
{
  auto [float_prec, float_eps] = maceps<float>();
  std::cout << "float\n";
  std::cout << "precision:\t" << float_prec << '\n';
  std::cout << "maceps:\t\t" << float_eps << '\n';
  std::cout << "std::numeric:\t" << std::numeric_limits<float>::epsilon()
            << "\n\n";

  auto [double_prec, double_eps] = maceps<double>();
  std::cout << "double\n";
  std::cout << "precision:\t" << double_prec << '\n';
  std::cout << "maceps:\t\t" << double_eps << '\n';
  std::cout << "std::numeric:\t" << std::numeric_limits<double>::epsilon()
            << "\n\n";

  auto [long_double_prec, long_double_eps] = maceps<long double>();
  std::cout << "long double\n";
  std::cout << "precision:\t" << long_double_prec << '\n';
  std::cout << "maceps:\t\t" << long_double_eps << '\n';
  std::cout << "std::numeric:\t" << std::numeric_limits<long double>::epsilon()
            << "\n\n";

  return EXIT_SUCCESS;
}
'''

**Output** from the lines above
'''
float
precision:	24
maceps:		1.19209e-07
std::numeric:	1.19209e-07

double
precision:	53
maceps:		2.22045e-16
std::numeric:	2.22045e-16

long double
precision:	64
maceps:		1.0842e-19
std::numeric:	1.0842e-19

'''

The values labeled precision represent the number of binary digits that define the machine epsilon.
The values labeled maceps are related to the decimal version of the same value.
The values labeled std::numeric are the result of std::numeric\_limits<type>::epsilon, for comparison.

**Implementation/Code:** The following is the code for maceps()

'''c++
template <typename T>
std::tuple<int, T> maceps()
{
  T e = 1;
  T one = 1;
  T half = 0.5;
  int prec = 1;
  while (one + e * half > one)
  {
    e *= half;
    ++prec;
  }

  return std::make_tuple(prec, e);
}
'''

**Last Modified:** August 2018
