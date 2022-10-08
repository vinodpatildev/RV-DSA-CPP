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
    int helper(Node* root,int& diameter){
        if(root==NULL){return 0;}
        int lh = helper(root->left,diameter);
        int rh = helper(root->right,diameter);
        diameter = max(diameter, lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(Node* root) {
        int diameter = 0;
        helper(root,diameter);
        return diameter;
    }
    
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    cout<<"BST diameter : "<<solution.diameterOfBinaryTree(root)<<endl;
    return 0;
}