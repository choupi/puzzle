class Solution {
public:
    bool match(string s, string a) {
        int i = 0;
        int j = 0;
        while (i<s.size() && j<a.size()) {
            if (s[i]==a[j]) {
                j++;
            }
            i++;
        }
        return j == a.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (string a: d) {
            if (match(s, a)) {
                if (a.size() > res.size()) res = a;
                else if (a.size() == res.size() && a<res) res = a;
            }
        }
        return res;
    }
};
