class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* even = head;
        ListNode* oddTemp = head->next;
        ListNode* odd = oddTemp;

        while(even != NULL && even->next != NULL && even->next->next != NULL){
            even->next = even->next->next;
            even = even->next;
            if(even->next != NULL){
                odd->next = even->next;
                odd = odd->next;
            }
        }
        even->next = oddTemp;
        odd->next = NULL;
        return head;
    }
};