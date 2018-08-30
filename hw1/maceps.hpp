#ifndef MACEPS_HPP
#define MACEPS_HPP

template <typename T>
T maceps()
{
  T e = .5;
  T one = 1;
  T half = 0.5;

  while (one + e * half > one)
  {
    e *= half;
  }

  return e;
}

#endif
