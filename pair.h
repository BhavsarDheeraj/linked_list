#include "node.h"

class Pair {
 public:
  Node *head;
  Node *tail;

  Pair(Node *head, Node *tail) {
    this->head = head;
    this->tail = tail;
  }
};