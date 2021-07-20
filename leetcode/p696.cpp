class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.size()<2) return 0;
        int total=0, i=1;
        while (i<s.size()) {
            //cout << i << endl;
            if (s[i]==s[i-1]) {
                i++;
                continue;
            }
            int j = i-1;
            while (i<s.size() && j>=0 && s[i]!=s[j]) {
                //cout << i << " " << j << endl;
                total++;
                i++;
                j--;
                if (s[i] != s[i-1]) break;
            }
        }
        return total;
    }
};
