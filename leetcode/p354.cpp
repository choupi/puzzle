class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> table;
        sort(envelopes.begin(), envelopes.end(), cmp);
        table.push_back(envelopes[0][1]);
        for (int i=1;i<envelopes.size();i++) {
            if (envelopes[i][1] > table[table.size()-1]) {
                table.push_back(envelopes[i][1]);
            } else {
                auto it = lower_bound(table.begin(), table.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return table.size();
    }
};
