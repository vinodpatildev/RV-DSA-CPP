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
    vector<int> iterativePreorderTraversal(Node* root) {
        vector<int> ans;
        if(root==NULL){return ans;}
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* node = st.top(); st.pop();
            if(node->right){st.push(node->right);}
            if(node->left){st.push(node->left);}
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
    vector<int> ans = solution.iterativePreorderTraversal(root);
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