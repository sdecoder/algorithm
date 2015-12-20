#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x){};
};

class Solution {
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) return NULL;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
    queue<UndirectedGraphNode *> visit;
    visit.push(node);
    UndirectedGraphNode *nodeCopy = new UndirectedGraphNode(node->label);
    nodeMap[node] = nodeCopy;
    while (visit.size() > 0) {
      UndirectedGraphNode *cur = visit.front();
      visit.pop();
      for (int i = 0; i < cur->neighbors.size(); ++i) {
        UndirectedGraphNode *neighb = cur->neighbors[i];
        if (nodeMap.find(neighb) == nodeMap.end()) {
          // no copy of neighbor node yet. create one and associate with the
          // copy of cur
          UndirectedGraphNode *neighbCopy =
              new UndirectedGraphNode(neighb->label);
          nodeMap[cur]->neighbors.push_back(neighbCopy);
          nodeMap[neighb] = neighbCopy;
          visit.push(neighb);
        } else {
          // already a copy there. Associate it with the copy of cur
          nodeMap[cur]->neighbors.push_back(nodeMap[neighb]);
        }
      }
    }

    return nodeCopy;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}