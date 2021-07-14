// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<int> tab(n2, 0);
        int mm = 0;
        for (int i=0;i<n1;i++) {
            for (int j=n2-1;j>0;j--) {
                if (nums1[i]==nums2[j]) tab[j]=tab[j-1]+1;
                else tab[j]=0;
                mm = max(mm, tab[j]);
            }
            if (nums1[i]==nums2[0]) tab[0]=1;
            else tab[0]=0;
            mm = max(mm, tab[0]);
        }
        return mm;
    }
};
