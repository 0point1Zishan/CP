Node* merge(Node* a, Node* b){
	Node* head = new Node(-1);
	Node* temp = head;
	while(a && b){
		if(a->data < b->data){
			head->child = a;
			a = a->child;
		}
		else{
			head->child = b;
			b = b->child;
		}
		head = head->child;
		head->next = NULL;
	}
	if(a)     head->child = a;
	else       head->child = b;
	
	if(temp->child) temp->child->next = NULL;
	return temp->child;
}

Node* flattenLinkedList(Node* head){
    if(!head || !head->next) return head;
	Node* down = head;
	Node* newH = flattenLinkedList(head->next);
	down->next = NULL;
	return merge(newH, down);
}