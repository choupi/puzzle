// 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k==arr.size()) return arr;
        int i, j;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        i = distance(arr.begin(), it);
        //cout << i << *it << endl;
        if (it!=arr.end() && *it == x) {
            j = i+1;
        } else {
            j = i;
            i--;
        }
        for (int kk=0;kk<k;kk++) {
            cout << i << " " << j << endl;
            if (i<0) j++;
            else if (j==arr.size()) i--;
            else if (abs(arr[i]-x)<=abs(arr[j]-x)) i--;
            else j++;
        }
        vector<int> res;
        for (i++;i<j;i++) res.push_back(arr[i]);
        return res;
    }
};
