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
    Node* reverseOddLevels(Node* root) {
        if(!root){return root;}
        queue<Node*> todo;
        deque<Node*> odd;
        queue<Node*> next;

        todo.push(root);
        while(!todo.empty()){
            int size_todo = todo.size();
            for(int i=0; i<size_todo; i++){
                Node* curr = todo.front(); todo.pop();
                odd.push_back(curr->left);
                odd.push_back(curr->right);
                todo.push(curr);
            }
            int size_odd = odd.size();
            for(int i=0; i<size_odd; i++){
                Node* curr = odd.front(); odd.pop_front();
                if(curr){
                    next.push(curr->left);
                    next.push(curr->right);
                }
                odd.push_back(curr);
            }
            for(int i=0; i<size_todo; i++){
                Node* curr = todo.front(); todo.pop();
                curr->left = odd.back(); odd.pop_back();
                curr->right = odd.back(); odd.pop_back();
                odd.push_front(curr->left);
                odd.push_front(curr->right);
            }
            for(int i=0; i<size_odd; i++){
                Node* curr = odd.back(); odd.pop_back();
                if(curr){
                    curr->left = next.front(); next.pop();
                    curr->right = next.front(); next.pop();
                    
                    if(curr->left){todo.push(curr->left);}
                    if(curr->right){todo.push(curr->right);}
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
    solution.reverseOddLevels(root);
    cout<<"BST odd levels reversed : "<<endl;
    return 0;
}