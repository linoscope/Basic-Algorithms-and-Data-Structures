#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << "==" << x << endl;

class LinkedList {

  struct Node {
    int x;
    Node *next;
  };

private:
  Node *head;

public:
  LinkedList() {
    head = NULL;
  }

  void add(int x) {
    Node* n = new Node();
    n -> x = x;
    n -> next = head;
    head = n;
  }

  int pop() {
    Node* nxt_head = head -> next;
    int ret = head -> x;
    delete head;
    head = nxt_head;
    return ret;
  }

};



int main() {
  ios::sync_with_stdio(false);

  LinkedList l = LinkedList();

  l.add(1);
  l.add(2);
  l.add(3);


  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;
  cout << l.pop() << endl;

  return 0;
}
