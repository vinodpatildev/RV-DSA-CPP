#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<3){return {};}
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                long long int twoSumTarget = target - (long long)(nums[i] + nums[j]);
                int left=j+1, right=nums.size()-1;
                vector<int> quad({nums[i],nums[j],0,0});
                while(left<right){
                    long int twoSum = nums[left] + nums[right];
                    if(twoSum < twoSumTarget) left++;
                    else if(twoSum > twoSumTarget) right--;
                    else {
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        left++;
                        right--;
                        while(left<right && nums[left] == nums[left-1]) left++;
                        while(left<right && nums[right] == nums[right+1]) right--;
                    }
                }
                while(j<nums.size()-1 && nums[j] == nums[j+1]) j++;
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};