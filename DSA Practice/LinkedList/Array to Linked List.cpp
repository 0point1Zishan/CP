class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i = 1; i < n; i++){
            Node *a = new Node(arr[i]);
            temp->next = a;
            temp = a;
        }
        return head;
    }
};