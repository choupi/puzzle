class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        nr = len(board)
        nc = len(board[0])
        pts = set()
        for i in range(nr):
            for j in range(nc):
                if board[i][j] == 1:
                    pts.add((i, j))
        #print(pts)
        ns = Counter([(x+a, y+b) for x, y in pts for a in range(-1, 2) for b in range(-1, 2)])
        #print(ns)
        for i in range(nr):
            for j in range(nc):
                #print(i, j, board[i][j], ns[(i, j)])
                if board[i][j] == 1:
                    if (ns[(i, j)] <3 or ns[(i, j)] > 4):
                        #print('set 0')
                        board[i][j] = 0
                else:
                    if ns[(i, j)] == 3:
                        #print('set 1')
                        board[i][j] = 1
        print(board)
