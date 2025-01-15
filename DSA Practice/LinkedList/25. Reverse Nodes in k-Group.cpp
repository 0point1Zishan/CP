ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;

    ListNode* newH = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;

    return newH;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = new ListNode(-1);
        ListNode* ansH = NULL;

        while(head != NULL){
            int cnt = 1;
            ListNode* left = head;
            while(head && cnt < k){
                cnt++;
                head = head->next;
            }
            
            if(cnt == k && head){
                ListNode* d = head->next;
                head->next = NULL;
                ListNode* subHead = reverse(left);

                temp->next = subHead;
                if(!ansH) ansH = temp->next;
                temp = left;
                left->next = NULL;
            
                head = d;
            }
            else temp->next = left;
        }
        return ansH;
    }
};