// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

typedef tuple<int, int, int> TP;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (k==1) return matrix[0][0];
        int n=matrix.size();
        if (k==n*n) return matrix[n-1][n-1];
        priority_queue<TP, vector<TP>, greater<TP>> pq;
        for (int i=0;i<n;i++) {
            pq.emplace(matrix[i][0], i, 0);
        }
        int x, i, j;
        for (int c=0;c<k;c++) {
            tie(x, i, j) = pq.top();
            pq.pop();
            if (j==n-1) continue;
            pq.emplace(matrix[i][j+1], i, j+1);
        }
        return x;
    }
};
