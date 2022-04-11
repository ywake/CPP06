#include "utils.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

bool contains(std::string array[], std::string word)
{
  for (size_t i = 0; i < array->length(); i++) {
    if (array[i] == word) {
      return true;
    }
  }
  return false;
}

void charToOther(char c)
{

  std::cout << "char: '" << c << "'\n"
            << "int: " << static_cast<int>(c) << "\n"
            << std::fixed << std::setprecision(1)
            << "float: " << static_cast<float>(c) << "f\n"
            << "double: " << static_cast<double>(c) << std::endl;
}

void numToChar(int num)
{
  if (std::isprint(num)) {
    std::cout << "char: '" << ASCII[num - ' '] << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
}

void intToOther(int i)
{
  numToChar(i);
  std::cout << "int: " << i << "\n"
            << std::fixed << std::setprecision(1)
            << "float: " << static_cast<float>(i) << "f\n"
            << "double: " << static_cast<double>(i) << std::endl;
}

void floatToOther(float f)
{
  int num = static_cast<int>(f);
  bool isCutWell = f == static_cast<float>(num);

  // numToChar(num);
  if (isCutWell) {
    numToChar(num);
  } else {
    std::cout << "char: impossible\n";
  }

  if (static_cast<float>(std::numeric_limits<int>::min()) <= f &&
      f <= static_cast<float>(std::numeric_limits<int>::max())) {
    std::cout << "int: " << static_cast<int>(f) << "\n";
  } else {
    std::cout << "int: impossible\n";
  }

  if (isCutWell)
    std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << f << "f\n"
            << "double: " << static_cast<double>(f) << std::endl;
}

void doubleToOther(double d)
{
  int num = static_cast<int>(d);
  bool isCutWell = d == static_cast<float>(num);

  // numToChar(num);
  if (isCutWell) {
    numToChar(num);
  } else {
    std::cout << "char: impossible\n";
  }

  if (static_cast<float>(std::numeric_limits<int>::min()) <= d &&
      d <= static_cast<float>(std::numeric_limits<int>::max())) {
    std::cout << "int: " << static_cast<int>(d) << "\n";
  } else {
    std::cout << "int: impossible\n";
  }

  if (isCutWell)
    std::cout << std::fixed << std::setprecision(1);

  if (static_cast<double>(std::numeric_limits<float>::min()) <= d &&
      d <= static_cast<double>(std::numeric_limits<float>::max())) {
    std::cout << "float: " << static_cast<float>(d) << "\n";
  } else {
    std::cout << "float: impossible\n";
  }
  std::cout << "double: " << d << std::endl;
}
