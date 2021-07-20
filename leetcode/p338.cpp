class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        while (1) {
            int l = res.size();
            for (int j=0;j<l;j++) {
                //cout << res[j] << endl;
                if (res.size() == num+1) return res;
                res.push_back(res[j]+1);
            }
        }
        //cout << res.size();
        return res;
    }
};
