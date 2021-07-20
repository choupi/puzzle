class Solution {
public:
    static bool cmp(string w1, string w2) {
        return w1.size() > w2.size();
    }
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        sort(words.begin(), words.end(), cmp);
        for (int i=0;i<words.size();i++) {
            for (auto c: words[i]) {
                mask[i] |= 1 << (c-'a');
            }
        }
        int m = 0;
        for (int i=0;i<words.size();i++) {
            if (m>=words[i].size()*words[i].size()) break;
            //cout << words[i] << mask[i] << endl;
            for (int j=i+1;j<words.size();j++) {
                //cout << words[j] << mask[j] << endl;
                //cout << (mask[i] & mask[j]) << endl;
                if ((mask[i] & mask[j]) == 0) {
                    int t = words[i].size() * words[j].size();
                    m = max(m, t);
                    break;
                }
            }
        }
        return m;
    }
};
