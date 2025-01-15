vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int, int>> ans;
    Node *tail = head;
    while(tail->next != NULL) tail = tail->next;
    
    while(tail->data > head->data){
        int sum = head->data + tail->data;
        
        if(sum > k) tail = tail->prev;
        else if(sum < k) head = head->next;
        else{
            ans.push_back({head->data, tail->data});
            head = head->next;
            tail = tail->prev;
        }
    }
    return ans;
}