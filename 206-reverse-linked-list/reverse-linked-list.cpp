// two ways to solve this problem 1. iterative 2. recursive
//commented code is iterative
//in recursive approach we are breaking the problem in smaller parts and when we reach the base case 
//we return the head itself which will become our newHead.
//after hitting the base case we come back to previous state and reverse the previous two links.
//we always return the newHead which will remain the same once we hit the base condition
//a liitle tricky but take a pen and paper in yu will be able to visualize it

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
        // if(head==NULL) return head;
        // ListNode* f = head;
        // ListNode* s = f->next;
        // f->next = NULL;
        // while(s){
        //     ListNode* temp = s->next;
        //     s->next = f;
        //     f = s;
        //     s = temp;
        // }
        // return f;
        if(!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

};