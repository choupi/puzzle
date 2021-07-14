// 1220. Count Vowels Permutation
// https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    int A=0, E=1, I=2, O=3, U=4;
    int M = 1000000007;
    int countVowelPermutation(int n) {
        vector<unsigned int> tab0(5, 1);
        vector<unsigned int> tab1(5, 0);
        for (int i=1;i<n;i++) {
            tab1[A] = (tab0[E] + tab0[I] + tab0[U]) % M;
            tab1[E] = (tab0[A] + tab0[I]) % M;
            tab1[I] = (tab0[E] + tab0[O]) % M;
            tab1[O] = tab0[I];
            tab1[U] = (tab0[I] + tab0[O]) % M;
            tab1.swap(tab0);
        }
        int s = 0;
        for (int i=0;i<5;i++) s = (s + tab0[i]) % M;
        return s;
    }
};
