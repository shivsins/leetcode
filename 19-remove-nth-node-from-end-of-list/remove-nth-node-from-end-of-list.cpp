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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* t = head;
        while(t){
            len++;
            t=t->next;
        }
        t = head;
        if(len-n == 0) return t->next;
        for(int i=0;i<len-n-1;i++){
            t=t->next;
        }
        t->next = t->next->next;
        return head;
    }
};