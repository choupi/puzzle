class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> tab(256, -1);
        vector<bool> alpha(256, false);
        int n = s.size();
        for (int i=0;i<n;i++) {
            int si = int(s[i]);
            int ti = int(t[i]);
            if (tab[si]>-1) {
                if (tab[si]!=ti) return false;
            } else if (alpha[ti]) {
                return false;
            } else {
                tab[si] = ti;
                alpha[ti] = true;
            }
        }
        return true;
    }
};
