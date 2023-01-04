#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        int res=0, sum=0;
        if(n==0) return 0;
        unordered_map <int,int> mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum) != mp.end()){
                res = max(res,i-mp[sum]);
            }
            else mp[sum] = i;
        }
        return res;
    }
};