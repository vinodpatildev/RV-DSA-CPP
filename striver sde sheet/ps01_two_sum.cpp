#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution{
    public:
    void twoSum(vector<int>& arr,int target){
        unordered_map<int,int> mpp;
        for(int i=0; i<arr.size(); i++){
            if(mpp.find(target-arr[i])!=mpp.end()){
                cout<<"["<<mpp[target-arr[i]]<<"--"<<i<<"]"<<endl;
                break;
            }
            mpp[arr[i]] = i;
        }
    }
};

int main(){
    vector<int> arr({2,6,5,8,11});

    Solution solution;
    solution.twoSum(arr,14);

    return 0;
}