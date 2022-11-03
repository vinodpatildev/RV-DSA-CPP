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
    Node* next = NULL;
    void Iterator(Node* root){
        Node* node = NULL;
        while(true){
            if(root->left){
                node = root->left;
                while(node->right && node->right != root){ node = node->right;}
                if(node->right){
                    node->right = NULL;
                    root = root->right;
                }else{
                    node->right = root;
                    root = root->left;
                }
            }else{
                next = root;
                break;
            }
        }
    }
    bool hasNext(){
        return next != NULL;
    }
    Node* Next(){
        if(!hasNext()){return NULL;}
        Node* root = next;
        next = next->right;
        while(true){
            if(next->left){
                Node* node = next->left;
                while(node->right && node->right != next){ node = node->right; }
                if(node->right){
                    node->right = NULL;
                    break;
                }else{
                    node->right = next;
                    next = next->left;
                }
            }else{
                break;
            }
        }
        return root;
    }
};
class Solution2 {
    stack<Node*> it;
    public:
    void Iterator(Node* root){
        while(root){
            it.push(root);
            root = root->left;
        }
    }
    bool hasNext(){
        return !it.empty();
    }
    Node* Next(){
        if(!hasNext()){return NULL;}
        Node* root = it.top(); it.pop();
        Node* node = root->right;
        while(node){
            it.push(node);
            node = node->left;
        }
        return root;
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution2 solution;
    solution.Iterator(root);
    while(solution.hasNext()){
        Node* node = solution.Next();
        cout<<node->data<<",";
    }
    return 0;
}