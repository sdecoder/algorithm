
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<string> findItinerary(vector<pair<string, string> > tickets) {
    unordered_set<string> from_set;
    unordered_set<string> to_set;
    unordered_map<string, string> from_to_map;
    const int size = tickets.size();
    for (int i = 0; i < size; ++i) {
      // cout<< "[dbg] first " << tickets[i].first << " second " <<
      // tickets[i].second << endl;
      from_set.insert(tickets[i].first);
      to_set.insert(tickets[i].second);
      from_to_map[tickets[i].first] = tickets[i].second;
    }

    std::unordered_set<string>::iterator it;
    string start;
    for (it = from_set.begin(); it != from_set.end(); it++) {
      const string element = *it;
      if (to_set.find(element) == to_set.end()) {
        start = element;
        break;
      }
    }

    cout << "[dbg] find the start place: " << start << endl;
    std::vector<string> result;
    while (true) {
      result.push_back(start);
      if (from_to_map.find(start) != from_to_map.end()) {
        start = from_to_map[start];
        cout << "[dbg] now go to: " << start << endl;
      } else
        break;
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution s;
  vector<pair<string, string> > tickets;
  pair<string, string> element;
  element = {"JFK","SFO"};
  tickets.push_back(element);

  element = {"JFK","ATL"};
  tickets.push_back(element);
  element = {"SFO","ATL"};
  tickets.push_back(element);
  element = {"ATL","JFK"};
  tickets.push_back(element);

  cout << "[dbg] reach " << __LINE__ << endl;

  std::vector<string> result = s.findItinerary(tickets);

  cout << "[dbg] verifying result: " << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << "[dbg] " << result[i] << endl;
  }

  // tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]

  return 0;
}