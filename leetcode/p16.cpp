class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (auto i=nums.begin();i!=nums.end()-2;i++) {
            for (auto j=i+1;j!=nums.end()-1;j++) {
                int d = target - *i - *j;
                int m = nums[nums.size()-1];
                int mm = *(j+1);
                int t, tt;
                if (d==m || d==mm) return target;
                if (d<mm) t = *i + *j + mm;
                else if (d>m) t = *i + *j + m;
                else {
                    auto k = lower_bound(j+1, nums.end(), d);
                    t = *i + *j + *k;
                    //cout << *i << *j << "@" << *k << " " << t << endl;
                    if (k-1 != j) {
                        tt = *i + *j + *(k-1);
                        if (abs(target-t)>abs(target-tt)) t = tt;
                    }
                }
                //cout << *i << *j << " " << m << mm << " " << d << " " << t << endl;
                if (t == target) return target;
                if (abs(target-closest) > abs(target-t)) closest = t;
            }
        }
        return closest;
    }
};
