Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp = head;
    while(temp != NULL){
        
        Node* temp1 = temp->next;
        while(temp1 != NULL && temp1->data == temp->data){
            free(temp1);
            temp1 = temp1->next;
        }
        if(temp1) temp1->prev = temp;
        temp->next = temp1;
        temp = temp1;
    }
    return head; 
}