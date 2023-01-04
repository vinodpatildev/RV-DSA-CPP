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
    vector<int> PreInPostOrderTraversal(Node* root,string order) {
        vector<int> preorder;
        vector<int> inorder;
        vector<int> postorder;
        if(root==NULL){return vector<int>();}
        stack<pair<Node*,int>> st;
        st.push(make_pair(root,1));
        while(!st.empty()){
            pair<Node*,int> node = st.top();
            if(node.second==1){
                preorder.push_back(node.first->data);
                st.top().second = 2;
                if(node.first->left){st.push(make_pair(node.first->left,1));}
            }else if(node.second==2){
                inorder.push_back(node.first->data);
                st.top().second = 3;
                if(node.first->right){st.push(make_pair(node.first->right,1));}
            }else if(node.second==3){
                postorder.push_back(node.first->data);
                st.pop();
            }          
        }
        if(order=="preorder"){
            return preorder;
        }else if(order=="inorder"){
            return inorder;
        }else if(order=="postorder"){
            return postorder;
        }
        return vector<int>();
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution solution;
    vector<int> preorder = solution.PreInPostOrderTraversal(root,"preorder");
    cout<<"preorder : [";
    for(int i=0; i<preorder.size(); i++){
        cout<<preorder[i];
        if(i != preorder.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;

    vector<int> inorder = solution.PreInPostOrderTraversal(root,"inorder");
    cout<<"inorder : [";
    for(int i=0; i<inorder.size(); i++){
        cout<<inorder[i];
        if(i != inorder.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;

    vector<int> postorder = solution.PreInPostOrderTraversal(root,"postorder");
    cout<<"postorder : [";
    for(int i=0; i<postorder.size(); i++){
        cout<<postorder[i];
        if(i != postorder.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    return 0;
}