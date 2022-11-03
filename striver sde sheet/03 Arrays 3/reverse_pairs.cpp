#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int todo(vector<int>& nums, vector<int>& workspace, int begin, int end){
        if(begin == end){return 0;}
        int mid = (begin+end)/2;
        return todo(nums,workspace,begin,mid) + todo(nums,workspace,mid+1,end) + todoMerge(nums,workspace,begin,mid,mid+1,end);
    }
    int todoMerge(vector<int>& nums,vector<int>& workspace, int beginLeft, int endLeft, int beginRight, int endRight){
        int size = endRight - beginLeft + 1, it = beginLeft;
        int res = 0, left_it = beginLeft, right_it = beginRight;

        while(left_it <= endLeft){
            if(right_it > endRight || nums[left_it] <= (long)2*nums[right_it]){
                res += right_it - beginRight;
                left_it++;
            }else{
                right_it++;
            }
        }
        for(int i=0; i<size; i++){
            if(beginLeft > endLeft){
                workspace[i] = nums[beginRight++];
            }else if(beginRight > endRight){
                workspace[i] = nums[beginLeft++];
            }else{
                workspace[i] = nums[beginLeft]<nums[beginRight] ?  nums[beginLeft++] : nums[beginRight++];
            } 
        }
        for(int i=0; i<size; i++,it++){
            nums[it] = workspace[i]; 
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> workspace(nums.size(),0);
        return todo(nums,workspace, 0, nums.size()-1);
    }
};