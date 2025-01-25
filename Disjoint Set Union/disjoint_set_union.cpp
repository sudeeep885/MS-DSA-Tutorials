#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> parent, rank, size;

 public:
  // constructor to initalize all arrays we need to maintain for union fn
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    size.resize(n + 1, 0);
    parent.resize(n + 1);

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

    // if ancestors are same then node u & v belongs to the same component
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

    // if ancestors are same then node u & v belongs to the same component
    if (pu == pv) return;

    if (size[pu] < size[pv]) {
      parent[pu] = pv;
    } else {
      parent[pv] = pu;
      size[pu]++;
    }
  }
};

// writting main() fn just for user-manual thing...
int main() {
  // define the disjoint set data structure with 10 nodes
  DisjointSet ds(10);

  // this operation is performed when an edge is added in the graph over which
  // we are maintaining DSU between vertex 1 and vertex 2.
  ds.union_by_rank(1, 2);

  // similar to rank we just use size array in this fn
  ds.union_by_size(1, 2);

  return 0;
}