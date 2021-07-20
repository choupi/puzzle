class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        // 3**19 = 1,162,261,467
        // 3**20 = 3,486,784,401 > 2**31
        int M = 19;
        int t = 1;
        for (int i=0;i<M;i++) {
            if (t == n) return true;
            t *= 3;
        }
        if (t == n) return true;
        return false;
    }
};
