class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i=2;i<=n;i++) {
            string s;
            int c = 1;
            for (int j=1;j<str.size();j++) {
                if (str[j]!=str[j-1]) {
                    s += to_string(c);
                    s += str[j-1];
                    c = 1;
                } else c++;
            }
            s += to_string(c);
            s += str[str.size()-1];
            str = s;
        }
        return str;
    }
};
