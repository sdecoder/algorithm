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
#include <algorithm>

#include <unordered_map>
#include <unordered_set>

using namespace std;


class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        row = matrix.size();
        if(row != 0) col = matrix[0].size();
        else col = 0;
        arr = vector<vector<int> >(row+1, vector<int>(col+1, 0));
        sum = vector<vector<int> >(row+1, vector<int>(col+1, 0));

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                modify(i+1, j+1, matrix[i][j]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2+1,col2+1) + getSum(row1, col1) - getSum(row1, col2+1) - getSum(row2+1, col1);
    }

    int getSum(int x, int y) {
        int ret = 0;
        for(int i=x; i>0; i-=lowbit(i)) {
            for(int j=y; j>0; j-=lowbit(j)) {
                ret += sum[i][j];
            }
        }
        return ret;
    }

    void modify(int x, int y, int v) {
        int oldv = arr[x][y];
        for(int i=x; i<=row; i+=lowbit(i)) {
            for(int j=y; j<=col; j+=lowbit(j)) {
                sum[i][j] = sum[i][j] - oldv + v;
            }
        }
        arr[x][y] = v;
    }

    int lowbit(int x) {
        return x&-x;
    }
private:
    int col;
    int row;
    vector<vector<int> > arr;
    vector<vector<int> > sum;
};


int main(int argc, char const *argv[])
{
    

    return 0;
}