class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i=0;i<A.size()-1;i++) {
            if (A[i]>A[i+1] && (A[i]!=i+1 || A[i+1]!=i)) return false;
        }
        return true;
    }
};
