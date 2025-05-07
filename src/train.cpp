// Copyright 2021 NNTU-CS
Train::Train()
  : first(nullptr)
  , size(0)
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
  ++size;
}

int Train::getLength() {
  countOp = size * 2;
  return size;
}

int Train::getOpCount() const {
  return countOp;
}
