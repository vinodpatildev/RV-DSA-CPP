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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){return ans;}
        queue<Node*> sq;
        sq.push(root);
        while(!sq.empty()){
            int sq_size = sq.size();
            vector<int> level;
            for(int i=0; i<sq_size; i++){
                Node* node = sq.front(); sq.pop();
                if(node->left){sq.push(node->left);}
                if(node->right){sq.push(node->right);}
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    vector<vector<int>> ans = solution.levelOrder(root);
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