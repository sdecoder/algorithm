#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#include <iostream>
#include <vector>

using namespace std; 

class NumMatrix {
  int mrow;
  int mcol;
  int buffer[1000][1000];

 public:
  NumMatrix(vector<vector<int> > &matrix) {
    memset(buffer, 0, sizeof(buffer));
    mrow = matrix.size();
    if (mrow <= 0) return;
    mcol = matrix[0].size();
    for (int i = 0; i < mrow; ++i) {
      for (int j = 0; j < mcol; ++j) {
        if (i == 0)
          buffer[i][j] = matrix[i][j];
        else
          buffer[i][j] = buffer[i - 1][j] + matrix[i][j];
      }
    }

    for (int j = 1; j < mcol; ++j) {
      for (int i = 0; i < mrow; ++i) {
        buffer[i][j] = buffer[i][j] + buffer[i][j - 1];
      }
    }

   /* cout << "[dbg] output the buffer matrix" << endl;
    for (int i = 0; i < mrow; ++i)
    {
      for (int j = 0; j < mcol; ++j) {
        cout << buffer[i][j] << " ";
      }
      cout << endl;    
    }*/
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row2 >= mrow || col2 >= mcol) return 0;

    if(row1 == row2 && col1 == col2)
      return matrix[][]

    if (mrow == 1) {
      if (col1 - 1 < 0)
        return buffer[0][col2] ;
      else
        return buffer[0][col2] - buffer[0][col1 - 1];
    }

    if (mcol == 1) {
      if (row1 - 1 < 0)
        return buffer[row2][0] ;
      else
        return buffer[row2][0] - buffer[row1 - 1][0];
    }

    if(row1 == row2) {
      if (col1 - 1 < 0)
        return buffer[row1][col2] ;
      else
        return buffer[row1][col2] - buffer[row1][col1 - 1];
    }

    if(col1 == col2){
      if (row1 - 1 < 0)
        return buffer[row2][col1];
      else
        return buffer[row2][col1] - buffer[row1 - 1][col1];
    }


    
    int a, b, c, d;
    a = buffer[row2][col2];
    if (row1 < 1)
      b = 0;
    else
      b = buffer[row1 - 1][col2];

    if (col1 < 1)
      c = 0;
    else
      c = buffer[row2][col1 - 1];

    if (row1 < 1 && col1 < 1)
      d = 0;
    else if (row1 < 1)
      d = buffer[0][col1 - 1];
    else if (col1 < 1)
      d = buffer[row1 - 1][0];
    else
      d = buffer[row1 - 1][col1 - 1];

    return a - b - c + d;
  }
};


//[[8,-4,5],[-1,4,4],[-2,3,1],[-4,4,3]],sumRegion(0,1,0,2),sumRegion(1,1,1,2),sumRegion(0,1,0,2)

int main(int argc, char const *argv[])
{
  vector<vector<int> > matrix; 
  vector<int> row1; 
  row1.push_back(8); 
  row1.push_back(-4); 
  row1.push_back(5);
  matrix.push_back(row1);

  vector<int> row2; 
  row2.push_back(-1); 
  row2.push_back(4);
  row2.push_back(4);
  matrix.push_back(row2);
  
  vector<int> row3; 
  row3.push_back(-2); 
  row3.push_back(3); 
  row3.push_back(1);
  matrix.push_back(row3);
  
  vector<int> row4; 
  row4.push_back(-4); 
  row4.push_back(4); 
  row4.push_back(3);
  matrix.push_back(row4);

  NumMatrix solution(matrix);
  cout <<  solution.sumRegion(0,1,0,2) << endl;
  cout <<  solution.sumRegion(1,1,1,2) << endl;
  cout <<  solution.sumRegion(0,1,0,2) << endl;

  return 0;
}