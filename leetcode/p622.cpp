class MyCircularQueue {
private:
    int front;
    int back;
    int cap;
    int count;
    vector<int> table;
public:
    MyCircularQueue(int k) {
        front = 0;
        back = 0;
        cap = k;
        count = 0;
        table.resize(k, -1);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        table[back] = value;
        back = (back+1)%cap;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        table[front] = -1;
        front = (front+1)%cap;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return table[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return table[(back+cap-1)%cap];
    }
    
    bool isEmpty() {
        if (count == 0) return true;
        return false;
    }
    
    bool isFull() {
        if (count == cap) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
