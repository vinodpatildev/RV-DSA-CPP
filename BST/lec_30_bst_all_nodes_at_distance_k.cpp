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
    vector<int> distanceK(Node* root, Node* target, int k) {
        vector<int> res;
        if(!root){return res;}
        unordered_map<Node*,Node*> mpp;
        queue<Node*> todo;
        todo.push(root);
        while(!todo.empty()){
            Node* curr = todo.front(); todo.pop();
            if(curr->left){
                mpp[curr->left]=curr;
                todo.push(curr->left);
            }
            if(curr->right){
                mpp[curr->right]=curr;
                todo.push(curr->right);
            }
        }
        unordered_map<Node*,int> visited;
        queue<Node*> nodes;
        nodes.push(target);
        while(!nodes.empty()){
            int size = nodes.size();
            for(int i=0; i<size; i++){
                Node* node = nodes.front(); nodes.pop();
                if(k==0){
                    res.push_back(node->data);
                }else if(k>0){
                    if(node->left && !visited[node->left]){
                        nodes.push(node->left);
                    }
                    if(node->right && !visited[node->right]){
                        nodes.push(node->right);
                    }
                    if(mpp[node] && !visited[mpp[node]]){
                        nodes.push(mpp[node]);
                    }
                }
                visited[node]++;
            }
            k--;
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
    vector<int> ans = solution.distanceK(root,root->right->left,2);
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