
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
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string S, vector<string> &L) {
    int l_size = L.size();
    if (l_size <= 0) {
      return vector<int>();
    }

    vector<int> result;
    unordered_map<string, int> word_count;
    int word_size = L[0].size();
    int i, j;

    for (i = 0; i < l_size; ++i) {
      ++word_count[L[i]];
    }

    unordered_map<string, int> counting;

    for (i = 0; i <= (int)S.length() - (l_size * word_size); ++i) {
      counting.clear();
      for (j = 0; j < l_size; ++j) {
        string word = S.substr(i + j * word_size, word_size);
        if (word_count.find(word) != word_count.end()) {
          ++counting[word];
          if (counting[word] > word_count[word]) {
            break;
          }
        } else {
          break;
        }
      }

      if (j == l_size) {
        result.push_back(i);
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[]) { return 0; }