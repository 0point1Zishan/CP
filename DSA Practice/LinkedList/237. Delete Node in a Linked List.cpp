class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp->next->next != NULL){
            temp->val = temp->next->val;
            temp = temp->next;
        }
        temp->val = temp->next->val;
        temp->next = NULL;
    }
};