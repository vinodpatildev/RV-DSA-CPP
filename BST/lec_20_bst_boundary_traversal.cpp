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
bool isLeaf(Node* node){
    return node!=NULL && node->left==NULL && node->right==NULL;
}
class Solution {
public:
    void addLeftBoundary(Node* root,vector<int>& res){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)){res.push_back(curr->data);}
            if(curr->left){curr = curr->left;}
            else{curr = curr->right;}
        }
    }
    void addRightBoundary(Node* root,vector<int>& res){
        Node* curr = root->right;
        stack<int> st;
        if(curr){
            if(!isLeaf(curr)){st.push(curr->data);}
            if(curr->right){curr = curr->right;}
            else{curr = curr->left;}
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }
    void addLeaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data); return;
        }
        if(root->left){addLeaves(root->left,res);}
        if(root->right){addLeaves(root->right,res);}
    }
    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if(root==NULL){return res;}
        if(!isLeaf(root)){res.push_back(root->data);}
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
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
    cout<<"BST boundary traversal : ";
    vector<int> ans = solution.boundaryTraversal(root);
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i != ans.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    return 0;
}