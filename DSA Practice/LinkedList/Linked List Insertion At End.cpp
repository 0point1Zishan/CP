class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head == NULL){
            Node * a = new Node(x);
            head = a;
            return head;
        }
        Node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* a = new Node(x);
        temp->next = a;
        return head;
    }
};