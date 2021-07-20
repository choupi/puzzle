class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size()<3) return 0;
        int total = 0;
        int i=0;
        while (i < A.size()-2) {
            //cout << i << A[i] << endl;
            int d = A[i+1] - A[i];
            int j = i + 2;
            for (;j<A.size();j++) {
                if (A[j]-A[j-1] != d) break;
            }
            int n = j - i - 2;
            //cout << i << j << n << endl;
            total += n*(n+1)/2;
            i = j-1;
        }
        return total;
    }
};
