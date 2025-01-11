int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;

    bool isCycle = false;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            isCycle = true;
            break;
        }
    }
    if(!isCycle) return 0;
    int cnt = 0;
    fast = fast->next;
    while(slow != fast){
        fast = fast->next;
        cnt++;
    }
    return cnt+1;
}