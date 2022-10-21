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
    vector<int> iterativePostorderTraversal(Node* root) {
        vector<int> ans;
        if(root==NULL){return ans;}
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);

        Node* node = NULL;
        while(true){
            if(st1.empty()){break;}
            node = st1.top(); st1.pop();
            if(node->left){st1.push(node->left);}
            if(node->right){st1.push(node->right);}
            st2.push(node);
        }
        while(!st2.empty()){
            node = st2.top(); st2.pop();
            ans.push_back(node->data);
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
    vector<int> ans = solution.iterativePostorderTraversal(root);
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