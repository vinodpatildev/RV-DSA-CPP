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
    Node* getTarget(Node* root,int target){
        if(!root || root->data == target){
            return root;
        }
        Node* left = getTarget(root->left,target);
        Node* right = getTarget(root->right,target);
        if(left){return left;}
        if(right){return right;}
        return NULL;
    }
  public:
    int minTime(Node* root, int target){
        int time = 0;
        if(!root){return time;}
        unordered_map <Node*,Node*> parent;
        queue<Node*> todo;
        todo.push(root);
        while(!todo.empty()){
            Node* curr = todo.front(); todo.pop();
            if(curr->left){
                parent[curr->left] = curr;
                todo.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                todo.push(curr->right);
            }
        }
        queue<Node*> burning;
        unordered_map <Node*,bool> visited;
        Node* target_node = getTarget(root,target);
        if(!target_node){return time;}
        burning.push(target_node);
        while(!burning.empty()){
            int size = burning.size();
            for(int i=0; i<size; i++){
                Node* curr = burning.front(); burning.pop();
                if(curr->left && !visited[curr->left]){
                    burning.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    burning.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    burning.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            time++;
        }
        return time-1;
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
    cout<<"Minimum time to burn tree: "<< solution.minTime(root,3);
    
    return 0;
}