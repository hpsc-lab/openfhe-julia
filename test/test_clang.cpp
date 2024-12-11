#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
  __int128 t = 1234567890;

  std::cout << typeid(__int128).name();

  return 0;
}