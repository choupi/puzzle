class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while (num>0) {
            cnt += num & 1;
            if (num>1) cnt += 1;
            num = num >> 1;
        }
        return cnt;
    }
};
