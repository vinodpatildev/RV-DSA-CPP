#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMaxHeight(height.size()), rightMaxHeight(height.size());
        leftMaxHeight[0] = height[0], rightMaxHeight[height.size()-1] = height[height.size()-1];

        for(int i=1; i<height.size(); i++) leftMaxHeight[i] = max(leftMaxHeight[i-1], height[i]);
        for(int i=height.size()-2; i>=0; i--) rightMaxHeight[i] = max(rightMaxHeight[i+1], height[i]);
        
        int res = 0;
        for(int i=1; i<height.size(); i++) res += min(leftMaxHeight[i],rightMaxHeight[i])-height[i];
        return res;
        
    }
};