class MyHashMap {
public:
    /** Initialize your data structure here. */
    const int M = 16384;
    vector<vector<pair<int, int>>> table;
    MyHashMap() {
        table.resize(M);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = key % M;
        for (int i=0;i<table[k].size();i++) {
            if (table[k][i].first == key) {
                table[k][i] = {key, value};
                return;
            }
        }
        table[k].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k = key % M;
        for (int i=0;i<table[k].size();i++) {
            if (table[k][i].first == key) {
                return table[k][i].second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k = key % M;
        for (auto it=table[k].begin();it!=table[k].end();it++) {
            if (it->first == key) {
                table[k].erase(it);
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
