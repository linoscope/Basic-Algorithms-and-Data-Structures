#include <iostream>

class DoublyLinkedList {

  struct Node {
    int val;
    Node* next;
    Node* prev;
  };

private:
  Node* head;
  Node* tail;

public:
  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void append_to_tail(int x) {
    Node* new_node = new Node;
    new_node->val  = x;
    new_node->next = NULL;
    if( tail == NULL ) {
      tail = new_node;
      head = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void append_to_head(int x) {
    Node* new_node = new Node;
    new_node->val = x;
    new_node->next = head;
    head = new_node;
    if( tail == NULL ) tail = new_node;
  }

  int pop_head() {
    Node* nxt_head = head->next;
    int ret = head->val;
    delete head;
    head = nxt_head;
    return ret;
  }

  int pop_tail() {
    Node* nxt_head = head->next;
    int ret = head->val;
    delete head;
    head = nxt_head;
    return ret;
  }


};


int main() {

  DoublyLinkedList dl = DoublyLinkedList();

  dl.append_to_head(1);
  dl.append_to_head(2);
  dl.append_to_tail(100);
  dl.append_to_tail(200);

  std::cout << dl.pop_head() << std::endl;
  std::cout << dl.pop_head() << std::endl;
  std::cout << dl.pop_head() << std::endl;
  std::cout << dl.pop_head() << std::endl;

  return 0;

}
