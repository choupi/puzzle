class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        for (int i=0;i<s.size()/2;i++) {
            if (s[i] != s[s.size()-i-1]) {
                return 2;
            }
        }
        return 1;
    }
};
