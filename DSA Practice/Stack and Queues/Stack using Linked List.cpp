class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode *a = new StackNode(x);
        a->next = top;
        top = a;
    }

    int pop() {
        // code here
        int val = -1;
        if(top != NULL){
            val = top->data;
            StackNode *temp = top;
            top = top->next;
            delete temp;
        }
        return val;
    }

    MyStack() { top = NULL; }
};