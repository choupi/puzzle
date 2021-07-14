// 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        if (m*n != r*c) return mat;
        if (m==r && n==c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int rr=0, cc=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                res[rr][cc] = mat[i][j];
                cc++;
                if (cc==c) {
                    rr++;
                    cc=0;
                }
            }
        }
        return res;
    }
};
