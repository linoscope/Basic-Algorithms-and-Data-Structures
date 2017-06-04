#include <iostream>

using namespace std;

class BinarySearchTree {

  struct Node {
    int data;
    Node* left;
    Node* right;
  };

private:
  Node* root;

  Node* create_leaf(int data) {
    Node* n = new Node;
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
  }

  void insert(int data, Node* node) {
    if( data < node->data  ) {
      if( node->left == NULL ) {
	node->left = create_leaf(data);
      } else {
	insert(data, node->left);
      }
    } else {
      if( node->right == NULL ) {
	node->right = create_leaf(data);
      } else {
	insert(data, node->right);
      }
    }
  }

  void print_preorder(Node* node) {
    if( node == NULL ) {
      cout << "null" << "\n";
      return;
    }
    cout << node->data << "\n";
    print_preorder(node->left);
    print_preorder(node->right);
  }


  bool search(Node* node, int data) {
    if( node == NULL ) return false;
    if( node->data == data ) return true;
    if( data < node->data ) {
      return search(node->left, data);
    } else {
      return search(node->right, data);
    }
  }

public:

  void insert(int data) {
    if( root == NULL ) {
      root = create_leaf(data);
    } else {
      insert( data, root );
    }
  }

  void print_preorder() {
    print_preorder(root);
  }

  bool search(int data) {
    return search(root, data);
  }


};

int main() {
  BinarySearchTree bst = BinarySearchTree();
  bst.insert(5);
  bst.insert(3);
  bst.insert(8);
  bst.insert(4);
  bst.insert(7);
  bst.insert(2);
  bst.insert(1);
  bst.insert(9);
  bst.print_preorder();
}
