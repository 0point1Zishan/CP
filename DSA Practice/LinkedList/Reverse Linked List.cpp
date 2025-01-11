Node* reverseLinkedList(Node *head)
{
    // Write your code here
    if(head == NULL || head->next == NULL) return head;
    Node* nHead = reverseLinkedList(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return nHead;
}