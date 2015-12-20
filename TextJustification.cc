
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
 private:
  string handle_normal(vector<string> &word, int L, int wordL) {
    string answer;
    if (word.size() == 1) {
      answer += word[0];
      for (int i = 0; i < L - wordL; i++) {
        answer += " ";
      }
      return answer;
    }
    int d = (L - wordL) / (word.size() - 1);
    int r = (L - wordL) % (word.size() - 1);
    answer = word[0];
    for (int i = 1; i < word.size(); i++) {
      for (int j = 0; j < d; j++) {
        answer += " ";
      }
      if (r > 0) {
        answer += " ";
        r--;
      }
      answer += word[i];
    }
    return answer;
  }

  string handle_end(vector<string> &word, int L, int count) {
    string answer;
    answer = word[0];
    for (int i = 1; i < word.size(); i++) {
      answer += " " + word[i];
    }
    for (int i = 0; i < L - count; i++) {
      answer += " ";
    }
    return answer;
  }

 public:
  vector<string> fullJustify(vector<string> &words, int L) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> ans;
    vector<string> selWord;
    int count = -1, wordL = 0;
    for (vector<string>::iterator iter = words.begin(); iter != words.end();
         iter++) {
      if (count + iter->length() + 1 > L) {
        ans.push_back(handle_normal(selWord, L, wordL));
        selWord.clear();
        count = -1;
        wordL = 0;
      }
      count += 1 + iter->length();
      wordL += iter->length();
      selWord.push_back(*iter);
    }
    ans.push_back(handle_end(selWord, L, count));
    return ans;
  }
};

namespace solution2 {
class Solution {
 public:
   vector<string> fullJustify(vector<string> &words, int L) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    vector<string> res;
    int len = words.size(), i = 0;
    while (i < len) {
      // if(words[i].size() == 0){i++; continue;}
      int rowlen = 0, j = i;
      while (j < len && rowlen + words[j].size() <= L)
         rowlen += (words[j++].size() + 1);
      // j-i是该行放入单词的数目
      if (j - i == 1) {  //处理放入一个单词的特殊情况
         res.push_back(words[i]);
         addSpace(res.back(), L - words[i].size());
         i = j;
        continue;
      }
      // charaLen是当前行字母总长度
      int charaLen = rowlen - (j - i);
      //平均每个单词后的空格,j < len 表示不是最后一行
      int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
      //多余的空格
      int leftSpace =
          j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i - 1);
      string tmp;
      for (int k = i; k < j - 1; k++) {
         tmp += words[k];
         addSpace(tmp, meanSpace);
         if (j < len && leftSpace > 0) {
          tmp.push_back(' ');
          leftSpace--;
           
        }
      }
      tmp += words[j - 1];                          //放入最后一个单词
      if (leftSpace > 0) addSpace(tmp, leftSpace);  //对最后一行
      res.push_back(tmp);
      i = j;
    }
    return res;
     
  }

   void addSpace(string &s, int count)
 {
  for(int i = 1; i <= count; i++)
s.push_back(' ');
 }
};
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}