class Solution {
public:
    int minDistance(string word1, string word2) {
        word1.insert(0, 1, '-');
        word2.insert(0, 1, '-');
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> table(n1, vector<int>(n2));
        for (int i=0;i<n2;i++) {
            table[0][i] = i;
        }
        for (int i=1;i<n1;i++) {
            table[i][0] = i;
        }
        for (int i=1;i<n1;i++) {
            for (int j=1;j<n2;j++) {
                int m = table[i-1][j-1] + (word1[i]==word2[j]?0:2);
                //cout << table[i-1][j-1] << " " << m << word1[i] << word2[j]<< endl;
                m = min(m, table[i-1][j]+1);
                m = min(m, table[i][j-1]+1);
                table[i][j] = m;
            }
        }
        /*
        for (int i=0;i<n1;i++) {
            for (int j=0;j<n2;j++) cout << table[i][j] << " ";
            cout << endl;
        }
        */
        return table[n1-1][n2-1];
    }
};
