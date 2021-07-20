class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i=0;i<mat.size();i++) {
            int c = 0;
            for (int j=0;j<mat[i].size();j++) {
                if (mat[i][j]!=1) break;
                c += 1;
            }
            pair<int, int> row = {c, i};
            if (pq.size()==k && row>pq.top()) continue;
            if (pq.size()==k) pq.pop();
            pq.push(row);
            //cout << c << i << endl;
        }
        vector<int> res(k, 0);
        for (int i=0;i<k;i++) {
            pair<int, int> row = pq.top();
            pq.pop();
            res[i] = row.second;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
