// 89. Gray Code
// https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res({0, 1});
        for (int i=1;i<n;i++) {
            int d = 1<<i;
            int l = res.size();
            for (int j=l-1;j>=0;j--) res.push_back(res[j]+d);
        }
        return res;
    }
};
