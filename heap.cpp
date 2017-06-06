#include <algorithm>
#include <iostream>

#define MAX_HEAP_SIZE 128

#define debug(x) std::cout << #x << "==" << x << std::endl;

class Heap {
private:
  int A[MAX_HEAP_SIZE];
  int index = 0;

public:
  void insert(int n) {
    A[++index] = n;
    int i = index;
    while( (i / 2) != 0  and A[ i / 2 ] < A[i] ) {
      std::swap( A[ i / 2 ], A[i] );
      i = i / 2;
    }
  }

  int max() {
    return A[1];
  }

  int pop() {
    int ret = A[1];
    std::swap(A[1], A[index]);
    index--;
    int i = 1;
    while( true ) {
      if( i * 2 > index ) break;	// no child
      if( i * 2 == index ) {		// single child
  	if( A[i * 2] > A[i] ) std::swap(A[i], A[i*2]);
  	break;
      }
      if( A[i*2] <= A[i] and A[ i*2+1 ] <= A[i]) break; // both childs are smaller

      if( A[i*2] > A[i*2+1] ) {
	std::swap(A[i], A[i*2]);
	i = i * 2;
      } else {
	std::swap(A[i], A[i*2+1]);
	i = i * 2 + 1;
      }
    }
    return ret;
  }

};


int main() {
  Heap h = Heap();
  h.insert(5);
  h.insert(1);
  h.insert(2);
  h.insert(9);
  h.insert(8);
  h.insert(10);
  h.insert(2);


  std::cout << h.pop() << "\n";

  std::cout <<  h.max() << "\n";
  return 0;
}
