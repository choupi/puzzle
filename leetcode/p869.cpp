class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if (N == 1e9) return false;
        int d=1, dd=10;
        int d2=1;
        while (dd<=N) {
            d = dd;
            dd *= 10;
        }
        while (d2<d) {
            d2 = d2 << 1;
        }
        string ns = to_string(N);
        sort(ns.begin(), ns.end());
        while (d2<dd) {
            bool flag = true;
            string ds = to_string(d2);
            sort(ds.begin(), ds.end());
            if (ds==ns) return true;
            d2 = d2 << 1;
        }
        return false;
    }
};
