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
    bool hasCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;
        if(!s) return false;
        while(true){
            if(!s) return false;
            if(!f) return false;
            if(f->next == s) return true;
            s = s->next;
            f = f->next;
            if(f) f = f->next;
        }
        return false;
    }
};