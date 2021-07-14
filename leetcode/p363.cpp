// 363. Max Sum of Rectangle No Larger Than K
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(), n=matrix[0].size();
        int res = INT_MIN;
        for (int c=0;c<n;c++) {
            vector<int> tab(m, 0);
            for (int j=c;j<n;j++) {
                for (int i=0;i<m;i++) {
                    tab[i] += matrix[i][j];
                }
                set<int> st;
                st.insert(0);
                int ss = 0;
                for (int i=0;i<m;i++) {
                    ss += tab[i];
                    auto it = st.lower_bound(ss - k);
                    if (it!=st.end()) res = max(res, ss - *it);
                    if (res==k) return k;
                    st.insert(ss);
                }
            }
        }
        return res;
    }
};
