#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << "==" << x << endl;

bool rec_binary_search(int n, const vector<int> &v, int l, int r) {

  if ( r - l < 1 ) {
    return false;
  }

  int mid = (r + l) / 2;

  if( n == v[mid] ) {
    return true;
  }
  else if( v[mid] < n ) {
    return rec_binary_search( n, v, mid+1, r);
  } else {
    return rec_binary_search( n, v, l, mid);
  }
}

bool binary_search(int n, const vector<int> &v) {

  int l = 0; int r = v.size();	// search v[l],...,v[r-1]

  while( r - l >= 1) {
    int m = (r + l) / 2;	// l + (r-l) / 2 == (r + l) / 2
    if( v[m] == n ) {
      return true;
    } else if( v[m] < n ) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  return false;

}

int main() {

  ios::sync_with_stdio(false);

  bool b;

  vector<int> v = {1,3,8,12,15};

  b = rec_binary_search(8, v, 0, v.size());
  cout << ( b ? "yes" : "no" ) << endl;

  b = binary_search(8, v);
  cout << ( b ? "yes" : "no" ) << endl;

  b = rec_binary_search(15, v, 0, v.size());
  cout << ( b ? "yes" : "no" ) << endl;

  b = binary_search(15, v);
  cout << ( b ? "yes" : "no" ) << endl;

  b = rec_binary_search(14, v, 0, v.size());
  cout << ( b ? "yes" : "no" ) << endl;

  b = binary_search(14, v);
  cout << ( b ? "yes" : "no" ) << endl;


  return 0;

}
