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
    Node* BSTInsertNode(Node* root,int data){
        if(!root){return new Node(data);}
        Node* curr = root;
        Node* next = NULL;
        while(true){
            if(data < curr->data){
                next = curr->left;
            }else{
                next = curr->right;
            }
            if(!next){
                curr = new Node(data);
                break;
            }
            curr = next;
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
    root = solution.BSTInsertNode(root,12);
    return 0;
}