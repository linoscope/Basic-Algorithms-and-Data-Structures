#include <string>
#include <iostream>

#define TABLE_SIZE 128


class HashMap {

  struct Node {
    std::string key;
    int value;
    Node* next;
    Node (std::string key, int value) {
      this->key = key;
      this->value = value;
      this->next = NULL;
    }
  };

private:
  Node* table[TABLE_SIZE];

  void insert(Node* &head, std::string key, int value) {
    if( head == NULL ) {
      head = new Node(key, value);
      return;
    }
    Node* new_node = new Node(key, value);
    new_node->next = head;
    head = new_node;
  }

  int get(Node* head, std::string key) {
    if( head == NULL ) return 0; // initial value is 0
    if( head->key == key ) return head->value;
    return get(head->next, key);
  }

  int hash(std::string str) {
    int sum = 0;
    for(char c : str) {
      sum += c;
    }
    return sum % TABLE_SIZE;
  }


public:

  void put(std::string key, int value) {
    int index = hash(key);
    insert( table[index], key, value);
  }

  int get(std::string key) {
    int index = hash(key);
    return get( table[index], key);
  }



};


int main() {
  HashMap hm = HashMap();
  hm.put("hoge", 99);
  hm.put("hgoe", 22);

  std::cout << hm.get("hoge") << "\n";
  std::cout << hm.get("hgoe") << "\n";
  return 0;
}
