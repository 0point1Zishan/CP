class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) cnt++, temp = temp->next;
        return cnt;
    }
};