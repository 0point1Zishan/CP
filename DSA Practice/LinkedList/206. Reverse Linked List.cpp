class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* pre = NULL;

        while(curr != NULL){
            ListNode* n = curr->next;
            curr->next = pre;
            pre = curr;
            curr = n;
        }
        return pre;
    }
};