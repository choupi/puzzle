class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        res.assign(s.size(), INT_MAX);
        int distance = INT_MAX;
        for (int i=0;i<s.size();i++) {
            if (s[i] == c) {
                distance = 0;
            }
            if (res[i] > distance) {
                res[i] = distance;
            }
            if (distance < INT_MAX) {
                distance++;
            }
        }
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i] == c) {
                distance = 0;
            }
            if (res[i] > distance) {
                res[i] = distance;
            }
            if (distance < INT_MAX) {
                distance++;
            }
        }
        return res;
    }
};
