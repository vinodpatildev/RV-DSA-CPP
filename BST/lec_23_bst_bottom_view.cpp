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
        vector<int> bottomView(Node* root) {
        vector<int> res;
        map<int,int> nodes_view;
        queue<pair<Node*,int>> todo;
        todo.push({root,0});
        while(!todo.empty()){
            auto curr = todo.front(); todo.pop();
            auto node = curr.first;
            auto line = curr.second;
            nodes_view[line] = node->data;
            if(node->left){todo.push({node->left,line-1});}
            if(node->right){todo.push({node->right,line+1});}            
        }
        for(auto p:nodes_view){
            res.push_back(p.second);
        }
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
    cout<<"BST vertical order traversal : ";
    vector<int> ans = solution.bottomView(root);
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