
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*

[LeetCode] Graph Valid Tree

Problem Description:

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge
is a pair of nodes), write a function to check whether these edges make up a
valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is
this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph
in which any two vertices are connected by exactly one path. In other words, any
connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all
edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear
together inedges.

As suggested by the hint, just check for cycle and connectedness in the graph.
Both of these can be done via DFS.

The code is as follows.*/

class Solution {
 public:
  bool validTree(int n, vector<pair<int, int> >& edges) {
    vector<vector<int> > neighbors(n);
    for (auto e : edges) {
      neighbors[e.first].push_back(e.second);
      neighbors[e.second].push_back(e.first);
    }
    vector<bool> visited(n, false);
    if (hasCycle(neighbors, 0, -1, visited)) return false;
    for (bool v : visited)
      if (!v) return false;
    return true;
  }

 private:
  bool hasCycle(vector<vector<int> >& neighbors, int kid, int parent,
                vector<bool>& visited) {
    if (visited[kid]) return true;
    visited[kid] = true;
    for (auto neigh : neighbors[kid])
      if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
        return true;
    return false;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}