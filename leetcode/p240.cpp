class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=matrix.size()-1, j=0;
        while (i>=0 && j<matrix[0].size()) {
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) i--;
            else if (target > matrix[i][j]) j++;
        }
        return false;
    }
};
