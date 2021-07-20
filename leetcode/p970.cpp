class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        int xx=1;
        while (xx<bound) {
            int yy=1;
            while (xx+yy<=bound) {
                res.insert(xx+yy);
                if (y==1) break;
                yy *= y;
            }
            if (x==1) break;
            xx *= x;
        }
        vector<int> result;
        result.insert(result.end(), res.begin(), res.end());
        return result;
    }
};
