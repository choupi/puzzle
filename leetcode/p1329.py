class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        diag_i = [sorted([mat[i+j][j] for j in range(min(len(mat[0]), len(mat)-i))]) for i in range(len(mat))]
        diag_j = [sorted([mat[i][i+j] for i in range(min(len(mat[0])-j, len(mat)))]) for j in range(len(mat[0]))]
        res = [[0]*len(mat[0]) for i in range(len(mat))]
        for i in range(len(mat)):
            for j in range(min(len(mat[0]), len(mat)-i)):
                res[i+j][j] = diag_i[i][j]
        for j in range(len(mat[0])):
            for i in range(min(len(mat[0])-j, len(mat))):
                res[i][i+j] = diag_j[j][i]
        return res
