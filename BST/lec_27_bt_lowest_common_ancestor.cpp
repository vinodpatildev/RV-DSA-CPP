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
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root || root==p || root==q){return root;}
        Node* left = lowestCommonAncestor(root->left,p,q);
        Node* right = lowestCommonAncestor(root->right,p,q);
        if(!left){return right;}
        else if(!right){return left;}
        else{return root;}
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
    Node* lca = solution.lowestCommonAncestor(root,root->left->left,root->left->right);
    cout<<"BST lowest common ancestor : "<<lca->data<<endl;
    
    return 0;
}