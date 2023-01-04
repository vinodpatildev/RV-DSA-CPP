#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr_org = head, *dup = NULL, *prev_dup = NULL, *curr_dup;
        unordered_map <Node*,Node*> nodeMapping;
        while(curr_org){
            if(!dup) dup = new Node(curr_org->val), prev_dup = dup;
            else prev_dup->next = new Node(curr_org->val), prev_dup = prev_dup->next;
            nodeMapping[curr_org] = prev_dup;
            curr_org = curr_org->next;
        }
        curr_org = head;
        curr_dup = dup;
        while(curr_org){
            if(curr_org->random) curr_dup->random = nodeMapping[curr_org->random];
            curr_org = curr_org->next;
            curr_dup = curr_dup->next;
        }
        return dup;
    }
};