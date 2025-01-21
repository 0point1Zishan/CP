void MyQueue:: push(int x)
{
        // Your Code
        QueueNode *a = new QueueNode(x);
        if(!front){
            front = a;
            rear = a;
        }
        else{
            rear->next = a;
            rear = a;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code   
        int val = -1;
        if(front){
            val = front->data;
            QueueNode *temp = front;
            front = front->next;
        }
        return val;
}