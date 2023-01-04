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
    int BSTCeil(Node* root,int data){
        int ceil = -1;
        while(root){
            if(data == root->data){
                ceil = root->data;
                return ceil;
            }
            if(data < root->data){
                ceil = root->data;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return ceil;
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
    int ceil = solution.BSTCeil(root,4);
    cout<<"found ceil:"<<ceil<<endl;
    return 0;
}