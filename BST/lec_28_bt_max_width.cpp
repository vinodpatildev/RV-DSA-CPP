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
    int widthOfBinaryTree(Node* root) {
        int maxWidth = 0;
        if(!root){return maxWidth;}
        queue<pair<Node*,int>> todo;
        todo.push({root,0});
        while(!todo.empty()){
            int size = todo.size();
            int mmin = todo.front().second;
            int first = todo.front().second - mmin;
            int last = todo.back().second - mmin;
            int width = last - first + 1;
            maxWidth = max(maxWidth , width);
            for(int i=0; i<size; i++){
                auto node_pair = todo.front(); todo.pop();
                Node* node = node_pair.first;
                int node_index = node_pair.second - mmin;
                if(node->left){todo.push({node->left, 2*node_index+1});}
                if(node->right){todo.push({node->right, 2*node_index+2});}           
            }
        }
       return maxWidth;
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
    cout<<"BST max width : "<<solution.widthOfBinaryTree(root);
    return 0;
}