class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b){
            a = (a != NULL) ? a->next : headB;
            b = (b != NULL) ? b->next : headA;
        }
        return a;
    }
};