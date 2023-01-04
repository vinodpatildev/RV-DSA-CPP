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
    bool checkBST(Node* root, long int leftRange, long int rightRange){
        if(!root){return true;}
        if(root->data<=leftRange || root->data>=rightRange){return false;}
        return checkBST(root->left,leftRange,root->data) && checkBST(root->right,root->data,rightRange);
    }
    public:
    bool isValidBST(Node* root) {
        long int leftRange = LONG_MIN;
        long int rightRange = LONG_MAX;
        return checkBST(root,leftRange,rightRange);
    }
    Node* BSTInsertNode(Node* root,int data){
        if(!root){return new Node(data);}
        Node* curr = root;
        Node* next = NULL;
        while(true){
            if(data < curr->data){
                next = curr->left;
                if(!next){
                    curr->left = new Node(data);
                    break;
                }
            }else{
                next = curr->right;
                if(!next){
                    curr->right = new Node(data);
                    break;
                }
            }
            curr = next;
        }
        return root;
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
    root = solution.BSTInsertNode(root,12);
    cout<<"validation :"<<solution.isValidBST(root)<<endl;
    return 0;
}