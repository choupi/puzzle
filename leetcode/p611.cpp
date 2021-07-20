// https://leetcode.com/problems/valid-triangle-number/
// 611. Valid Triangle Number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int total = 0;
        for (auto it0=nums.begin();it0!=nums.end()-2;it0++) {
            if (*it0==0) continue;
            for (auto it1=it0+1;it1!=nums.end()-1;it1++) {
                if (*it1==0) continue;
                int s = (*it1 + *it0)-1;
                auto it4 = upper_bound(it1+1, nums.end()-1, s);
                //cout <<*it0 << " " <<*it1 << " " << *it4 << " " << distance(it1, it4) << endl;
                total += distance(it1, it4);
                if (*it4>s) total -= 1;
                //cout << total << endl;
            }
        }
        return total;
    }
};
