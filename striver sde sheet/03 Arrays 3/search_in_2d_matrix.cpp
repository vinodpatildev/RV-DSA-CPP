#include<vector>
#include <iostream>
using namespace std;

class SolutionLeetcode {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1, mid = 0;
        while(left<=right){
            mid = (left + right)/2;
            if(matrix[mid/col][mid%col] < target){
                left = mid + 1;
            }else if(matrix[mid/col][mid%col] > target){
                right = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

class SolutionGFG {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1, col = 0;
        int row_it = 0, col_it = matrix[0].size()-1;
        while(row_it<=row && col_it>=col){
            if(matrix[row_it][col_it] == target){
                return true;
            }
            if(matrix[row_it][col_it] < target){
                row_it++;
            }else{
                col_it--;
            }
        }
        return false;
    }
};