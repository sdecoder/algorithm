#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>


using namespace std;

class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges)
    {
        root = vector<int>(n, -1);
        int size = edges.size();
        int count = n;
        for (int i = 0; i < size; ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            int uroot = findRoot(u);
            int vroot = findRoot(v);
            if (uroot != vroot) {
                --count;
                unionSet(uroot, u, vroot, v);
            }
        }

        return count;
    }

private:
    void unionSet(int uroot, int u, int vroot, int v) { root[uroot] = vroot; }
    int findRoot(int u)
    {
        if (root[u] == -1)
            return u;
        root[u] = findRoot(root[u]);
        return root[u];
    }

private:
    vector<int> root;
};

class Solution_dfs {
public:
    int countComponents(int n, vector<pair<int, int> >& edges)
    {
        vector<vector<bool> > map(n, vector<bool>(n, false));
        int size = edges.size();
        for (int i = 0; i < size; ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            map[u][v] = map[v][u] = true;
        }

        vector<bool> visited(n, false);
        int count = 0;
        for (int u = 0; u < n; ++u)
            if (!visited[u]) {
                visited[u] = true;
                dfs(n, u, map, visited);
                ++count;
            }

        return count;
    }

private:
    void dfs(int n, int u, vector<vector<bool> >& map, vector<bool>& visited)
    {
        for (int i = 0; i < n; ++i)
            if (map[u][i] && !visited[i]) {
                visited[i] = true;
                dfs(n, i, map, visited);
            }
    }
};

int main(int argc, char const* argv[]) { return 0; }