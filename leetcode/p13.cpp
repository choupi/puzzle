class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        int l = s.size()-1;
        for (int i=0;i<s.size();i++) {
            // I, V, X, L, C, D and M
            if (s[i] == 'M') {
                n += 1000;
            } else if (s[i] == 'D') {
                n += 500;
            } else if (s[i] == 'C') {
                if (i<l && s[i+1] == 'D') {
                    n += 400;
                    i++;
                } else if (i<l && s[i+1] == 'M') {
                    n += 900;
                    i++;
                } else {
                    n += 100;
                }
            } else if (s[i] == 'L') {
                n += 50;
            } else if (s[i] == 'X') {
                if (i<l && s[i+1] == 'L') {
                    n += 40;
                    i++;
                } else if (i<l && s[i+1] == 'C') {
                    n += 90;
                    i++;
                } else {
                    n += 10;
                }
            } else if (s[i] == 'V') {
                n += 5;
            } else if (s[i] == 'I') {
                if (i<l && s[i+1] == 'V') {
                    n += 4;
                    i++;
                } else if(i<l && s[i+1] == 'X') {
                    n += 9;
                    i++;
                } else {
                    n += 1;
                }
            }
        }
        return n;
    }
};
