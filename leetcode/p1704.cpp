class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> ALPHAS({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int ta=0;
        int i;
        for (i=0;i<s.size()/2;i++) {
            if (ALPHAS.find(s[i])!=ALPHAS.end()) ta++;
        }
        for (;i<s.size();i++) {
            if (ALPHAS.find(s[i])!=ALPHAS.end()) {
                ta--;
            }
        }
        return ta==0;
    }
};
