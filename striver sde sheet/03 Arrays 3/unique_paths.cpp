#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat(2,vector<int>(n,0));
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(row==0 && col==0){
                    mat[row&1][col] = 1;
                }else if(row==0){
                    mat[row&1][col] = mat[row&1][col-1];
                }else if(col==0){
                    mat[row&1][col] = mat[(row-1)&1][col];
                }else{
                    mat[row&1][col] = mat[row&1][col-1] + mat[(row-1)&1][col];
                }
            }
        }
        return mat[(m-1)&1][(n-1)];
    }
};