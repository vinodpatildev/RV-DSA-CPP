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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> zigzag;
        if(root==NULL){return zigzag;}
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++){
                Node* temp = q.front(); q.pop();
                int index = leftToRight? i : size-1-i;
                row[index] = temp->val;
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            leftToRight = !leftToRight;
            zigzag.push_back(row);
        }
        return zigzag;
    }
};
int main(){
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->left = new Node(9);

    Solution solution;
    cout<<"BST zigzag level order traversal : "<<endl;
    vector<vector<int>> ans = solution.zigzagLevelOrder(root);
    for(int i=0; i<ans.size(); i++){
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
            if(j != ans.size()-1){
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}