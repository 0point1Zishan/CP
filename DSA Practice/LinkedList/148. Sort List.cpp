class Solution {
public:
    void merge(ListNode*& left, ListNode*& right){

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left != NULL) temp->next = left;
        if(right != NULL) temp->next = right;
        
        left = head->next;
        delete head;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;    
    }

    void mergeSort(ListNode*& head){
        if(head == NULL || head->next == NULL) return;

        ListNode* mid = middle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        mergeSort(head);
        mergeSort(right);
        merge(head, right);
    }
    ListNode* sortList(ListNode* head) {
        mergeSort(head);
        return head;
    }
};