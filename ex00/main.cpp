#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

#include "utils.hpp"

e_types detectTheType(std::string str)
{
  std::string pseudoFloat[] = {"-inff", "+inff", "nanf"};
  std::string pseudoDouble[] = {"-inf", "+inf", "nan"};
  bool hasSign = false;

  if (str[0] == '+' || str[0] == '-')
    hasSign = true;

  if (str[0] == '\'' && str.length() == 3 && str[2] == '\'')
    return TYPE_CHAR;

  else if (contains(pseudoFloat, str))
    return TYPE_FLOAT;

  else if (contains(pseudoDouble, str))
    return TYPE_DOUBLE;

  else if (std::isdigit(str[hasSign])) {
    size_t pos = str.find_first_of('.', hasSign);
    if (pos == str.find_last_of('.')) {
      if (pos == std::string::npos)
        return TYPE_INT;

      if (str.at(str.length() - 1) == 'f')
        return TYPE_FLOAT;

      return TYPE_DOUBLE;
    }
  }

  return TYPE_NONE;
}

int main(int argc, char const *argv[])
{
  if (argc != 2 || argv[1][0] == '\0')
    return (1);

  e_types type = detectTheType(argv[1]);
  // std::cout << TYPES(type) << std::endl;

  switch (type) {
  case TYPE_CHAR:
    charToOther(argv[1][1]);
    break;
  case TYPE_INT:
    intToOther(std::strtol(argv[1], NULL, 10));
    break;
  case TYPE_FLOAT:
    floatToOther(std::strtof(argv[1], NULL));
    break;
  case TYPE_DOUBLE:
    doubleToOther(std::strtod(argv[1], NULL));
    break;
  case TYPE_NONE:
    break;
  }
  return 0;
}
