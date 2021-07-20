class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        vector<bool> table(n, true);
        table[0] = false;
        table[1] = false;
        int total = n-2;
        for (int i=2;i<sqrt(n)+1;i++) {
            if (!table[i]) continue;
            for (int j=i+i;j<n;j+=i) {
                if (table[j]) {
                    table[j] = false;
                    total--;
                }
            }
        }
        return total;
    }
};
