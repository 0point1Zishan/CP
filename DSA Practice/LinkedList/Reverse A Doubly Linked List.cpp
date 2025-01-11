Node* reverseDLL(Node* head)
{   
    // Write your code here   
    Node* tail = head;
    while(tail->next != NULL) tail = tail->next;

    Node* temp1 = head;
    Node* temp2 = tail;

    while(temp1 != temp2 && temp1->next != temp2){

        swap(temp1->data, temp2->data);

        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    if(temp1->next == temp2) swap(temp1->data, temp2->data);

    return head;
}