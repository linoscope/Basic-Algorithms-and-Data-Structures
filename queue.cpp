#include<iostream>

template <typename T>
class Queue {
  struct Node {
    T val;
    Node* next;
  };

private:
  Node* first;
  Node* last;

public:
  // Add to last
  void add(T x) {
    Node* new_node = new Node;
    new_node->val = x;
    new_node->next = NULL;
    if( last == NULL ) {
      first = new_node;
      last  = new_node;
    } else {
      last->next = new_node;
      last = new_node;
    }
  }

  T remove() {
    Node* new_first = first->next;
    T data = first->val;
    delete first;
    first = new_first;
    if( first == NULL ) last = NULL;
    return data;
  }

  T peek() {
    return first->val;
  }

  bool is_empty() {
    return (first == NULL);
  }

};


int main() {
  Queue<int> q;
  q.add(1);
  q.add(2);
  q.add(3);
  std::cout << q.remove() << std::endl;
  std::cout << q.remove() << std::endl;
  q.add(4);
  q.add(5);
  std::cout << q.remove() << std::endl;
  std::cout << q.remove() << std::endl;
  std::cout << q.remove() << std::endl;

  return 0;
}
