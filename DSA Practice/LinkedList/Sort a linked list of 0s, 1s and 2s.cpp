class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* zeroH = zero;
        Node* oneH = one;
        Node* twoH = two;
        
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0)     zero->next = temp, zero = zero->next;
            else if(temp->data == 1)   one->next = temp, one = one->next;
            else  two->next = temp, two = two->next;
            temp = temp->next;
        }
        two->next = NULL;
        one->next = twoH->next;
        zero->next = oneH->next;
        
        return zeroH->next;
    }
};