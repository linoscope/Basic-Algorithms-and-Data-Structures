#include <iostream>
#include <vector>

using namespace std;

void print_vec(const vector<int> &a) {
  for(auto x : a) cout << x << " ";
  cout << endl;
}

void merge(vector<int> *v, const vector<int> &lv, const vector<int> &rv) {

  int i = 0, j = 0, k = 0;
  int lsize = lv.size(), rsize = rv.size();

  while( i < lsize and j < rsize ) {
    if( lv[i] < rv[j] ) {
      v->at(k) = lv[i];
      i++;
    } else {
      v->at(k) = rv[j];
      j++;
    }
    k++;
  }

  while( i < lsize ) {
    v->at(k) = lv[i];
    i++;
    k++;
  }

  while( j < rsize ) {
    v->at(k) = rv[j];
    j++;
    k++;
  }

  return;

}

// sort v[l],...,v[r-1];
void merge_sort(vector<int> *v) {

  if( v->size() == 1 ) return;

  int mid = v->size() / 2;

  vector<int> lv(v->begin(), v->begin() + mid);
  vector<int> rv(v->begin() + mid, v->end());

  merge_sort(&lv);
  merge_sort(&rv);

  merge(v, lv, rv);

}


int main() {
  ios::sync_with_stdio(false);

  vector<int> a = {5,1,8,2,4,9,3,3};
  merge_sort(&a);
  print_vec(a);

  vector<int> a2 = {9,8,7,6,5,4,3,2,1};
  merge_sort(&a2);
  print_vec(a2);


  return 0;
}
