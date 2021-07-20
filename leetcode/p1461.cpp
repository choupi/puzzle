class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> kset;
        int kcnt = 1 << k;
        int len = s.size();
        //cout << len-k+1<< endl;
        for (int i=0;i<len-k+1;i++) {
            //cout << s.substr(i, k) << endl;
            kset.insert(s.substr(i, k));
            if (kset.size() == kcnt) return true;
        }
        return false;
    }
};
