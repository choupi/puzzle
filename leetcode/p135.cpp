// 135. Candy
// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> arr;
        vector<int> candy(n, 1);
        for (int i=0;i<n;i++) {
            arr.push_back({ratings[i], i});
        }
        sort(arr.begin(), arr.end());
        int total = 0;
        for (auto [r, i]: arr) {
            int c = candy[i];
            if (i>0 && r>ratings[i-1] && c<=candy[i-1]) c = candy[i-1]+1;
            if (i<n-1 && r>ratings[i+1] && c<=candy[i+1]) c = candy[i+1]+1;
            candy[i] = c;
            total += c;
        }
        return total;
    }
};
