#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
  std::srand(time(NULL));
  switch (std::rand() % 3) {
  case 0:
    return new A();
  case 1:
    return new B();
  }
  return new C();
}

void identify(Base *p)
{
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A";
  if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B";
  if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C";
  std::cout << std::endl;
}
void identify(Base &p)
{
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A";
  } catch (const std::exception &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B";
  } catch (const std::exception &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C";
  } catch (const std::exception &e) {
  }
  std::cout << std::endl;
}

int main(void)
{
  Base *base = generate();
  identify(base);
  identify(*base);
}
