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
    bool isSameTree(Node* p, Node* q) {
        if(p==NULL || q==NULL){ return p==q; }
        return p->data == q->data && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    } 
};
int main(){
    struct Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(1);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->left = new Node(9);

    struct Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(7);
    root2->left->left = new Node(1);
    root2->left->right = new Node(4);
    root2->right->left = new Node(6);
    root2->right->left = new Node(9);

    Solution solution;
    cout<<"Both BSTs are : "<<solution.isSameTree(root1,root2);
    return 0;
}