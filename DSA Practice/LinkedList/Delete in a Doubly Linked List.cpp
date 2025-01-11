class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        
        if(x == 1){
            head = head->next;
            head->prev = NULL;
            return head;
        }
        
        Node* temp = head;
        int cnt = 2;
        while(cnt < x && temp->next != NULL){ 
            temp = temp->next;
            cnt++;
        }
        // cout << temp->data << "\n";
        
        temp->next = temp->next->next;
        if(temp->next != NULL) temp->next->prev = temp;
        return head;
    }
};