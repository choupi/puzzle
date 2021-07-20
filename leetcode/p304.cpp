class NumMatrix {
public:
    vector<vector<long long>> table;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        table.resize(m, vector<long long>(n));
        table[0][0] = matrix[0][0];
        for (int i=1;i<m;i++) {
            table[i][0] = table[i-1][0] + matrix[i][0];
        }
        for (int j=1;j<n;j++) {
            table[0][j] = table[0][j-1] + matrix[0][j];
        }
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                table[i][j] = table[i-1][j] + table[i][j-1] - table[i-1][j-1] + matrix[i][j];
            }
        }
        /*
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) cout << table[i][j] << " ";
            cout << endl;
        }
        */
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long u = row1>0?table[row1-1][col2]:0;
        long long l = col1>0?table[row2][col1-1]:0;
        long long lu = row1>0&&col1>0?table[row1-1][col1-1]:0;
        //cout << u << " " << l << " " << lu << " " << table[row2][col2] << endl;
        return table[row2][col2] - l - u + lu;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
