#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << "==" << x << endl;


class SortedLinkedList {

  struct Node {
    int val;
    Node *next;
  };

private:
  Node *head;

public:
  SortedLinkedList() {
    head = NULL;
  }

  void add(int x) {

    Node* new_node = new Node();
    new_node->val  = x;

    if( head == NULL or head->val >= x ) {
      new_node->next = head;
      head = new_node;
      return;
    }

    Node* tmp = head;
    while( tmp->next != NULL and tmp->next->val < x ) {
      tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;


  }

  int pop() {
    Node* nxt_head = head -> next;
    int ret = head -> val;
    delete head;
    head = nxt_head;
    return ret;
  }

};


int main() {
  ios::sync_with_stdio(false);

  SortedLinkedList l = SortedLinkedList();

  l.add(5);
  l.add(2);
  l.add(3);
  l.add(9);
  l.add(1);
  l.add(4);
  l.add(100);
  l.add(2);
  l.add(12);
  l.add(9);
  l.add(1);
  l.add(4);


  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;


  return 0;
}
