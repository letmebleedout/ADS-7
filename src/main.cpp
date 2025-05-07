// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  Train train;
  for (int i = 0; i < 10; ++i) {
    train.addCar(i % 2 == 0);
  }
  std::cout << "Length: " << train.getLength() << std::endl;
  std::cout << "Operations: " << train.getOpCount() << std::endl;
  return 0;
}
