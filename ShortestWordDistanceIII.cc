
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

/*Leetcode Shortest Word Distance III
This is a follow up of Shortest Word Distance. The only difference is now word1
could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest
distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the
list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.*/

int shortestWordDistance(std::vector<string> words, string word1,
                         string word2) {
  int p1 = -1, p2 = -1, distance = words.size();
  for (int i = 0; i < words.size(); i++) {
    if (words[i] == word1) {
      p1 = i;
      if (p1 != -1 && p2 != -1) {
        distance = (p1 != p2) ? min(distance, abs(p1 - p2)) : distance;
      }
    }
    if (words[i] == word2) {
      p2 = i;
      if (p1 != -1 && p2 != -1) {
        distance = (p1 != p2) ? min(distance, abs(p1 - p2)) : distance;
      }
    }
  }
  return distance;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}