#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map <int,int> mpp;

        for(int i=0; i<nums.size(); i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                res.emplace_back(mpp[target-nums[i]]);
                res.emplace_back(i);
                break;
            }
            mpp[nums[i]] = i;
        }
        return res;
    }
}; 
int main(){
    vector<int> arr({2,6,5,8,11});

    Solution solution;
    solution.twoSum(arr,14);

    return 0;
}