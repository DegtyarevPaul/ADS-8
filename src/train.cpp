// Copyright 2021 NNTU-CS
#include "train.h"
Train::Cage* Train::create(bool light) {
  Cage* ptr = new Cage;
  ptr->light = light;
  return ptr;
}

Train()::first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
  if (!first) {
    first = create(light);
    last = first;
    first->next = first;
    first->prev = first;
  } else {
      Cage* ptr = create(light);
      ptr->next = first;
      ptr->prev = last;
      last->next = ptr;
      last = ptr;
      first->prev = ptr;
  }
}
int Train::getLength() {
  first->light = true;
  int ln = 0;
  Cage* temp = first;
  int tempn = 0;
  while (true) {
    countOp++;
    tempn++;
    temp = temp->next;
    if (temp->light) {
      int tmp = tempn;
      temp->light = false;
        for (int i = tempn; tempn > 0; tempn--, countOp++) {
          temp = temp->prev;
        }
      if (!temp -> light) {
        ln = tmp;
        break;
      }
    }
  }
  return ln;
}

int Train::getOpCount() {
  return countOp;
}
