#include "../1-error/error.hpp"
#include "../2-derivativeApproximation/derivApprox.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
  const auto x = 3.0;
  auto h = 1.0;
  const auto value = pow(x, -.5)/2;
  // const auto f = sqrt;
  const auto newApprox = [](double x, double h){return 1/(sqrt(x+h) + sqrt(x));};
  auto approx = 0.0;
  auto error_abs = 0.0;
  auto error_rel = 0.0;
  // auto approx_0 = 0.0;
  auto h0 = 0.0;

  do
  {
    // approx_0 = approx;
    h0 = h;
    // approx = deriv_approx(f, x, h);
    approx = newApprox(x, h);
    error_abs = absolute_error(approx, value);
    error_rel = relative_error(approx, value);
    std::cout << h << ' ' << std::setprecision(10) << value << ' ' << approx
              << ' ' << error_abs << ' ' << error_rel << '\n';
    h /= 2;
  } while (h < h0);
}
