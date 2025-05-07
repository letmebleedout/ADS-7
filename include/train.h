// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
  private:
    int nCars;
    int countOp;

  public:
    Train();
    ~Train();

    void addCar(bool light);

    int getLength();

    int getOpCount() const;
};

#endif  // INCLUDE_TRAIN_H_
