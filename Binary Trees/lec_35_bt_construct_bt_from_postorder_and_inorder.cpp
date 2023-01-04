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
    Node* helper(vector<int>& inorder, vector<int>& postorder,int inBegin, int inEnd, int& postId, unordered_map<int,int> mpp ){
        if(inBegin>inEnd){return NULL;}
        Node* root = new Node(postorder[postId--]);

        int inRoot = mpp[root->data];
        
        root->right = helper(inorder,postorder,inRoot+1,inEnd,postId,mpp);
        root->left = helper(inorder,postorder,inBegin,inRoot-1,postId,mpp);
        return root;
    }
    Node* buildTreeFromPostorderInorder(vector<int>& postorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int postId = postorder.size()-1;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        return helper(inorder,postorder,0,inorder.size()-1,postId,mpp);
    }
};
int main(){
    vector<int> postorder({9,15,7,20,3});
    vector<int> inorder({9,3,15,20,7});
    Solution solution;
    struct Node* root = solution.buildTreeFromPostorderInorder(postorder,inorder);
    return 0;
}