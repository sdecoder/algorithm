/*
Word Ladder II My Submissions Question
Total Accepted: 36163 Total Submissions: 269943 Difficulty: Hard
Given two words (beginWord and endWord), and a dictionary's word list, find all
shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters*/

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
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  std::vector<std::vector<std::string> > findLadders(
      std::string start, std::string end,
      std::unordered_set<std::string>& dict) {

    std::vector<std::vector<std::string> > result;
    std::vector<std::string> entry;

    entry.push_back(start);
    Find(start, end, dict, 0, result, entry);

    return result;
  }

 private:
  void Find(std::string& start, const std::string& end,
            const std::unordered_set<std::string>& dict,
            size_t positionToChange,
            std::vector<std::vector<std::string> >& result,
            std::vector<std::string>& entry) {
    //如果长度已经等于当前结果中的长度，再找出来肯定就
    //超过了，终止处理
    if (!result.empty() && entry.size() == result[0].size()) {
      return;
    }

    for (size_t pos = positionToChange; pos < start.size(); ++pos) {
      char beforeChange = ' ';
      for (int i = 'a'; i <= 'z'; ++i) {
        //防止同字母替换
        if (start[pos] == i) {
          continue;
        }
        beforeChange = start[pos];
        start[pos] = i;

        //用std::find的话
        /*
         if(std::find(entry.begin(), entry.end(), start) != entry.end())
         {
              start[pos] = beforeChange;
              continue;
         }
         */
        //如果单词已经用过的情况
        if (!used_.empty() && used_.count(start) != 0) {
          start[pos] = beforeChange;
          continue;
        }

        if (start == end) {
          entry.push_back(start);

          //只需要保存最短的序列
          if (!result.empty()) {
            if (entry.size() < result[0].size()) {
              result.clear();
              result.push_back(entry);
            } else if (entry.size() == result[0].size()) {
              result.push_back(entry);
            }
          } else {
            result.push_back(entry);
          }
          //完成一个序列，把前面加入的end弹出
          entry.pop_back();
          return;
        }

        if (dict.find(start) != dict.end()) {
          entry.push_back(start);
          used_.insert(start);
          Find(start, end, dict, 0, result, entry);
          used_.erase(*entry.rbegin());
          entry.pop_back();

          if (!entry.empty()) {
            start = *entry.rbegin();
          } else {
            start[pos] = beforeChange;
          }
        } else {
          start[pos] = beforeChange;
        }
      }
    }

        return;
    }
    
    std::unordered_set<std::string> used_;
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}