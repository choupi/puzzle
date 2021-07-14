// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i=1;i<numRows;i++) {
            res.push_back({1});
            for (int j=1;j<res[i-1].size();j++) {
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
