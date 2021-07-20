class Solution {
public:
    vector<int> lorder;
    bool cmp(string& w1, string& w2) {
        int l = min(w1.size(), w2.size());
        //cout << w1 << " " << w2 << endl;
        for (int i=0;i<l;i++) {
            if (lorder[w1[i]-'a']>lorder[w2[i]-'a']) return false;
            else if (lorder[w1[i]-'a']<lorder[w2[i]-'a']) return true;
            //cout << i << endl;
        }
        if (w1.size()>w2.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        lorder.resize(26);
        for (int i=0;i<order.size();i++) {
            lorder[order[i]-'a'] = i;
        }
        //cout << "lorder done" << endl;
        for (int i=1;i<words.size();i++) {
            if (!cmp(words[i-1], words[i])) return false;
        }
        return true;
    }
};
