ListNode* reverse(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* r = reverse(slow);
        ListNode* l = head;
        while(l != NULL && r != NULL){
            if(l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        return true;
    }
};