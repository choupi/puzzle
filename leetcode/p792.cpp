// 792. Number of Matching Subsequences
// https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> q(26, vector<pair<int, int>>());
        for (int i=0;i<words.size();i++) {
            char c = words[i][0];
            q[c-'a'].push_back({i, 0});
        }
        int total = 0;
        for (char c: s) {
            auto ws = q[c-'a'];
            q[c-'a'].clear();
            for (auto p: ws) {
                if (p.second+1>=words[p.first].size()) total++;
                else {
                    char cc = words[p.first][p.second+1];
                    q[cc-'a'].push_back({p.first, p.second+1});
                }
            }
        }
        return total;
    }
};
