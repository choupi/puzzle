class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        seq = [[] for i in range(len(matrix)+len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                ij = i+j
                seq[ij].append(matrix[i][j])
        #print(seq)
        out = []
        for i in range(len(seq)):
            if i % 2 == 0:
                seq[i].reverse()
            out+=seq[i]
        #print(out)
        return out
                
