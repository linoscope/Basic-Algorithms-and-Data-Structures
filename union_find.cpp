#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class UnionFind {

private:
  vector<int> par;
  vector<int> rank;

  void init(int n)  {
    for (int i = 0; i < n; i++) {
      par[i] = i; rank[i] = 0;
    }
  }

public:
  UnionFind(int size) {
    par.resize(size);
    rank.resize(size);
    init(size);
  }

  int  root(int x) {
    if( par[x] == x ) {
      return x;
    }
    else {
      return par[x] = root(par[x]);
    }
  }

  bool same(int x, int y) { return root(x) == root(y); }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if( x == y) return;
    if( rank[x] < rank[y] ) {  par[x] = y; }
    else {
      par[y] = x;
      if(rank[x] == rank[y]) { rank[x]++; }
    }
  }
};



int main() {
  ios::sync_with_stdio(false);

  UnionFind uf(9);

  uf.unite(0, 1);
  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(3, 4);

  uf.unite(5,6);
  uf.unite(7,8);

  cout << boolalpha;            // print true and false instead of 1 and 0
  cout << uf.same(1,4) << "\n";
  cout << uf.same(1,6) << "\n";

  return 0;
}
