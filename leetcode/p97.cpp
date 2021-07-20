class Solution {
public:
    vector<vector<bool>> table;
    string S1;
    string S2;
    string S3;
    void check(int i, int j) {
        if (i>0 && table[i-1][j] && S1[i-1] == S3[i+j-1]) table[i][j] = true;
        else if (j>0 && table[i][j-1] && S2[j-1] == S3[i+j-1]) table[i][j] = true;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        S1 = s1;
        S2 = s2;
        S3 = s3;
        table.resize(s1.size()+1, vector<bool>(s2.size()+1, false));
        table[0][0] = true;
        for (int i=1;i<s1.size()+1;i++) check(i, 0);
        for (int j=1;j<s2.size()+1;j++) check(0, j);
        for (int i=1;i<s1.size()+1;i++) {
            for (int j=1;j<s2.size()+1;j++) {
                check(i, j);
                //cout << table[i][j] << endl;
            }
        }
        return table[s1.size()][s2.size()];
    }
};
