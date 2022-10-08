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
        vector<vector<int>> verticalOrderTraversal(Node* root) {
        vector<vector<int>> res;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto it = todo.front(); todo.pop();
            Node* node = it.first;
            int line = it.second.first;
            int level = it.second.second;
            nodes[line][level].insert(node->data);
            if(node->left){todo.push({node->left,{line-1,level+1}});}
            if(node->right){todo.push({node->right,{line+1,level+1}});}
        }
        for(auto line: nodes){
            vector<int> col;
            for(auto level: line.second ){
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            res.push_back(col);
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
    vector<vector<int>> ans = solution.verticalOrderTraversal(root);
    for(int i=0; i<ans.size(); i++){
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
            if(j != ans[i].size()-1){
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}