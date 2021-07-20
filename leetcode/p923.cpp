class Solution {
public:
    int M = 1e9+7;
    unsigned int chosen(int n, int k) {
        if (k>n) return 0;
        if (k==n) return 1;
        if (k*2 > n) k = n-k;
        if (k==0) return 1;
        unsigned long long res = n;
        for (int i=2;i<=k;i++) {
            res *=n-i+1;
            res /= i;
            if (res>=M) res = res%M;
        }
        return res;
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        vector<int> table(101, 0);
        for (int i: arr) {
            table[i] += 1;
        }
        int total = 0;
        for (int i=0;i<101;i++) {
            if (table[i]==0) continue;
            for (int j=i;j<101;j++) {
                if (table[j]==0) continue;
                int t = target -i -j;
                if (t<j) break;
                if (t>100 || table[t]==0) continue;
                //cout << "ijt" << i << " " << j << " " << t << endl;
                if (i==j && j==t) {
                    total += chosen(table[i], 3) %M;
                } else if (i==j) {
                    total += (chosen(table[i], 2) * table[t]) %M;
                } else if (t==i) {
                    total += (chosen(table[i], 2) * table[j]) %M;
                } else if (t==j) {
                    total += (chosen(table[j], 2) * table[i]) %M;
                } else {
                    total += (table[i] * table[j] * table[t]) %M;
                }
                if (total >= M) total -= M;
            }
        }
        return total;
    }
};
