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
    bool findPath(Node* root, Node* node, vector<int>& res){
        if(!root){return false;}
        res.push_back(root->data);
        if(root==node){return true;}
        if(findPath(root->left,node,res) || findPath(root->right,node,res)){
            return true;
        }
        res.pop_back();
        return false;   
    }
    public:
    vector<int> rootToNodePath(Node* root,Node* node){
        vector<int> res;
        findPath(root,node,res);
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
    cout<<"BST root to node path : ";
    vector<int> path = solution.rootToNodePath(root,root->left->left);
    cout<<"[";
    for(int i=0; i<path.size(); i++){
        cout<<path[i];
        if(i != path.size()-1){
            cout<<", ";
        }
    }
    cout<<"]";
    return 0;
}