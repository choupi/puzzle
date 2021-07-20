class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bd(26, 0);
        for (auto b: B) {
            vector<int> t(26, 0);
            for (char c: b) {
                int i = c-'a';
                t[i]++;
                if (bd[i]<t[i]) bd[i] = t[i];
            }
        }
        vector<int> bi;
        for (int i=0;i<26;i++) {
            if (bd[i]>0) bi.push_back(i);
        }
        vector<string> res;
        for (auto a: A) {
            vector<int> t(26, 0);
            for (char c: a) {
                int i = c-'a';
                t[i]++;
            }
            bool flag = true;
            for (int i: bi) {
                if (bd[i]>t[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(a);
        }
        return res;
    }
};
