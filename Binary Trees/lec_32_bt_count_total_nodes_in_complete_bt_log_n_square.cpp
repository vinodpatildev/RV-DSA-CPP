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
    int leftHeight(Node* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    int rightHeight(Node* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
public:
    int countNodes(Node* root) {
        if(!root){return 0;}
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh==rh){return (1<<lh)-1;}
        return countNodes(root->left) + countNodes(root->right) + 1;
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
    cout<<"Number of nodes in complete binary tree: "<< solution.countNodes(root);
    
    return 0;
}