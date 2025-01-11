class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        int cnt = 0;
        Node* temp = head;
        while(cnt < pos && temp->next != NULL){
            cnt++;
            temp = temp->next;
        }
        
        Node* a = new Node(data);
        
        a->next = temp->next;
        if(temp->next != NULL) temp->next->prev = a;
        
        temp->next = a;
        a->prev = temp;
        
        
        return head;
    }
};