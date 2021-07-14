// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    vector<int> bit;
    int n;
    int lowbit(int x) {
        return x & (-x);
    }
    void init() {
        bit.resize(n+1, 0);
    }
    void update(int i, int val) {
        while (i<=n) {
            //cout << "up" << i << endl;
            bit[i] += val;
            i += lowbit(i);
        }
    }
    int query(int i) {
        int r = 0;
        while (i>0) {
            //cout << "q " << i << endl;
            r += bit[i];
            i -= lowbit(i);
        }
        return r;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> rank;
        int ind = 1;
        for (int x: sorted) {
            rank[x] = ind;
            ind++;
        }
        vector<int> res(n, 0);
        init();
        for (int i=n-1;i>=0;i--) {
            //cout << nums[i] << " " << rank[nums[i]] << endl;
            res[i] = query(rank[nums[i]]-1);
            update(rank[nums[i]], 1);
        }
        return res;
    }
};
