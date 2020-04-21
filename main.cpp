#include <iostream>

using namespace std;
#include <cmath>
#include <stack>

#include "pair.h"

void printLinkedList(Node *head) {
  while (head != NULL) {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << endl;
}

Node *getTail(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  while (head->next != NULL) {
    head = head->next;
  }
  return head;
}

Node *takeInput() {
  Node *head = NULL;
  Node *temp = NULL;
  int data;
  cin >> data;

  while (data != -1) {
    Node *node = new Node(data);

    if (head == NULL) {
      head = node;
      temp = head;
    } else {
      temp->next = node;
      temp = temp->next;
    }

    cin >> data;
  }

  return head;
}

Pair takeInputBetter() {
  Node *head = NULL;
  Node *tail = NULL;
  int data;
  cin >> data;

  while (data != -1) {
    Node *node = new Node(data);

    if (head == NULL) {
      head = node;
      tail = head;
    } else {
      tail->next = node;
      tail = tail->next;
    }

    cin >> data;
  }

  return Pair(head, tail);
}

int lengthLinkedList(Node *head) {
  int count = 0;
  while (head != NULL && head->data != -1) {
    count++;
    head = head->next;
  }
  return count;
}

void printIth(Node *head, int i) {
  int n = 0;
  while (head != NULL) {
    if (i == n) {
      cout << head->data << endl;
      break;
    }
    n++;
    head = head->next;
  }
}

Node *insertFirst(Node *head, int data) {
  Node *node = new Node(data);
  node->next = head;
  head = node;
  return head;
}

Node *insertAtIth(Node *head, int i, int data) {
  int count = 0;
  if (i == 0) {
    return insertFirst(head, data);
  }
  Node *temp = head;
  Node *node = new Node(data);
  while (count < i - 1) {
    temp = temp->next;
    count++;
  }
  node->next = temp->next;
  temp->next = node;
  return head;
}

Node *deleteFirst(Node *head) {
  Node *newHead = head->next;
  delete head;
  return newHead;
}

int deleteLast(Node *head) {
  if (head->next == NULL) {
    int data = head->data;
    delete head;
    head = NULL;
    return data;
  }
  while (head->next->next != NULL) {
    head = head->next;
  }

  int last = head->next->data;
  delete head->next;
  head->next = NULL;
  return last;
}

Node *deleteNode(Node *head, int i) {
  int count = 0;
  if (i == 0) {
    return deleteFirst(head);
  }
  Node *temp = head;
  while (count < i - 1 && temp != NULL) {
    temp = temp->next;
    count++;
  }
  if (temp->next == NULL) {
    return head;
  }
  Node *toDelete = temp->next;
  temp->next = temp->next->next;
  delete toDelete;

  return head;
}

int length(Node *head) {
  if (head == NULL) {
    return 0;
  }
  return 1 + length(head->next);
}

Node *insertRecursive(Node *head, int i, int data) {
  if (head == NULL || i == 0) {
    return insertFirst(head, data);
  }
  head->next = insertRecursive(head->next, i - 1, data);
  return head;
}

Node *deleteNodeRec(Node *head, int i) {
  if (head == NULL) {
    return head;
  }
  if (i == 0) {
    return deleteFirst(head);
  }
  head->next = deleteNodeRec(head->next, i - 1);
  return head;
}

int indexOfNIter(Node *head, int n) {
  Node *temp = head;
  int count = 0;
  while (temp != NULL) {
    if (temp->data == n) {
      return count;
    }
    count++;
    temp = temp->next;
  }
  return -1;
}

Node *appendLinkedList(Node *head, int n) {
  if (head->next == NULL) {
    return head;
  }

  int length = 1;
  Node *last = head;

  while (last->next != NULL) {
    length++;
    last = last->next;
  }

  int count = 0;
  Node *temp = head;
  while (count < length - n - 1) {
    count++;
    temp = temp->next;
  }
  last->next = head;
  Node *newHead = temp->next;
  temp->next = NULL;

  return newHead;
}

Node *removeDuplicate(Node *head) {
  Node *temp = head;
  while (temp->next != NULL) {
    if (temp->data == temp->next->data) {
      temp->next = deleteFirst(temp->next);
    } else {
      temp = temp->next;
    }
  }
  return head;
}

bool check_palindrome(Node *head) {
  stack<int> s;
  Node *tempHead = head;
  while (tempHead != NULL) {
    s.push(tempHead->data);
    tempHead = tempHead->next;
  }
  tempHead = head;
  while (tempHead != NULL) {
    int data = s.top();
    if (tempHead->data != data) {
      return false;
    }
    s.pop();
    tempHead = tempHead->next;
  }

  return true;
}

void printReverse(Node *head) {
  if (head->next == NULL) {
    cout << head->data << ' ';
  }
  printReverse(head->next);
  cout << head->data << ' ';
}

Node *mid(Node *head) {
  if (head->next == NULL) {
    return head;
  }

  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node *deleteMid(Node *head) {
  if (head == NULL) {
    return head;
  }

  if (head->next == NULL || head->next->next == NULL) {
    return deleteFirst(head);
  }

  Node *slow = head;
  Node *prev = slow;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = slow->next;
  delete slow;
  return head;
}

Node *mergeTwoSorted(Node *head1, Node *head2) {
  Node *finalHead, *finalTail;

  if (head1->data <= head2->data) {
    finalTail = head1;
    head1 = head1->next;
  } else {
    finalTail = head2;
    head2 = head2->next;
  }

  finalHead = finalTail;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head2->data) {
      finalTail->next = head1;
      head1 = head1->next;
    } else {
      finalTail->next = head2;
      head2 = head2->next;
    }
    finalTail = finalTail->next;
  }

  if (head1 == NULL) {
    finalTail->next = head2;
  } else if (head2 == NULL) {
    finalTail->next = head1;
  }

  return finalHead;
}

Node *mergeSortLinkedList(Node *head) {
  if (head->next == NULL) {
    return head;
  }

  Node *middle = mid(head);
  Node *sorted2 = mergeSortLinkedList(middle->next);
  middle->next = NULL;
  Node *sorted1 = mergeSortLinkedList(head);

  return mergeTwoSorted(sorted1, sorted2);
}

Node *reverseLLRecursiveBest(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *smallHead = reverseLLRecursiveBest(head->next);
  Node *tail = head->next;
  tail->next = head;
  head->next = NULL;
  return smallHead;
}

Node *k_reverse(Node *head, int k) {
  int count = 1;
  Node *tempHead = head;

  while (count < k && tempHead->next != NULL) {
    tempHead = tempHead->next;
    count++;
  }

  if (tempHead == NULL || tempHead->next == NULL) {
    return reverseLLRecursiveBest(head);
  }

  Node *newHead = k_reverse(tempHead->next, k);
  tempHead->next = NULL;
  Node *temp = reverseLLRecursiveBest(head);
  head->next = newHead;
  return temp;
}

Pair reverseLLRecursiveBetter(Node *head) {
  if (head == NULL || head->next == NULL) {
    return Pair(head, head);
  }

  Pair smallPair = reverseLLRecursiveBetter(head->next);

  smallPair.tail->next = head;
  head->next = NULL;
  return Pair(smallPair.head, head);
}

Node *reverseLLRecursiveNaive(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *smallHead = reverseLLRecursiveNaive(head->next);
  Node *temp = smallHead;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = head;
  head->next = NULL;
  return smallHead;
}

Node *reverseLLIteratively(Node *head) {
  Node *prev = NULL;
  Node *next = NULL;
  Node *curr = head;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

Node *swapNodes(Node *head, int pos1, int pos2) {
  if (pos1 == pos2) {
    return head;
  }
  pos1++;
  pos2++;

  if (pos2 < pos1) {
    swap(pos1, pos2);
  }

  Node *p1 = NULL, *c1 = NULL, *p2 = NULL, *c2 = NULL;
  int count = 1;
  Node *tempHead = head;
  while (count < pos2 && tempHead->next != NULL) {
    if (pos1 == 1) {  // Pos 1 is head
      c1 = head;
    }
    if (count == pos1 - 1) {
      p1 = tempHead;
      c1 = tempHead->next;
    }
    if (count == pos2 - 1) {
      p2 = tempHead;
      c2 = tempHead->next;
    }
    count++;
    tempHead = tempHead->next;
  }
  if (pos1 != 1) {
    p1->next = c2;
  }
  Node *temp = c2->next;
  if (abs(pos2 - pos1) != 1) {
    c2->next = c1->next;
    p2->next = c1;
  } else {
    c2->next = c1;
  }
  c1->next = temp;

  if (pos1 == 1) {
    return c2;
  }

  return head;
}

Node *bubble_sort(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  int count = length(head);

  for (int i = 0; i < count - 1; i++) {
    Node *temp = head;
    for (int j = 0; j < count - 1 - i; j++) {
      if (temp->data > temp->next->data) {
        Node *tempHead = swapNodes(head, j, j + 1);
        if (j == 0) {
          head = tempHead;
        }
      } else {
        temp = temp->next;
      }
    }
  }

  return head;
}

Node *bubble_sort_recursive(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *sortedHead = bubble_sort_recursive(head->next);
  Node *temp = sortedHead;
  Node *temp2 = sortedHead;
  int count = 0;
  while (temp != NULL) {
    if (temp->data > head->data) {
      return insertAtIth(sortedHead, count, head->data);
    }
    count++;
    temp = temp->next;
    if (temp2->next != NULL) {
      temp2 = temp2->next;
    }
  }
  head->next = NULL;
  temp2->next = head;
  return sortedHead;
}

int decimalEquivalentHelper(Node *head, int pos) {
  if (head->next == NULL) {
    return head->data;
  }
  int smallAns = decimalEquivalentHelper(head->next, pos - 1);
  smallAns = (pow(2, pos) * head->data) + smallAns;
  return smallAns;
}

int decimalEquivalentRecursive(Node *head) {
  int pos = lengthLinkedList(head);
  return decimalEquivalentHelper(head, pos);
}

int decimalEquivalentIterative(Node *head) {
  int sum = 0;
  while (head != NULL) {
    sum *= 2;
    sum += head->data;
    head = head->next;
  }
  return sum;
}

Node *sum_of_two_numbers(Node *num1, Node *num2) {
  int carry = 0;
  Node *head = NULL;
  Node *temp = head;

  while (true) {
    int sum1 = 0, sum2 = 0;
    if (num1 != NULL) {
      sum1 = num1->data;
    }
    if (num2 != NULL) {
      sum2 = num2->data;
    }
    int sum = sum1 + sum2 + carry;
    Node *n = new Node(sum % 10);
    if (head == NULL) {
      head = n;
      temp = n;
    } else {
      temp->next = n;
      temp = temp->next;
    }
    carry = sum / 10;
    if (num1 != NULL) {
      num1 = num1->next;
    }
    if (num2 != NULL) {
      num2 = num2->next;
    }
    if (num1 == NULL && num2 == NULL) {
      break;
    }
  }
  if (carry != 0) {
    Node *n = new Node(carry);
    temp->next = n;
  }
  return head;
}

Node *modularNode(Node *head, int k) {
  if (head == NULL || k <= 0) {
    return NULL;
  }

  int pos = 1;
  Node *mod = head;
  while (head != NULL) {
    if (pos % k == 0) {
      mod = head;
    }
    head = head->next;
    pos++;
  }
  return mod;
}

Node *moveLastToFirst(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  head = insertFirst(head, deleteLast(head));
  return head;
}

Node *pairWiseSwap(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = pairWiseSwap(head->next->next);
  Node *swappedHead = swapNodes(head, 0, 1);
  head->next = temp;
  return swappedHead;
}

Node *multiply_two_numbers(Node *head1, Node *head2) {
  if (head1 == NULL) {
    return head1;
  }
  if (head2 == NULL) {
    return head2;
  }
  Node *finalHead = NULL;
  Node *head = NULL;
  Node *newHead = NULL;
  Node *tempHead = NULL;
  Node *newTempHead = NULL;
  head1 = reverseLLRecursiveBest(head1);
  head2 = reverseLLRecursiveBest(head2);

  while (head2 != NULL) {
    if (newTempHead) {
      newTempHead = newTempHead->next;
      tempHead = newTempHead;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;
    while (temp1 != NULL) {
      int sum = temp1->data * temp2->data + carry;
      if (newHead == NULL) {
        newHead = new Node(sum % 10);
        head = newHead;
        finalHead = head;
        carry = sum / 10;
        tempHead = newHead;
        newTempHead = tempHead;
        tempHead = tempHead->next;
      } else {
        if (tempHead) {
          sum = sum + tempHead->data;
          carry = sum / 10;
          sum = sum % 10;
          tempHead->data = sum;
          tempHead = tempHead->next;
        } else {
          carry = sum / 10;
          sum = sum % 10;
          tempHead = new Node(sum);
          head->next = tempHead;
          head = head->next;
          tempHead = tempHead->next;
        }
      }

      temp1 = temp1->next;
    }

    if (carry > 0) {
      tempHead = new Node(carry);
      head->next = tempHead;
      head = head->next;
    }
    head2 = head2->next;
  }

  return reverseLLRecursiveBest(finalHead);
}

Node *sort_abs_with_actual_value(Node *head) {
  Node *temp = head;
  while (temp->next != NULL) {
    if (temp->next->data < temp->data) {
      Node *toDelete = temp->next;
      Node *tempNext = temp->next->next;
      int data = toDelete->data;
      delete toDelete;
      temp->next = tempNext;
      head = insertFirst(head, data);
    } else {
      temp = temp->next;
    }
  }
  return head;
}

Node *delete_alternate(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = head;
  while (temp != NULL && temp->next != NULL) {
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    temp = temp->next;
  }
  return head;
}

int main() {
  Node *head = takeInput();
  head = delete_alternate(head);
  printLinkedList(head);
  return 0;
}