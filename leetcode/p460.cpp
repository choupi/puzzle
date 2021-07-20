class LFUCache {
public:
    vector<list<int>> freq;
    vector<tuple<int, int, list<int>::iterator>> keys;
    int K;
    int cap;
    int min_freq;
    LFUCache(int capacity) {
        freq.resize(2);
        keys.resize(10001, {-1, 0, freq[0].end()});
        cap = capacity;
        K = 0;
        min_freq = 0;
    }
    
    int get(int key) {
        auto [v, fq, it] = keys[key];
        if (v==-1) return -1;
        freq[fq].erase(it);
        if (freq.size()<fq+2) freq.push_back(list<int>());
        //cout << freq.size() << "+++" << fq << endl;
        freq[fq+1].push_back(key);
        it = freq[fq+1].end();
        it--;
        std::get<1>(keys[key]) = fq+1;
        std::get<2>(keys[key]) = it;
        if (fq == min_freq && freq[fq].empty()) min_freq = fq+1;
        return v;
    }
    
    void put(int key, int value) {
        if (cap==0) return;
        else if (get(key)!= -1) {
            auto [v, fq, it] = keys[key];
            std::get<0>(keys[key]) = value;
            return;
        } else if (K==cap) {
            int q = freq[min_freq].front();
            freq[min_freq].pop_front();
            std::get<0>(keys[q]) = -1;
            std::get<1>(keys[q]) = 0;
            K--;
        }
        min_freq = 1;
        freq[1].push_back(key);
        auto it = freq[1].end();
        it--;
        std::get<0>(keys[key]) = value;
        std::get<1>(keys[key]) = 1;
        std::get<2>(keys[key]) = it;
        K++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
