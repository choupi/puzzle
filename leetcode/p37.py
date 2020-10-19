# 37. Sudoku Solver
# https://leetcode.com/problems/sudoku-solver/

class Solution(object):
    def get_box(self, i, j):
        c=j/3
        r=i/3
        return c*3+r
    
    def row_iter(self, board, r):
        import itertools
        for p in itertools.permutations(list(self.row_set[r])):
            empty_list=[]
            idx=0
            flag=True
            for j in range(9):
                if board[r][j]=='.':
                    if p[idx] in self.col_set[j] or p[idx] in self.box_set[self.get_box(r, j)]:
                        flag=False
                        break
                    board[r][j]=p[idx]
                    self.col_set[j].add(p[idx])
                    self.box_set[self.get_box(r, j)].add(p[idx])
                    empty_list.append(j)
                    idx+=1
            if flag:
                if r==8: return True
                flag=self.row_iter(board, r+1)
                if flag: return True
            for j in empty_list:
                self.col_set[j].remove(board[r][j])
                self.box_set[self.get_box(r,j)].remove(board[r][j])
                board[r][j]='.'
        return False
                    
    def cell_iter(self, board, idx):
        if idx==len(self.empty_list): return True
        i, j, d = self.empty_list[idx]
        b=self.get_box(i, j)
        for c in d:
            if c in self.box_set[b]: continue
            if c in self.col_set[j]: continue
            if c in self.row_set[i]: continue
            self.box_set[b].add(c)
            self.col_set[j].add(c)
            self.row_set[i].add(c)
            board[i][j]=c
            flag=self.cell_iter(board, idx+1)
            if flag: return True
            self.box_set[b].remove(c)
            self.col_set[j].remove(c)
            self.row_set[i].remove(c)
            board[i][j]='.'
            
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.row_set=[set() for i in range(9)]
        self.col_set=[set() for i in range(9)]
        self.box_set=[set() for i in range(9)]
        self.empty_list=[]
        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':
                    self.empty_list.append((i, j, []))
                    continue
                self.col_set[j].add(board[i][j])
                self.row_set[i].add(board[i][j])
                self.box_set[self.get_box(i, j)].add(board[i][j])
        for i, j, d in self.empty_list:
            b=self.get_box(i,j)
            for c in '123456789':
                if c in self.box_set[b]: continue
                if c in self.col_set[j]: continue
                if c in self.row_set[i]: continue
                d.append(c)
        #flag=self.row_iter(board, 0)
        flag=self.cell_iter(board, 0)
        return board
