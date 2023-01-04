#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            int target = -nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right] < target) left++; 
                else if(nums[left]+nums[right] > target) right--;
                else {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++, right--;
                } 
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};