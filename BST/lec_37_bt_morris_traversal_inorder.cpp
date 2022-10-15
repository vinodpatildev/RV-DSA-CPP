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
    vector<int> inorderMorrisTraversal(Node* root) {
        vector<int> inorder;
        Node* curr = root;
        while(curr){
            if(curr->left){
                Node* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }else{
                inorder.push_back(curr->data);
                curr = curr->right;
            }     
        }
        return inorder;
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    vector<int> ans = solution.inorderMorrisTraversal(root);
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