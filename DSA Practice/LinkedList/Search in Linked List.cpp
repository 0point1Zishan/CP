class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == key) return true;
            temp = temp->next;
        }return false;
    }
};