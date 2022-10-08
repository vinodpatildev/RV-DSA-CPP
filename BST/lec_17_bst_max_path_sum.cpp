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
    int helper(Node* root,int& maxPathSum){
        if(root==NULL){return 0;}
        int ls = max(0,helper(root->left,maxPathSum));
        int rs = max(0,helper(root->right,maxPathSum));
        maxPathSum = max(maxPathSum, ls+rs+root->data);
        return max(ls,rs)+root->data;
    }
    int maxPathSum(Node* root) {
        int maxPathSum = INT_MIN;
        helper(root,maxPathSum);
        return maxPathSum;
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    cout<<"BST Max Path Sum : "<<solution.maxPathSum(root)<<endl;
    return 0;
}