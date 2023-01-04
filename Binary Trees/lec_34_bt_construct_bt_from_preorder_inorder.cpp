#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
   Node* helper(vector<int>& inorder,vector<int>& preorder,int inBegin,int inEnd, int& preId, unordered_map<int,int>& mpp){
        if(inBegin>inEnd){return NULL;}
        Node* root = new Node(preorder[preId++]);
        
        int inRoot = mpp[root->data];
        
        root->left = helper(inorder,preorder,inBegin,inRoot-1, preId, mpp);
        root->right = helper(inorder,preorder,inRoot+1,inEnd, preId, mpp);
        return root;
    }
    Node* buildTreeFromPreorderInorder(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int preId = 0;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        return helper(inorder,preorder,0,inorder.size()-1,preId,mpp);
    }
};
int main(){
    vector<int> preorder({1,2,3});
    vector<int> inorder({3,2,1});
    Solution solution;
    struct Node* root = solution.buildTreeFromPreorderInorder(inorder,preorder);
    return 0;
}