// https://leetcode.com/problems/4sum/
// 18. 4Sum

class Solution {
public:
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
    };
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        unordered_set<vector<int>, VectorHash> st;
        if (n<4) return res;
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        int p, q;
        for (int i=0;i<n;i++) {
            for (int j=n-1;j>i;j--) {
                int p=i+1, q=j-1;
                int s = nums[i] + nums[j];
                while (p<q) {
                    int ss = s + nums[p] + nums[q];
                    if (ss==target) {
                        st.insert({nums[i], nums[p], nums[q], nums[j]});
                        p++;
                        q--;
                    } else if (ss>target) q--;
                    else p++;
                }
            }
        }
        for (auto v: st) {
            res.push_back(v);
        }
        return res;
    }
};
