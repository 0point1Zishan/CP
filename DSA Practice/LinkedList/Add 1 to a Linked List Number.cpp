class Solution {
  private:
    int carry(Node* head){
        if(!head) return 1;
        int sum = carry(head->next) + head->data;
        head->data = sum % 10;
        return sum / 10;
    }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(carry(head)){
            Node* newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};