class Solution {
public:
    int find(vector<int>& table, int i) {
        int j = i;
        while (j-1>=0 && table[j-1]!=j-1) {
            j = table[j-1];
        }
        return j;
    }
    int longestValidParentheses(string s) {
        if (s.size()==0) return 0;
        vector<int> table(s.size());
        table[0] = 0;
        for (int i=1;i<s.size();i++) {
            table[i] = i;
            if (s[i]=='(') {
                continue;
            }
            // s[i]==')'
            if (s[i-1]=='(') {
                int j = find(table, i-1);
                table[i] = j;
                //cout << i << ">" << j << endl;
            } else if (table[i-1]!=i-1) {
                int j=find(table, i);
                //cout << i << ">>" << j << endl;
                if (j-1>=0 && s[j-1]=='(') {
                    j = find(table, j-1);
                    table[i] = j;
                } else {
                    table[i] = i;
                }
            }
        }
        int m=0;
        for (int i=0;i<s.size();i++) {
            //cout << table[i] << endl;
            int l = i==table[i]?0:i-table[i]+1;
            if (l>m) m=l;
        }
        return m;
    }
};
