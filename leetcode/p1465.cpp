// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int mh = 0;
        for (int i=1;i<horizontalCuts.size();i++) {
            int t = horizontalCuts[i] - horizontalCuts[i-1];
            mh = max(mh, t);
        }
        int mw = 0;
        for (int i=1;i<verticalCuts.size();i++) {
            int t = verticalCuts[i] - verticalCuts[i-1];
            mw = max(mw, t);
        }
        //cout << mh << " " << mw << endl;
        int r = ((long long)mh * mw) % (1000000000 + 7);
        return r;
    }
};
