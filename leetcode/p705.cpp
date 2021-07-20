class MyHashSet {
public:
    vector<list<int>> table;
    const int M = 16384;
    /** Initialize your data structure here. */
    MyHashSet() {
        table.resize(16384);
    }
    
    void add(int key) {
        if (contains(key)) return;
        int k = key % M;
        table[k].push_back(key);
    }
    
    void remove(int key) {
        int k = key % M;
        table[k].remove(key);
        return;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = key % M;
        for (int i: table[k]) {
            if (i == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
