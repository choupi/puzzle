class Solution {
public:
    const int M = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, vector<pair<int, int>>> pmap;
        vector<int> table(arr.size(), -1);
        for (int i=0;i<arr.size();i++) {
            pmap[arr[i]] = vector<pair<int, int>>(0);
        }
        for (int i=0;i<arr.size();i++) {
            for (int j=i;j<arr.size();j++) {
                long long t = (long long)arr[i] * (long long)arr[j];
                if (t<=1e9 && pmap.find((int)t) != pmap.end()) {
                    pmap[(int)t].push_back({i, j});
                }
            }
        }
        for (int i=0;i<table.size();i++) {
            table[i] = 1;
            for (auto p: pmap[arr[i]]) {
                int t = ((long long)table[p.first]*(long long)table[p.second]) % M;
                if (p.first!=p.second) table[i] += (2*t)%M;
                else table[i] += t;
                if (table[i]>=M) table[i] -= M;
            }
        }
        int res = 0;
        for (int i=0;i<table.size();i++) {
            //cout << i << " " << table[i] << endl;
            res += table[i];
            if (res>=M) res -= M;
        }
        return res;
    }
};
