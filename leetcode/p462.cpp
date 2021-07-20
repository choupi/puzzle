class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int nl = nums.size();
        int med = nl%2==1?nums[nl/2]:(nums[nl/2]+nums[nl/2-1])/2;
        //cout << nl << " " << med << endl;
        int tot = 0;
        for (int n: nums) {
            //cout << n -med << endl;
            tot += abs(n - med);
        }
        return tot;
    }
};
