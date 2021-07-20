class Solution {
public:
    int concatenatedBinary(int n) {
        int M = 1000000007;
        unsigned long long int total=1;
        int i=2, b=1;
        while (i<=n) {
            b++;
            int t = 1 << b;
            //cout << b << endl;
            for (;i<t;i++) {
                total = (total << b) + i;
                //cout << total << endl;
                if (total >= M) total = total%M;
                if (i == n) return total;
            }
        }
        return total;
    }
};
