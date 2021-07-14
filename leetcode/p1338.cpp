// 1338. Reduce Array Size to The Half
// https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> count(100001, 0);
        for (int x: arr) {
            count[x]++;
        }
        sort(count.rbegin(), count.rend());
        int cnt = arr.size()/2;
        int res = 0;
        //cout << count[0] << endl;
        for (res=0;cnt>0;res++) {
            cnt -= count[res];
        }
        return res;
    }
};
