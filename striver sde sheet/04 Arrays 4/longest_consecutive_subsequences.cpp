#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int res=1, local=1;
        for(int i=1; i<=nums.size(); i++){
            if(i==nums.size() || nums[i] != nums[i-1]+1){
                if(i==nums.size() || nums[i] != nums[i-1]){
                    res = max(res,local);
                    local = 0;
                }else{
                    local--;
                }
            }
            local++;
        }
        return res;
    }
};