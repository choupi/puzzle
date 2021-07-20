// https://leetcode.com/problems/shuffle-an-array/
// 384. Shuffle an Array

class Solution {
public:
    vector<int>& array;
    Solution(vector<int>& nums):array(nums) {
        return;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(array);
        int n = res.size();
        for (int i=0;i<n;i++) {
            int t = rand()%(n-i) + i;
            swap(res[i], res[t]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
