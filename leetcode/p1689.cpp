class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for (auto c: n) {
            int t = c - '0';
            if (t>m) m = t;
        }
        return m;
    }
};
