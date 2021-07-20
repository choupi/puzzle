class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s = 0;
        for (int i=0;i<k;i++) {
            s += cardPoints[i];
        }
        int m = s;
        int n = cardPoints.size();
        for (int i=0;i<k;i++) {
            s -= cardPoints[k-i-1];
            s += cardPoints[n-i-1];
            if (s>m) m = s;
        }
        return m;
    }
};
