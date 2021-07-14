// 1710. Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1]==b[1]?a[0]>a[0]:a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int room = truckSize;
        int res = 0;
        for (int i=0;i<boxTypes.size();i++) {
            if (boxTypes[i][0] > room) {
                res += room * boxTypes[i][1];
                room = 0;
                break;
            } else {
                room -= boxTypes[i][0];
                res += boxTypes[i][0] * boxTypes[i][1];
            }
        }
        return res;
    }
};
