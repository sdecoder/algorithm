#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  string rtrim(string input) {
    char buffer[1000];
    memset(buffer, 0, sizeof(char) * 1000);
    int cur = 0;
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] != ' ')
        buffer[cur++] = input[i];
      else {
        buffer[cur++] = ' ';
        while (input[i] == ' ') i++;
        i--;
      }
    }
    string result(buffer);
    int tail = result.size() - 1;
    while (result[tail] == ' ') tail--;
    return result.substr(0, tail + 1);
  }
  string parse_one_digit(int i) {
    if (i == 0) return "Zero";
    if (i == 1) return "One";
    if (i == 2) return "Two";
    if (i == 3) return "Three";
    if (i == 4) return "Four";
    if (i == 5) return "Five";
    if (i == 6) return "Six";
    if (i == 7) return "Seven";
    if (i == 8) return "Eight";
    if (i == 9) return "Nine";
  }

  string func(int num) {
    stringstream ss;
    if (100 <= num && num <= 999) {
      if (num % 100 == 0)
        ss << parse_one_digit(num / 100) << " Hundred";
      else
        ss << parse_one_digit(num / 100) << " Hundred ";
    }
    num = num % 100;
    if (10 <= num && num <= 19) {
      if (num == 10)
        ss << "Ten";
      else if (num == 11)
        ss << "Eleven";
      else if (num == 12)
        ss << "Twelve";
      else if (num == 13)
        ss << "Thirteen";
      else if (num == 14)
        ss << "Fourteen";
      else if (num == 15)
        ss << "Fifteen";
      else if (num == 16)
        ss << "Sixteen";
      else if (num == 17)
        ss << "Seventeen";
      else if (num == 18)
        ss << "Eighteen";
      else if (num == 19)
        ss << "Nineteen";
    } else if (20 <= num && num <= 99) {
      if (num / 10 == 2)
        ss << "Twenty ";
      else if (num / 10 == 3)
        ss << "Thirty ";
      else if (num / 10 == 4)
        ss << "Forty ";
      else if (num / 10 == 5)
        ss << "Fifty ";
      else if (num / 10 == 6)
        ss << "Sixty ";
      else if (num / 10 == 7)
        ss << "Seventy ";
      else if (num / 10 == 8)
        ss << "Eighty ";
      else if (num / 10 == 9)
        ss << "Ninety ";

      if (num % 10) {
        ss << parse_one_digit(num % 10).c_str();
      }

    } else {
      if (num % 10) ss << parse_one_digit(num);
    }

    return ss.str();
  }

  int get_million_part(int number) {
    int reg = number / 1000000;

    return reg % 1000;
  }
  int get_thounsand_part(int number) {
    int reg = number / 1000;

    return reg % 1000;
  }

  string numberToWords(int num) {
    if (num == 0) return "Zero";
    if (0 < num && num <= 999) {
      string stra = func(num);
      // stra.erase(stra.find_last_of(' ') + 1, string::npos);
      return rtrim(stra);

    } else if (1000 <= num && num <= 999999) {
      // thousand
      string stra = func(num / 1000);
      string strb = func(num % 1000);
      return rtrim(stra + " Thousand " + strb);

    } else if (1000000 <= num && num <= 999999999) {
      string stra = func(num / 1000000) + " Million ";
      int thousan_part = get_thounsand_part(num);
      if (thousan_part != 0) stra += func(thousan_part) + " Thousand ";

      int remained = num % 1000;
      if (remained != 0) stra += func(remained);

      // stra.erase(stra.find_last_of(' ') + 1, string::npos);
      return rtrim(stra);

    } else {
      // billion
      string stra = func(num / 1000000000) + " Billion ";
      int million_part = get_million_part(num);
      if (million_part != 0) {
        stra += func(million_part) + " Million ";
      }
      int thousand_part = get_thounsand_part(num);
      if (thousand_part != 0) {
        stra += func(thousand_part) + " Thousand ";
      }
      int hunder_part = num % 1000;
      if (hunder_part != 0) stra += func(hunder_part);

      //  stra.erase(stra.find_last_of(' ') + 1, string::npos);
      return rtrim(stra);
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}