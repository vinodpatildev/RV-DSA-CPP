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
class Solution1 {
    //8,5,1,7,10,12
    bool checkBST(Node* root, long int leftRange, long int rightRange){
        if(!root){return true;}
        if(root->data<=leftRange || root->data>=rightRange){return false;}
        return checkBST(root->left,leftRange,root->data) && checkBST(root->right,root->data,rightRange);
    }
    int findPartition(vector<int>& pre, int begin_pre, int end_pre){
        for(int i=begin_pre+1; i<pre.size(); i++){
            if(pre[i]>pre[begin_pre]){return i;}
        }
        return end_pre+1;
    }
    Node* createFromPre(vector<int>& pre, int begin_pre, int end_pre){
        if(begin_pre>end_pre){return NULL;}
        Node* root = new Node(pre[begin_pre]);
        int part = findPartition(pre,begin_pre,end_pre);
        root->left = createFromPre(pre,begin_pre+1,part-1);
        root->right = createFromPre(pre,part,end_pre);
        return root;
    }
    public:
    bool isValidBST(Node* root) {
        long int leftRange = LONG_MIN;
        long int rightRange = LONG_MAX;
        return checkBST(root,leftRange,rightRange);
    }
    Node* BSTCreateFromPreorder(vector<int>& pre){
        if(pre.size()==0){return NULL;}
        return createFromPre(pre,0,pre.size()-1);
    }
};

//Efficient solution O(nlogn)
class Solution2 {
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
public:
    Node* BSTCreateFromPreorder(vector<int> &pre){
        vector<int> in = pre;
        sort(in.begin(), in.end());
        return buildTreeFromPreorderInorder(pre,in);
    }
};
//Very Efficient soltuion O(n)
class Solution {
    public:
    Node* build(vector<int>& pre, int& index, int ubound){
        if(index==pre.size() ||  pre[index] > ubound){ return NULL; }
        Node* root = new Node(pre[index++]);
        root->left = build(pre, index, root->data);
        root->right = build(pre, index, ubound);
        return root;
    }
    Node* BSTCreateFromPreorder(vector<int>& pre){
        int index = 0;
        return build(pre, index, INT_MAX);
    }
};
int main(){
    vector<int> pre({8,5,1,7,10,12});
    Solution1 sol1;
    Node* root1 = sol1.BSTCreateFromPreorder(pre);
    cout<<"Method:1";
    cout<<"BST is complete."<<endl;
    cout<<"BST is validation :"<<sol1.isValidBST(root1)<<endl;

    Solution2 sol2;
    Node* root2 = sol2.BSTCreateFromPreorder(pre);
    cout<<"Method:2";
    cout<<"BST is complete."<<endl;
    cout<<"BST is validation :"<<sol1.isValidBST(root2)<<endl;

    Solution sol;
    Node* root = sol.BSTCreateFromPreorder(pre);
    cout<<"Method:3";
    cout<<"BST is complete."<<endl;
    cout<<"BST is validation :"<<sol1.isValidBST(root)<<endl;
    return 0;
}