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
    bool checkBST(Node* root, long int leftRange, long int rightRange){
        if(!root){return true;}
        if(root->data<=leftRange || root->data>=rightRange){return false;}
        return checkBST(root->left,leftRange,root->data) && checkBST(root->right,root->data,rightRange);
    }
    bool isValidBST(Node* root) {
        long int leftRange = LONG_MIN;
        long int rightRange = LONG_MAX;
        return checkBST(root,leftRange,rightRange);
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution solution;
    bool res = solution.isValidBST(root);
    cout<<"BST validation :"<<res<<endl;
    return 0;
}