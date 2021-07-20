class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_counter;
        unordered_map<char, int> t_counter;
        for (int i=0;i<s.size();i++) {
            if (s_counter.find(s[i]) == s_counter.end()) {
                s_counter[s[i]] = 1;
            } else {
                s_counter[s[i]] += 1;
            }
        }
        for (int i=0;i<t.size();i++) {
            if (t_counter.find(t[i]) == t_counter.end()) {
                t_counter[t[i]] = 1;
            } else {
                t_counter[t[i]] += 1;
            }
        }
        if (s_counter.size() != t_counter.size()) {
            return false;
        }
        for (auto kv: s_counter) {
            if (kv.second != t_counter[kv.first]) {
                return false;
            }
        }
        return true;
    }
};
