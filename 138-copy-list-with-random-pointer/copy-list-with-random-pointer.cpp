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
        Node *l1 = head;
        Node *head2 = new Node(0);
        Node *l2 = head2;
        map<Node*, Node*> m;
        if(!l1) return NULL;
        while(l1){
            l2->val = l1->val;
            m[l1] = l2;
            if(l1->next){
                Node *temp = new Node(0);
                l2->next = temp;
                l2=l2->next;
            }
            l1=l1->next; 
        }
        l1=head;
        l2 = head2;
        while(l1){
            l2->random = m[l1->random];
            l1 = l1->next;
            l2 = l2->next;
        }
        return head2;
    }
};