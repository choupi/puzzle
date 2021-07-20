class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int cur = 0;
        long long int total = 0;
        for (int i=0;i<customers.size();i++) {
            cur = (cur>customers[i][0] ? cur : customers[i][0]) + customers[i][1];
            total += cur - customers[i][0];
        }
        return total / double(customers.size());
    }
};
