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
  struct TriNode {
    TriNode *ch[26];
    bool isWord;
    TriNode() : isWord(false) {
      for (auto &a : ch) a = NULL;
    }
  } * root;

  void insert(string word) {
    TriNode *p = root;
    for (auto &a : word) {
      int i = a - 'a';
      if (p->ch[i] == NULL) p->ch[i] = new TriNode();
      p = p->ch[i];
    }
    p->isWord = true;
  }

  bool isPrefix(string word) {
    TriNode *p = root;
    for (auto &a : word) {
      int i = a - 'a';
      if (p->ch[i] == NULL) return false;
      p = p->ch[i];
    }
    return true;
  }

  bool isWord(string word) {
    TriNode *p = root;
    for (auto &a : word) {
      int i = a - 'a';
      if (p->ch[i] == NULL) return false;
      p = p->ch[i];
    }
    return p->isWord;
  }

  Solution() { root = new TriNode(); }

  bool isValid(vector<vector<char> > &board, vector<vector<bool>> &visit, int x,
               int y) {
    int m = board.size(), n = board[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) return false;
    return true;
  }

  bool dfs(vector<vector<char> > &board, vector<vector<bool>> &visit,
           set<string> &st, string &s, int x, int y) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    visit[x][y] = true;
    int xx, yy;
    for (int i = 0; i < 4; ++i) {
      xx = x + dx[i];
      yy = y + dy[i];
      if (isValid(board, visit, xx, yy)) {
        s.push_back(board[xx][yy]);
        if (isWord(s)) st.insert(s);
        if (isPrefix(s)) dfs(board, visit, st, s, xx, yy);
        s.pop_back();
      }
    }
    visit[x][y] = false;
  }

  vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
    vector<string> res;
    if (board.empty() || board[0].empty() || words.empty()) return res;
    for (auto &word : words) insert(word);
    int m = board.size(), n = board[0].size();
    vector<vector<bool> > visit(m, vector<bool>(n, false));
    string s;
    set<string> st;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        s.push_back(board[i][j]);
        if (isWord(s)) st.insert(s);
        if (isPrefix(s)) dfs(board, visit, st, s, i, j);
        s.pop_back();
      }
    }
    for (auto &word : st) res.push_back(word);
    return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}