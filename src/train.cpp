// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train()
  : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *node = new Car{light, nullptr, nullptr};
  if (!first) {
    node->next = node;
    node->prev = node;
    first = node;
  } else {
    Car *last = first->prev;
    last->next = node;
    node->prev = last;
    node->next = first;
    first->prev = node;
  }
}

int Train::getLength() {
  if (!first) return 0;
  int length = 0;
  const Car *cur = first;
  bool anyOff = false;
  do {
    if (!cur->light) anyOff = true;
    cur = cur->next;
    ++length;
  } while (cur != first);

  countOp = anyOff ? 2 * length : length * (length + 1);
  return length;
}

int Train::getOpCount() {
  return countOp;
}
