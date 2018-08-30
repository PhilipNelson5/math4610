#include "maceps.hpp"
#include <iostream>
#include <limits>

int main()
{
  std::cout << "int\n";
  std::cout << "precision:\t" << maceps<int>() << '\n';
  std::cout << "std::numeric:\t" << std::numeric_limits<int>::epsilon()
            << "\n\n";

  std::cout << "long\n";
  std::cout << "precision:\t" << maceps<long>() << '\n';
  std::cout << "std::numeric:\t" << std::numeric_limits<long>::epsilon()
            << "\n\n";

  std::cout << "float\n";
  std::cout << "precision:\t" << maceps<float>() << std::endl;
  std::cout << "std::numeric:\t" << std::numeric_limits<float>::epsilon()
            << "\n\n";

  std::cout << "double\n";
  std::cout << "precision:\t" << maceps<double>() << std::endl;
  std::cout << "std::numeric:\t" << std::numeric_limits<double>::epsilon()
            << "\n\n";

  std::cout << "long double\n";
  std::cout << "precision:\t" << maceps<long double>() << std::endl;
  std::cout << "std::numeric:\t" << std::numeric_limits<long double>::epsilon()
            << "\n\n";

  return EXIT_SUCCESS;
}
