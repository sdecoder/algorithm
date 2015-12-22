
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
[LeetCode] Alien Dictionary

Problem Description:

There is a new alien language which uses the latin alphabet. However, the order
among letters are unknown to you. You receive a list of words from the
dictionary, wherewords are sorted lexicographically by the rules of this new
language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:

You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
Well, this problem is not that easy. First you may need some clarifications
about the problem itself. If you do, you may refer to this post for a nice
example which illustrates the purpose of this problem.

Moreover, you need to understand graph representation, graph traversal and
specifically, topological sort, which are all needed to solve this problem
cleanly.

DFS

Fortunately, jaewoo posts a nice solution in this post, whose code is rewritten
as follows by decomposing the code into two parts:

make_graph: Build the graph as a list of adjacency lists;
toposort and acyclic: Traverse the graph in DFS manner to check for cycle and
generate the topological sort.*/

class Solution {
 public:
  string alienOrder(vector<string>& words) {
    if (words.size() == 1) return words[0];
    graph g = make_graph(words);
    return toposort(g);
  }

 private:
  typedef unordered_map<char, unordered_set<char> > graph;

  graph make_graph(vector<string>& words) {
    graph g;
    int n = words.size();
    for (int i = 1; i < n; i++) {
      bool found = false;
      string word1 = words[i - 1], word2 = words[i];
      int m = word1.length(), n = word2.length(), l = max(m, n);
      for (int j = 0; j < l; j++) {
        if (j < m && g.find(word1[j]) == g.end())
          g[word1[j]] = unordered_set<char>();
        if (j < n && g.find(word2[j]) == g.end())
          g[word2[j]] = unordered_set<char>();
        if (j < m && j < n && word1[j] != word2[j] && !found) {
          g[word1[j]].insert(word2[j]);
          found = true;
        }
      }
    }
    return g;
  }

  string toposort(graph& g) {
    vector<bool> path(256, false), visited(256, false);
    string topo;
    for (auto adj : g)
      if (!acyclic(g, path, visited, topo, adj.first)) return "";
    reverse(topo.begin(), topo.end());
    return topo;
  }

  bool acyclic(graph& g, vector<bool>& path, vector<bool>& visited,
               string& topo, char node) {
    if (path[node]) return false;
    if (visited[node]) return true;
    path[node] = visited[node] = true;
    for (auto neigh : g[node])
      if (!acyclic(g, path, visited, topo, neigh)) return false;
    path[node] = false;
    topo += node;
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }