class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        bool neg = false;
        if (num<0) {
            neg = true;
            num = -num;
        }
        string r = "";
        while (num>0) {
            int t = num%7;
            r.append(1, '0'+t);
            num = num/7;
        }
        if (neg) r.append(1, '-');
        reverse(r.begin(), r.end());
        return r;
    }
};
