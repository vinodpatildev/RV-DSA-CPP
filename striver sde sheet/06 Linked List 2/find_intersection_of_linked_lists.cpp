#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> checked;
        while(headA) checked.insert(headA), headA = headA->next;
        while(headB) {
            if(checked.find(headB) != checked.end()) return headB;
            headB = headB->next;
        } 
        return NULL;
    }
};
Console
