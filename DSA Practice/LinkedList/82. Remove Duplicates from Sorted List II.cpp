class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* a = new ListNode(-1);
        a->next = head;
        ListNode* temp = a;

        while(temp != NULL && temp->next != NULL){
            ListNode* nextNode = temp->next->next;
            bool isduplicate = false;
            while(nextNode != NULL && nextNode->val == temp->next->val){
                nextNode = nextNode->next;
                isduplicate = true;
            }
            if(isduplicate) temp->next = nextNode;
            else temp = temp->next;
        }
        return a->next;
    }
};