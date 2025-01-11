Node * deleteLastNode(Node *head) {
    // Write your code here
    if(head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != NULL)  temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    return head;
}