class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<unsigned int> pq;
        long long s=0;
        for (auto i: target) {
            pq.push(i);
            s+=i;
        }
        while (!pq.empty()) {
            unsigned int t = pq.top();
            pq.pop();
            if (t==1) return true;
            s -= t;
            if (t<=s || s<1) return false;
            unsigned int r = t % s;
            pq.push(r);
            s += r;
        }
        return false;
    }
};
