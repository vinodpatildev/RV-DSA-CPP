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
    void leftViewHelper(Node* root, vector<int>& res, int level){
        if(root==NULL){return;}
        if(level==res.size()){
            res.push_back(root->data);
        }
        leftViewHelper(root->left,res,level+1);
        leftViewHelper(root->right,res,level+1);
    }
    void rightViewHelper(Node* root, vector<int>& res, int level){
        if(root==NULL){return;}
        if(level==res.size()){
            res.push_back(root->data);
        }
        rightViewHelper(root->right,res,level+1);
        rightViewHelper(root->left,res,level+1);
    }
    vector<int> leftView(Node* root) {
        vector<int> res;
        leftViewHelper(root,res,0);
        return res;        
    }
    vector<int> rightView(Node* root) {
        vector<int> res;
        rightViewHelper(root,res,0);
        return res;        
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
    cout<<"BST left  view : ";
    vector<int> lans = solution.leftView(root);
    cout<<"[";
    for(int i=0; i<lans.size(); i++){
        cout<<lans[i];
        if(i != lans.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    cout<<"BST right view : ";
    vector<int> rans = solution.rightView(root);
    cout<<"[";
    for(int i=0; i<rans.size(); i++){
        cout<<rans[i];
        if(i != rans.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    return 0;
}