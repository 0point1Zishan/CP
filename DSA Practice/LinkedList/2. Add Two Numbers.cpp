class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* l2Head = l2;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;

            if(l2){
                l2->val = sum % 10;
                tail = l2;
                l2 = l2->next;
            }
            if(l1){
                l1->val = sum % 10;
                tail = l1;
                l1 = l1->next;
            }
            if(!l1 && l2) head = l2Head;
            if(!l1 && !l2 && carry)   tail->next = new ListNode(carry);
        }
        return head;
    }
};