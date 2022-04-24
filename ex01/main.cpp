#include <cstdlib>
#include <iostream>

typedef struct s_Data {
  int num;
} Data;

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main(void)
{
  Data *data = new Data();
  data->num = 42;

  uintptr_t serialized = serialize(data);
  Data *deserialized = deserialize(serialized);

  std::cout << "origin: " << data << "\n"
            << "serial: " << serialized << "\n"
            << "deserialize: " << deserialized << "\n"
            << "deserialize->num: " << deserialized->num << std::endl;

  delete data;
}
