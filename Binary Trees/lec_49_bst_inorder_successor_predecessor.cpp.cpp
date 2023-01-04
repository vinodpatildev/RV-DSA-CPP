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
    Node* BSTInorderSuccessor(Node* root, Node* p){
        Node* successor = NULL;
        while(root){
            if(p->data < root->data){
                successor = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return successor;
    }
    Node* BSTInorderPredecessor(Node* root, Node* p){
        Node* predecessor = NULL;
        while(root){
            if(p->data <= root->data){
                root = root->left;
            }else{
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
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
    Node* predecessor = solution.BSTInorderPredecessor(root,root->left);
    Node* successor = solution.BSTInorderSuccessor(root, root->left);

    cout<<"Inorder predecessor :"<<predecessor->data<<endl;
    cout<<"Inorder successor   :"<<successor->data<<endl;
    return 0;
}