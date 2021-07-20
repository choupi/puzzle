class Solution {
public:
    bool check(string& word, string& pattern) {
        vector<int> wm(26, -1);
        vector<int> pm(26, -1);
        for (int i=0;i<word.size();i++) {
            int wi = word[i]-'a';
            int pi = pattern[i]-'a';
            if (wm[wi] == -1) {
                if (pm[pi] != -1) return false;
                wm[wi] = pi;
                pm[pi] = wi;
                continue;
            } else if (wm[wi]!=pi) {
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto w: words) {
            if (check(w, pattern)) res.push_back(w);
        }
        return res;
    }
};
