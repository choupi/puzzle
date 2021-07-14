// 473. Matchsticks to Square
// https://leetcode.com/problems/matchsticks-to-square/

class Solution {
public:
    bool dfs(vector<int>& mat, vector<long long>& len, int ind, long long target) {
        if (ind<0) return len[0]==len[1] && len[1]==len[2] && len[2]==len[3];
        for (int j=0;j<4;j++) {
            if (len[j]+mat[ind]>target) continue;
            if (j>0 && len[j-1] == len[j]) continue;
            len[j] += mat[ind];
            if (dfs(mat, len, ind-1, target)) return true;
            len[j] -= mat[ind];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        long long total = 0;
        for (int m: matchsticks) total += m;
        if (total%4 != 0) return false;
        long long target = total/4;
        sort(matchsticks.begin(), matchsticks.end());
        vector<long long> len(4, 0);
        return dfs(matchsticks, len, matchsticks.size()-1, target);
    }
};
