// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train()
  : nCars(0)
  , countOp(0)
{}

Train::~Train() {}

void Train::addCar(bool /*light*/) {
  ++nCars;
}

int Train::getLength() {
  countOp = nCars * 2;
  return nCars;
}

int Train::getOpCount() const {
  return countOp;
}
