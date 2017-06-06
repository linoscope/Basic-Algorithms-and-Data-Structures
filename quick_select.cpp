#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int l, int r) {
  int pivot = v[l];
  int pi = l;
  for(int i = l + 1; i <= r; i++) {
    if( pivot < v[i] )  continue;
    pi++;
    swap(v[i], v[pi]);
  }
  swap(v[l], v[pi]);
  return pi;
}

// get the kth smallest element in v[l], .., v[r]
int quick_select(int k, vector<int> &v, int l, int r) {
  if( r < l ) return -99;	// k is out of bounds
  int p = partition(v, l, r);
  if( p == k - 1 ) return v[p];
  else if ( k - 1 < p ) {
    return quick_select(k, v, l, p - 1);
  } else {
    return quick_select(k, v, p + 1, r);
  }
}

int main() {
  vector<int> v ={3,2,4,1,5,9,};
  cout << quick_select(3, v, 0, v.size() - 1) << "\n";
  cout << quick_select(6, v, 0, v.size() - 1) << "\n";
  cout << quick_select(1, v, 0, v.size() - 1) << "\n";
}
