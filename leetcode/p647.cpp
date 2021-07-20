class Solution {
public:
    int countSubstrings(string s) {
        if (s.size()==0) return 0;
        queue<pair<int, int>> q;
        int total = 0;
        for (int i=0;i<s.size()-1;i++) {
            if (s[i]==s[i+1]) {
                total += 1;
                q.push({i, i+1});
            }
            q.push({i, i});
            total += 1;
        }
        q.push({s.size()-1, s.size()-1});
        total += 1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i-1>=0 && j+1<s.size() && s[i-1]==s[j+1]) {
                total += 1;
                q.push({i-1, j+1});
            }
        }
        return total;
    }
};
