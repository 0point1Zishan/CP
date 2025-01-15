class Solution {
private:
    void AddNextCopyList(Node* head){
        Node* temp = head;
        while(temp){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }

    void AddRandomCopyList(Node* head){
        Node* temp = head;
        while(temp){
            Node* copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode->random = NULL;
            temp = temp->next->next;
        }
    }

    Node* Extract(Node* head){
        Node* dNode = new Node(-1);
        Node* res = dNode;
        Node* temp = head;
        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;
    }
public:
    Node* copyRandomList(Node* head) {
        AddNextCopyList(head);
        AddRandomCopyList(head);
        return Extract(head);
    }
};