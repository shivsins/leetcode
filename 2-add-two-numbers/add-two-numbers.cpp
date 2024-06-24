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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0, n2=0, carry=0;
        ListNode *t1 = l1, *t2 = l2, *e1,*e2;
        while(t1 || t2){
            if(t1){
                n1++;
                e1 = t1;
                t1=t1->next;
            }
            if(t2){
                n2++;
                e2 = t2;
                t2=t2->next;
            }
        }
        if(n1>=n2){
            add1(l1, l2, carry);
            if(carry){
                ListNode* temp = new ListNode(carry);
                e1->next = temp;
            }
            return l1;
            
        }else{
            add1(l2,l1,carry);
            if(carry){
                ListNode* temp = new ListNode(carry);
                e2->next = temp;
            }
            return l2;
        }
    }

    void add1(ListNode* t1, ListNode* t2, int &carry){
        if(t1 == NULL && t2 == NULL) return;
        if(t2==NULL){
            int sum = t1->val+carry;
            t1->val = sum%10;
            carry = sum/10;
            add1(t1->next, NULL , carry);
        }
        else{
            int sum = t1->val + t2->val+carry;
            t1->val = sum%10;
            carry = sum/10;
            add1(t1->next, t2->next, carry);
        }

    }

    // void add2(ListNode* t1, ListNode* t2, int &carry){
    //     if(t1 && t2) return;
    //     if(t1==NULL){
    //         int sum = t2->val+carry;
    //         t2->val = sum%10;
    //         carry = sum/10;
    //         add2(NULL, t2->next , carry);
    //     }
    //     else{
    //         int sum = t1->val + t2->val+carry;
    //         t2->val = sum%10;
    //         carry = sum/10;
    //         add2(t1->next, t2->next, carry);
    //     }

    // }
};