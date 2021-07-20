class Solution {
public:
    int minOperations(int n) {
        int st = n&1 ? 0 : 1;
        return (st+n-1)*((n+1)/2)/2;
    }
};
