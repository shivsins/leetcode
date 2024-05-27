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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* f = head;
        ListNode* s = f->next;
        f->next = NULL;
        while(s){
            ListNode* temp = s->next;
            s->next = f;
            f = s;
            s = temp;
        }
        return f;
    }
};