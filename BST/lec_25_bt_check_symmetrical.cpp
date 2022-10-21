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
    bool checkSymmetric(Node* left,Node* right){
        if(!left || !right){return left==right;}
        if(left->data != right->data){return false;}
        return checkSymmetric(left->left,right->right) && checkSymmetric(left->right,right->left);
    }
public:
    bool isSymmetric(Node* root) {
        return !root || checkSymmetric(root->left,root->right);
    }
};
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    cout<<"BST is symmetric : "<<solution.isSymmetric(root);
    return 0;
}