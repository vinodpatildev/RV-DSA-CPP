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
    int kthLargestElement(Node* root, int& k){
        if(!root){return -1;}
        int res = kthLargestElement(root->left,k);
        if(k==0){return res;}

        k--;
        if(k==0){return root->data;}

        res = kthLargestElement(root->right,k);
        if(k==0){return res;}
        return -1;        
    }
    public:
    int BSTKthLargestElement(Node* root, int k){
        return kthLargestElement(root,k);
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
    int res = solution.BSTKthLargestElement(root,1);
    cout<<"Kth largest element : "<<res<<endl;
    return 0;
}