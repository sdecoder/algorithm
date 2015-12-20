#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <list>



using namespace std;

/*
210. Course Schedule II My Submissions Question
Total Accepted: 16850 Total Submissions: 82151 Difficulty: Medium
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the
ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it
is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have
finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have
finished both courses 1 and 2. Both courses 1 and 2 should be taken after you
finished course 0. So one correct course order is [0,1,2,3]. Another correct
ordering is[0,2,1,3].

*/

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<list<int> > adj(numCourses, list<int>());
    vector<bool> visited(numCourses, false);
    vector<bool> onstack(numCourses, false);
    vector<int> order;

    for (auto& it : prerequisites) {
      adj[it.second].push_back(it.first);
    }

    for (int i = 0; i < numCourses; ++i) {
      if (visited[i]) continue;
      if (hasCycle(adj, i, visited, onstack, order)) return vector<int>();
    }
    return order;
  }

  bool hasCycle(vector<list<int> >& adj, int v, vector<bool>& visited,
                vector<bool>& onstack, vector<int>& order) {
    visited[v] = true;
    onstack[v] = true;
    for (auto& it : adj[v]) {
      if (!visited[it] && hasCycle(adj, it, visited, onstack, order))
        return true;
      if (onstack[it]) return true;
    }
    order.insert(order.begin(), v);
    onstack[v] = false;
    return false;
  }
};

namespace solution_queue {
vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
  vector<list<int> > adj(numCourses, list<int>());
  vector<int> requisites(numCourses, 0);
  vector<int> order(numCourses, 0);
  queue<int> que;

  for (auto& it : prerequisites) {
    adj[it.second].push_back(it.first);
    requisites[it.first]++;
  }
  for (int i = 0; i < numCourses; i++) {
    if (requisites[i] == 0) {
      que.push(i);
    }
  }
  int len = 0;
  while (!que.empty()) {
    int course = que.front();
    que.pop();
    order[len++] = course;
    for (auto& it : adj[course]) {
      if (!--requisites[it]) {
        que.push(it);
      }
    }
  }
  return len == numCourses ? order : vector<int>();
}
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}