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
    int helper(Node* root){
        if(root==NULL){return 0;}
        int lh = helper(root->left);
        if(lh==-1){return -1;}
        int rh = helper(root->right);
        if(rh==-1){return -1;}
        if(abs(lh-rh)>1){ return -1; }
        return max(lh,rh)+1;
    }
    bool isBalanced(Node* root) {
        return helper(root) != -1;
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    cout<<"BST is balanced : "<<solution.isBalanced(root)<<endl;
    return 0;
}