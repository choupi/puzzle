// https://leetcode.com/problems/three-equal-parts/
// 927. Three Equal Parts

class Solution {
public:
    int find1(vector<int> &arr, int i) {
        while (arr[i]!=1) i++;
        return i;
    }
    int count1(vector<int> &arr, int i, int cnt) {
        while (cnt>0) {
            if (arr[i]==1) cnt--;
            i++;
        }
        return i;
    }
    int count1_cmp(vector<int> &arr, int i, int t, int cnt) {
        while (cnt>0) {
            if (arr[i]!=arr[t]) return -1;
            if (arr[i]==1) cnt--;
            i++;
            t++;
        }
        return i;
    }
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        for (int x: arr) {
            cnt += x;
        }
        if (cnt==0) return {0, n-1};
        if (cnt%3!=0) return {-1, -1};
        reverse(arr.begin(), arr.end());
        int r0 = find1(arr, 0);
        int r1 = count1(arr, r0, cnt/3);
        int m0 = find1(arr, r1);
        if (m0-r1<r0) return {-1, -1};
        int m1=count1_cmp(arr, m0, r0, cnt/3);
        if (m1<0) return {-1, -1};
        //cout << "m " << m0 << " " << m1 << endl;
        int l0 = find1(arr, m1);
        if (l0-m1<r0) return {-1, -1};
        int l1 = count1_cmp(arr, l0, r0, cnt/3);
        if (l1<0) return {-1, -1};
        //cout << "l " << l0 << " " << l1 << endl;
        return {n - (l0-r0)-1, n - (m0-r0)};
    }
};
