class Solution {
public:
    vector<int> nums{0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string gen(string& digits, vector<int>& tab) {
        string r;
        for (int i=0;i<tab.size();i++) {
            r.append(1, letters[digits[i]-'0'][tab[i]]);
        }
        return r;
    }
    bool inc(string& digits, vector<int>& tab) {
        for (int i=0;i<tab.size();i++) {
            tab[i]++;
            if (tab[i]<nums[digits[i]-'0']) return false;
            tab[i]=0;
        }
        return true;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size()==0) return res;
        vector<int> tab(digits.size(), 0);
        while (true) {
            res.push_back(gen(digits, tab));
            if(inc(digits, tab)) break;
        }
        return res;
    }
};
