// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train()
  : first(nullptr)
  , countOp(0)
{}

Train::~Train() {
  if (!first) return;
  Car* cur = first->next;
  while (cur != first) {
    Car* tmp = cur;
    cur = cur->next;
    delete tmp;
  }
  delete first;
}

void Train::addCar(bool light) {
  Car* car = new Car;
  car->light = light;
  if (!first) {
    car->next = car;
    car->prev = car;
    first = car;
  } else {
    Car* last = first->prev;
    last->next = car;
    car->prev = last;
    car->next = first;
    first->prev = car;
  }
}

int Train::getLength() {
  if (!first) {
    countOp = 0;
    return 0;
  }

  int length = 1;
  Car* cur = first->next;
  while (cur != first) {
    ++length;
    cur = cur->next;
  }

  countOp = length * 2;
  return length;
}

int Train::getOpCount() const {
  return countOp;
}
