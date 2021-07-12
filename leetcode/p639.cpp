// 639. Decode Ways II
// https://leetcode.com/problems/decode-ways-ii/

class Solution {
public:
    int M = 1000000007;
    int numDecodings(string s) {
        int n = s.size();
        vector<int> tab(n+1, 0);
        tab[0] = 1;
        for (int i=0;i<n;i++) {
            if (s[i]=='*') {
                tab[i+1] = ((long long)tab[i] * 9)%M ;
                if (i>0) {
                    if (s[i-1]=='1') tab[i+1] = (tab[i+1] + ((long long)tab[i-1] * 9)%M)%M;
                    else if (s[i-1]=='2') tab[i+1] = (tab[i+1] + ((long long)tab[i-1] * 6)%M)%M;
                    else if (s[i-1]=='*') tab[i+1] = (tab[i+1] + ((long long)tab[i-1] * 15)%M)%M;
                }
            } else if (s[i]=='0') {
                if (i>0 ) {
                    if (s[i-1]=='1' || s[i-1]=='2') {
                        tab[i+1] = tab[i-1];
                    } else if (s[i-1]=='*') {
                        tab[i+1] = (tab[i+1] + ((long long)tab[i-1] * 2)%M)%M;
                    }
                }
            } else {
                tab[i+1] = tab[i];
                if (i>0) {
                    if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<'7')) {
                        tab[i+1] = (tab[i+1] + tab[i-1])%M;
                    } else if (s[i-1]=='*') {
                        if (s[i]<'7') {
                            tab[i+1] = (tab[i+1] + ((long long)tab[i-1] * 2)%M)%M;
                    } else {
                            tab[i+1] = (tab[i+1] + tab[i-1])%M;
                        }
                    }
                }
            }
            //cout << s[i] << " " << tab[i+1] << endl;
        }
        return tab[n];
    }
};
