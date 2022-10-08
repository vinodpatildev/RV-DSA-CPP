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
        stack<Node*> st;
        Node* node = root;
        while(node || !st.empty()){
            if(node){
                st.push(node);
                node = node->left;
            }else{
                Node* temp = st.top()->right;
                if(temp){
                    node = temp;
                }else{
                    temp = st.top(); st.pop();
                    ans.push_back(temp->data);

                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top(); st.pop();
                        ans.push_back(temp->data);
                    }
                }
            }
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