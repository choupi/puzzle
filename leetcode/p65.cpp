class Solution {
public:
    bool isInt(string s) {
        if (s.size()<1) return false;
        int i=0;
        if (s[0] == '+' || s[0] == '-') {
            if (s.size()<2) return false;
            i=1;
        }
        for (;i<s.size();i++) {
            if (s[i]<'0' || s[i]>'9') return false;
        }
        return true;
    }
    bool isDecimal(string s) {
        if (s.size()<1) return false;
        int i=0;
        if (s[0] == '+' || s[0] == '-') {
            if (s.size()<2) return false;
            i=1;
        }
        int dot = 0;
        int dig = 0;
        for (;i<s.size();i++) {
            if (s[i] == '.') {
                dot++;
                if (dot>1) return false;
            } else if (s[i] == 'e' || s[i] == 'E') {
                return dig>0 && isInt(s.substr(i+1));
            } else if (s[i]<'0' || s[i]>'9') return false;
            else dig++;
        }
        return dig>0;
    }
    bool isNumber(string s) {
        return isInt(s) || isDecimal(s);
    }
};
