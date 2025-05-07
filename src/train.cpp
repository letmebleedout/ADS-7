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
  Car* car = new Car{ light, nullptr, nullptr };
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
  if (!first) return 0;

  countOp = 0;
  Car* cur = first;
  do {
    cur->light = false;
    cur = cur->next;
    ++countOp;
  } while (cur != first);

  first->light = true;

  int length = 0;
  cur = first->next;
  ++countOp;
  ++length;
  while (!cur->light) {
    cur = cur->next;
    ++countOp;
    ++length;
  }

  return length;
}

int Train::getOpCount() const {
  return countOp;
}
