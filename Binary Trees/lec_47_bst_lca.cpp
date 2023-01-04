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
    Node* BSTLowestCommonAncestor(Node* root, Node* p, Node* q ){
        if(!root){return NULL;}
        if(root->val < p->val && root->val < q->val){
            return BSTLowestCommonAncestor(root->right, p, q);
        }
        if(root->val > p->val && root->val > q->val){
            return BSTLowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
int main(){
    struct Node* root = new Node(10);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution solution;
    Node* node = solution.BSTInsertNode(root, root->left->left, root->right->right);
    return 0;
}