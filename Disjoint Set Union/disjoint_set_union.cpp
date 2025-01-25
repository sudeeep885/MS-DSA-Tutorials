#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
  vector<int> parent, rank, size;

 public:
  // constructor to initialize all arrays we need to maintain for union fn
  DisjointSet(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1) {
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  // find ancestor fn with path compression optimization
  int find_ancestor(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find_ancestor(parent[node]);
  }

  // union by rank fn
  void union_by_rank(int u, int v) {
    int pu = find_ancestor(u);
    int pv = find_ancestor(v);

    if (pu == pv) return;

    if (rank[pu] < rank[pv]) {
      parent[pu] = pv;
    } else if (rank[pv] < rank[pu]) {
      parent[pv] = pu;
    } else {
      parent[pv] = pu;
      rank[pu]++;
    }
  }

  // union by size fn
  void union_by_size(int u, int v) {
    int pu = find_ancestor(u);
    int pv = find_ancestor(v);

    if (pu == pv) return;

    if (size[pu] < size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    } else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};

int main() {
  DisjointSet ds(10);

  ds.union_by_rank(1, 2);
  ds.union_by_size(1, 2);

  return 0;
}