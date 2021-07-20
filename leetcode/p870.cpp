class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<pair<int, int>> BB(B.size());
        for (int i=0;i<B.size();i++) {
            BB[i] = {B[i], i};
        }
        sort(BB.begin(), BB.end());
        vector<int> res(B.size(), -1);
        int a=0, b=0;
        while (a<A.size() && b<B.size()) {
            if (A[a]>BB[b].first) {
                res[BB[b].second] = A[a];
                A[a] = -1;
                b++;
            }
            a++;
        }
        a = 0;
        for (int i=0;i<res.size();i++) {
            if (res[i]!=-1) continue;
            while (A[a]==-1) a++;
            res[i] = A[a];
            a++;
        }
        return res;
    }
};
