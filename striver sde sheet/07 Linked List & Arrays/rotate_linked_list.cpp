#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        int nodeCount = 1;
        ListNode *node = head;
        while(node->next) nodeCount++, node = node->next;

        k = k%nodeCount;
        if(k==0) return head;

        node->next = head;

        k = nodeCount-k;
        while(k--) head = head->next;

        node = head;
        while(--nodeCount) node = node->next;
        node->next = NULL;

        return head;
    }
};