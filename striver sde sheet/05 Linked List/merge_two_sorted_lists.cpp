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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *res = NULL, *prev = NULL;
        if(list1->val > list2->val) std::swap(list1,list2);
        res=list1;
        while(list1 && list2){
            while(list1 && list1->val <= list2->val) prev=list1, list1=list1->next;
            prev->next=list2;
            std::swap(list1,list2);
        }
        return res;
    }
};