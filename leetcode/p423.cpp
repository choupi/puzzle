class Solution {
public:
    vector<pair<string, int>> nums{{"zero",0}, {"wto",2}, {"ufor",4}, {"xsi",6}, {"geiht", 8}, {"htree",3}, {"five",5}, {"seven",7}, {"one",1}, {"inne",9}};
    vector<int> counter;
    vector<int> digits;
    int get(char c) {
        return counter[(int)c-'a'];
    }
    int inc(char c) {
        return ++counter[(int)c-'a'];
    }
    int sub(char c, int i) {
        counter[(int)c-'a'] -= i;
        return counter[(int)c-'a'];
    }
    string originalDigits(string s) {
        counter.resize(26, 0);
        digits.resize(10, 0);
        for (char c: s) {
            inc(c);
        }
        for (int i=0;i<digits.size();i++) {
            string n = nums[i].first;
            if (get(n[0])==0) continue;
            int cnt = get(n[0]);
            for (char c: n) {
                sub(c, cnt);
            }
            digits[nums[i].second] += cnt;
        }
        string res;
        for (int i=0;i<digits.size();i++) {
            res.append(digits[i], '0'+i);
        }
        return res;
    }
};
