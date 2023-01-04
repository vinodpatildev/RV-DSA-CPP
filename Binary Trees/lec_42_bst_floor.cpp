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
    int BSTFloor(Node* root,int data){
        int floor=INT_MAX;
        while(root){
            if(data == root->data){
                floor = root->data;
                return floor;
            }
            if(data < root->data){
                root = root->left;
            }else{
                floor = root->data;
                root = root->right;
            }
        }
        return floor;
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
    int floor = solution.BSTFloor(root,4);
    cout<<"found floor:"<<floor<<endl;
    return 0;
}