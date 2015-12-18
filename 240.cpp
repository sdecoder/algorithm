#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
	int row_size; 
	int col_size;
	bool binary_search(vector<vector<int> >& matrix, int row_idx,int target){
		int left_bound = 0; 
    	int right_bound = col_size -1; 
    	//cout<< "right_bound " << right_bound << endl;
    	
    	while(true){
    		if(left_bound > right_bound) break; 
    		int mid = (right_bound + left_bound)/2; 
    		//cout<< "matrix[row_idx][mid] "  << matrix[row_idx][mid] << endl; 
    		//cout<< "target " << target << endl;
    		//cout<< "mid " << mid << endl;  
    		if(matrix[row_idx][mid] == target) return true; 
    		else if(matrix[row_idx][mid] < target) left_bound = mid + 1; 
    		else right_bound = mid - 1;
    	}

    	return false; 
	}

    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	row_size = matrix.size();
    	col_size = matrix[0].size();
    	for (int i = 0; i < row_size; ++i)
    	{	
    		cout<< "searching " << i << " row" << endl; 
    		if(binary_search(matrix, i, target))
    			return true; 
    	}

        return false; 
    }
};



int main(int argc, char const *argv[])
{
		vector<vector<int> > matrix; 
		vector<int> a; 
		a.push_back(-1);
		matrix.push_back(a);

		std::vector<int> b;
		b.push_back(-1);
		matrix.push_back(b);


	/*	std::vector<int> c;
		c.push_back(3);
		c.push_back(6);
		c.push_back(9);
		c.push_back(16); 
		c.push_back(22);
		matrix.push_back(c);

		std::vector<int> d;
		d.push_back(10);
		d.push_back(13);
		d.push_back(14);
		d.push_back(17); 
		c.push_back(24);
		matrix.push_back(d);


		std::vector<int> e;
		e.push_back(18);
		e.push_back(21);
		e.push_back(23);
		e.push_back(26); 
		e.push_back(30);
		matrix.push_back(e);*/

		Solution s; 
		bool result = s.searchMatrix(matrix, 0);
		if(result) cout<< "found" << endl; 
		else cout<<"not found " << endl;
/*	int matrix[5][5] ={
		{1,   4,  7, 11, 15},
  		{2,   5,  8, 12, 19},
  		{3,   6,  9, 16, 22},
  		{10, 13, 14, 17, 24},
  		{18, 21, 23, 26, 30}
	};
	int *p1 = &matrix[0][0]; 
	//printf("matrix[4][4]%d\n", matrix[1][3]);
	bool result = searchMatrix(&p1, 5, 5, 5);
	if(result) puts("target found!");
	else puts("target not found!");*/
	return 0;
}
