// 336. Palindrome Pairs
// https://leetcode.com/problems/palindrome-pairs/

class Solution {
public:
    bool check(string s) {
        int n = s.size();
        for (int i=0;i<n/2;i++) {
            if (s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int empty_word = -1;
        for (int i=0;i<words.size();i++) {
            if (words[i].size()==0) {
                empty_word = i;
                continue;
            }
            string t(words[i].rbegin(), words[i].rend());
            mp[t] = i;
        }
        vector<vector<int>> res;
        for (int i=0;i<words.size();i++) {
            if (words[i].size()==0) continue;
            if (empty_word >= 0 && check(words[i])) {
                res.push_back({i, empty_word});
                res.push_back({empty_word, i});
            }
            string left, right;
            for (int j=0;j<words[i].size();j++) {
                left.push_back(words[i][j]);
                right = words[i].substr(j+1);
                if (mp.count(left) && mp[left]!=i && check(right)) {
                    res.push_back({i, mp[left]});
                }
                if (mp.count(right) && mp[right]!=i && check(left)) {
                    res.push_back({mp[right], i});
                }
            }
        }
        return res;
    }
};
