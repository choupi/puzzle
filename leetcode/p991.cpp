class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        int shift = 0;
        while (X < Y) {
            X = X << 1;
            shift++;
        }
        int df = X - Y;
        int cnt = 0;
        for (int i=0;i<shift;i++) {
            if (df == 0) break;
            cnt += df & 1;
            df = df >> 1;
        }
        return shift + cnt + df;
    }
};
