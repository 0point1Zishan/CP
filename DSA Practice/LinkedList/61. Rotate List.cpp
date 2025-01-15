class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int sz = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;

        while(temp){
            sz++;
            if(temp) tail = temp;
            temp = temp->next;
        }

        k %= sz;
        if(k == 0) return head;

        temp = head;
        k = sz-k;
        while(k-- > 1){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};