class Solution {
public:
    int max_len;
    int min_len;
    vector<vector<int>> dag;
    vector<int> table;
    void gen_dag(vector<string>& words) {
        unordered_map<string, int> st;
        for (int i=0;i<words.size();i++) {
            st[words[i]]=i;
        }
        dag.resize(words.size(), vector<int>());
        max_len = 0;
        min_len = INT_MAX;
        for (int i=0;i<words.size();i++) {
            if (words[i].size()>max_len) max_len = words[i].size();
            if (words[i].size()<min_len) min_len = words[i].size();
            if (words[i].size()<2) continue;
            //cout << "@" << words[i] << endl;
            for (int l=0;l<words[i].size();l++) {
                string s = words[i].substr(0, l) + words[i].substr(l+1);
                //cout << s << endl;
                auto it = st.find(s);
                if (it!=st.end()) {
                    dag[i].push_back((*it).second);
                }
            }
        }
    }
    void run() {
        table.resize(dag.size(), 1);
        //cout << max_len << endl;
        for (int j=0;j<max_len-min_len+1;j++) {
            for (int i=0;i<dag.size();i++) {
                int m = 0;
                for (auto d: dag[i]) {
                    //cout << i << "->" << d << endl;
                    if (table[d]>m) m = table[d];
                }
                table[i] = m+1;
                //cout << i << " " << table[i] << endl;
            }
        }
    }
    int longestStrChain(vector<string>& words) {
        gen_dag(words);
        run();
        int m = 0;
        for (int i=0;i<table.size();i++) {
            if (table[i]>m) m = table[i];
        }
        return m;
    }
};
