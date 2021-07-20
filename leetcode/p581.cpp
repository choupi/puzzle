class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i=0;i<nums.size();i++) {
            q.push({nums[i], i});
        }
        int mi = INT_MAX;
        int mm = INT_MIN;
        for (int j=0;j<nums.size();j++) {
            pair<int, int> p = q.top();
            q.pop();
            if (p.second == j) continue;
            else {
                cout << j <<" " << p.second<<endl;
                mi = min(min(mi, j), p.second);
                mm = max(max(mm, j), p.second);
            }
        }
        if (mi==INT_MAX && mm==INT_MIN) return 0;
        return mm - mi + 1;
    }
};
