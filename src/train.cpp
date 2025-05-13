// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* element = new Car{light, nullptr, nullptr};

  if (first == nullptr) {
    element->next = element;
    element->prev = element;
    first = element;
    return;
  }

  Car* tail = first->prev;
  tail->next = element;
  element->prev = tail;
  element->next = first;
  first->prev = element;
}

int Train::getLength() {
  if (first == nullptr) {
    countOp = 0;
    return 0;
  }

  int size = 1;
  const Car* current = first->next;
  bool hasLightOff = !first->light;

  while (current != first) {
    if (!current->light) hasLightOff = true;
    ++size;
    current = current->next;
  }

  countOp = hasLightOff ? size * 2 : size * (size + 1);
  return size;
}

int Train::getOpCount() {
  return countOp;
}
