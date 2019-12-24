class MinStack {

public:

    class NodeList 
    {
    public:
        int val;
        NodeList* prev;
        NodeList* prev_min;
        NodeList (int val, NodeList* prev) {

            this->val = val;
            this->prev_min = prev;
            prev = NULL;
        }
    } *head, *min_node;

    /** initialize your data structure here. */
    MinStack() {
        min_node = head = NULL;         
    }
    
    void push(int x) {
        NodeList* node = new NodeList (x, head);
        node->prev = head;
        head = node;
        min_node = (min_node == NULL || (node->val < min_node->val)) ? node : min_node;  
    }
    
    void pop() {
        NodeList* node = head;
        if (min_node == node) {
            min_node = node->prev_min;
        }
        head = head->prev;
        delete node;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return min_node->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */