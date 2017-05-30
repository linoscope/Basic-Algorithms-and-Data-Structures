#include <iostream>
#include <vector>

using namespace std;

void print_vec(const vector<int> &a) {
  for(auto x : a) cout << x << " ";
  cout << endl;
}

int partition(vector<int> *v, int l, int r) {

  int pivot = l;

  int k = l;
  for(int i = l+1; i < r; i++) {
    if( v->at(i) < v->at(pivot) ) {
      k++;
      swap( v->at(k), v->at(i));
    }
  }

  swap(v->at(pivot), v->at(k));

  return k;
}

void quick_sort(vector<int> *v, int l, int r) {
  if( r - l <= 1 ) return;
  int p = partition(v, l, r);
  quick_sort(v, l, p);
  quick_sort(v, p+1, r);
}

int main() {
  ios::sync_with_stdio(false);

  vector<int> v1 = {12,3,5,11,2,1,9};
  quick_sort(&v1, 0, v1.size());
  print_vec(v1);

  vector<int> v2 = {9,8,7,6,5,4,3,2,1};
  quick_sort(&v2, 0, v2.size());
  print_vec(v2);

  return 0;
}
