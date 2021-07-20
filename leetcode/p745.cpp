class WordFilter {
public:
    unordered_map<string, int> wmap;
    WordFilter(vector<string>& words) {
        for (int i=0;i<words.size();i++) {
            for (int j=1;j<=words[i].size();j++) {
                for (int k=1;k<=words[i].size();k++) {
                    string s = words[i].substr(0, j) + "#" + words[i].substr(words[i].size()-k, k);
                    //cout << j << k << s << endl;
                    wmap[s]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix+"#"+suffix;
        //cout << s << endl;
        auto it = wmap.find(s);
        if (it==wmap.end()) return -1;
        return (*it).second;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
