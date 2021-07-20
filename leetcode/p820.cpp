class Solution {
public:
    static bool compare(string &s1,string &s2) {
        return s1.size() < s2.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int total = 0;
        for (int i=0;i<words.size();i++) {
            //cout << words[i] << endl;
            bool flag = true;
            for (int j=i+1;j<words.size();j++) {
                if (words[j].rfind(words[i]) == words[j].size()-words[i].size()) {
                    //cout << words[j].find(words[i]) << endl;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                total += words[i].size()+1;
            }
            //cout << total << endl;
        }
        return total;
    }
};
