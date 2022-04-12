#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

typedef enum types {
  TYPE_NONE,
  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
} e_types;

#define TYPES(n)                                                               \
  ((std::string[]){"TYPE_NONE", "TYPE_CHAR", "TYPE_INT", "TYPE_FLOAT",         \
                   "TYPE_DOUBLE"}[n])

bool contains(std::string array[], std::string word);

void charToOther(char c);
void intToOther(int i);
void floatToOther(float f);
void doubleToOther(double d);

#endif
