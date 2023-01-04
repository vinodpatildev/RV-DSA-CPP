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
private:
    stack<Node*> left,right;
    void addAllLeft(Node* root){
        while(root){
            left.push(root);
            root = root->left;
        }
    }
    void addAllRight(Node* root){
        while(root){
            right.push(root);
            root = root->right;
        }
    }
    Node* leftNext(){
        if(!leftHasNext()){return NULL;}
        Node* node = left.top(); left.pop();
        addAllLeft(node->right);
        return node;
    }
    Node* rightNext(){
        if(!rightHasNext()){return NULL;}
        Node* node = right.top(); right.pop();
        addAllRight(node->left);
        return node;
    }
    bool leftHasNext(){return !left.empty();}
    bool rightHasNext(){return !right.empty();}
public:
    bool findTarget(Node* root, int k) {
        addAllLeft(root);
        addAllRight(root);

        Node *left,*right;
        left = leftNext();
        right = rightNext();
        while(left && right && left->data < right->data){
            int sum = left->data + right->data;
            if(sum == k){return true;}
            if(sum < k){
                left = leftNext();
            }else{
                right = rightNext();
            }
        }
        return false;
    }
};
int main(){
    struct Node* root = new Node(10);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution solution;
    cout<<"Two sum :"<<solution.findTarget(root,10)<<endl;
    return 0;
}