class FreqStack {
public:
    unordered_map<int, int> cnt_map;
    priority_queue<tuple<int, int, int>> pq;
    int ts = 0;
    
    FreqStack() {
        ts = 0;
    }
    
    bool check(int x, int cnt) {
        return cnt_map[x] == cnt;
    }
    
    void push(int x) {
        cnt_map[x]++;
        pq.push({cnt_map[x], ts, x});
        ts++;
    }
    
    int pop() {
        auto [cnt, t, x] = pq.top();
        pq.pop();
        cnt_map[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
