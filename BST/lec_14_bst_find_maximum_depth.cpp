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
    int findMaxDepth(Node* root) {
        if(root==NULL){return 0;}
        int maxLeftDepth = findMaxDepth(root->left);
        int maxRightDepth = findMaxDepth(root->right);
        return max(maxLeftDepth,maxRightDepth)+1;
    }
    int findMaxDepthIterative(Node* root) {
        int height = 0;
        if(root==NULL){return height;}
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* temp = q.front(); q.pop();
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            height++;
        }
        return height;        
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    cout<<"maximum depth of BST (recursive method) : "<<solution.findMaxDepth(root)<<endl;
    cout<<"maximum depth of BST (iterative method) : "<<solution.findMaxDepthIterative(root)<<endl;
    
    return 0;
}