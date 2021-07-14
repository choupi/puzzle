// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int>& _nums;
    vector<int> bit;
    int n;
    int lowbit(int x) {
        return x&(-x);
    }
    
    NumArray(vector<int>& nums): _nums(nums) {
        n = nums.size();
        bit.resize(n+1, 0);
        for (int i=0;i<n;i++) {
            _update(i, nums[i]);
        }
    }
    
    void _update(int i, int val) {
        i++;
        while (i<=n) {
            bit[i] += val;
            i += lowbit(i);
        }
    }
    void update(int index, int val) {
        int _val = val - _nums[index];
        _nums[index] = val;
        _update(index, _val);
    }
    
    int getSum(int i) {
        int total = 0;
        while (i>0) {
            total += bit[i];
            i -= lowbit(i);
        }
        return total;
    }
    int sumRange(int left, int right) {
        return getSum(right+1) - getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
