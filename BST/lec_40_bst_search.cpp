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
    Node* searchBST(Node* root,int data){
        while(root!=NULL && root->data != data){
            root = data < root->data? root->left : root->right;
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
    Node* node = solution.searchBST(root,4);
    if(node){
        cout<<"found data:"<<node->data<<endl;
    }
    return 0;
}