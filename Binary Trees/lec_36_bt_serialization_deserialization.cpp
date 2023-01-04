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
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string data = "";
        if(!root){return data;}
        queue<Node*> todo;
        todo.push(root);

        while(!todo.empty()){
            int size = todo.size();
            for(int i=0; i<size; i++){
                Node* curr = todo.front(); todo.pop();
                if(curr){
                    data += to_string(curr->data) + ",";
                    todo.push(curr->left);
                    todo.push(curr->right);
                }else{
                    data += "#,";
                }
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.empty()){return NULL;}
        stringstream tokenizer(data);
        string token;
        getline(tokenizer,token,',');

        Node* root = new Node(stoi(token));
        queue<Node*> todo;
        todo.push(root);
        while(!todo.empty()){
            int size = todo.size();
            for(int i=0; i<size; i++){
                Node* curr = todo.front(); todo.pop();
                getline(tokenizer,token,',');
                if(token=="#"){
                    curr->left = NULL;
                }else{
                    curr->left = new Node(stoi(token));
                    todo.push(curr->left);
                }

                getline(tokenizer,token,',');
                if(token=="#"){
                    curr->right = NULL;
                }else{
                    curr->right = new Node(stoi(token));
                    todo.push(curr->right);
                }
            }
        }
        return root;
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
    string data = solution.serialize(root);
    cout<<"BST serialized : "<<data<<endl;
    root = solution.deserialize(data);
    data = solution.serialize(root);
    cout<<"BST de-serialized :"<<data<<endl;
    return 0;
}